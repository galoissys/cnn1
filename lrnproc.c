/*********************************************************/
/*  lrnproc.c                                            */
/*                                                       */
/*  階層型ニューロネットプログラム                       */
/*  学習機                                               */
/*  畳み込みニューラルネット(CNN)の基本構造(骨子)        */
/*                                                       */
/*********************************************************/
#include "lrnproc.h"

int lrnproc(){
	
	/* 構造体のメモリ確保 */
	
	// 学習データ構造体
	int n=0;
	int r_cnt =0;  //  データ件数
	
	Lrndata *plrndata[INPUT_MAX];
	for(n=0; n < INPUT_MAX; ++n){
		plrndata[n] = (Lrndata *)malloc(sizeof(Lrndata));
	}
	
	// ニューロンの中間層及び出力層の重み構造体
	
	Whdata *pwhdata;
	Wodata *pwodata;
	pwhdata = (Whdata *)malloc(sizeof(Whdata));
	pwodata = (Wodata *)malloc(sizeof(Wodata));
	
	// 出力構造体
	Hd_output *phdo;
	Output *po;
	phdo = (Hd_output *)malloc(sizeof(Hd_output));
	po = (Output *)malloc(sizeof(Output));
	
	//  Filter構造体
	Filter *pflt;
	pflt = (Filter *)malloc(sizeof(Filter));
	
	// 全結合層への入力データ
	Input *pin;
	pin = (Input *)malloc(sizeof(Input));
	
	//  畳み込み出力
	Convout *pconv;
	pconv = (Convout *)malloc(sizeof(Convout));
	
	//  プーリング出力
	Poolout *ppool;
	ppool = (Poolout *)malloc(sizeof(Poolout));
	
	/* 構造体のメモリ確保完了 */
	
	
	// 学習データをセット
	r_cnt = setldata(plrndata);
	
	// データ件数を超えて確保したメモリを解放
	for(n=r_cnt; n < INPUT_MAX; ++n){
		free(plrndata[n]);
	}
	
	//  セットデータ確認
	getldata(r_cnt, plrndata);
	
	
	// 重みとしきい値の初期化
	init_wh(pwhdata);
	init_wo(pwodata);
	// debug_info
	get_wh(pwhdata);
	get_wo(pwodata);
	
	
	// Filterの初期化
	init_filter(pflt);
	get_filter(pflt);
	
	
	// sleep(5);
	
	
	double err = 100;   // 誤差の初期値
	double err1 = 100;  // 誤差１の初期値
	int count = 0;
	
	int i=0, j=0, k=0, a=0, b=0;
	
	/* 学習 */
	
	while(err1 > LIMIT1){
		err1 = 0.0;
		for(k=0; k < OUT_NUM; ++k){
			err = 0.0;
			for(i=0; i < r_cnt; ++i){  /*  学習データごとの繰り返し      */
				for(j=0; j < FILTERNO; ++j){   /*  フィルタごとの繰り返し      */
					//  畳み込みの計算
					conv(j, pflt, plrndata[i], pconv);
					//  プーリングの計算
					pool(pconv, ppool);
					//  プーリング出力を全結合層の入力へコピー
					for(a=0; a < POOLOUTSIZE; ++a){
						for(b=0; b < POOLSIZE; ++b){
							pin->input[j * POOLOUTSIZE * POOLOUTSIZE + POOLOUTSIZE * a + b] = ppool->poolout[a][b];
							pin->input[POOLOUTSIZE * POOLOUTSIZE * FILTERNO] = plrndata[i]->t;   //  教師データ
						}
					}
				}
				// 順方向の計算 
				forward(k, i, pin, pwhdata, pwodata, phdo, po);
				
				// 出力層重み調整
				olearn(k, i, pin, pwodata, phdo, po);
				
				// 中間層重み調整
				hlearn(k, i, pin, pwhdata, pwodata, phdo, po);
				
				// 誤差の積算
				// tは教師データ。乗算することで値を＋とし積算する。
				err += (po->output[k] - plrndata[i]->t) * (po->output[k] - plrndata[i]->t);
			}
			printf("count = %d\t k = %d\t err = %lf\n", count, k, err);
			err1 += err;
		}
		printf("count = %d\t err1 = %lf\n", count, err1);
		++count;
		// fprintf(stderr, "%d\t err1 = %lf\n", count, err1);
	}
	/* 学習終了 */
	
	
	// ニューロン中間層及び出力層の重みとしきい値の最終結果確認
	get_wh(pwhdata);
	get_wo(pwodata);
	
	
	// 学習データに対する出力
	printf("*** Network output ***\n");
	printf("Num\t tercher\t output\t \n");
	for(i=0; i < r_cnt; ++i){
		printf("Num = %d\t ", i);
		for(j=0; j < FILTERNO; ++j){  //  フィルタごとの繰り返し
			// 畳み込みの計算
			conv(j, pflt, plrndata[i], pconv);
			// プーリングの計算
			pool(pconv, ppool);
			//  プーリング出力を全結合層の入力へコピー
			for(a=0; a < POOLOUTSIZE; ++a){
				for(b=0; b < POOLSIZE; ++b){
					pin->input[j * POOLOUTSIZE * POOLOUTSIZE + POOLOUTSIZE * a + b] = ppool->poolout[a][b];
					pin->input[POOLOUTSIZE * POOLOUTSIZE * FILTERNO] = plrndata[i]->t;   //  教師データ
				}
			}
		}
		printf("%d\t\t", plrndata[i]->t);
		for(j=0; j< OUT_NUM; ++j){
			// 学習後の結果出力
			printf("%lf\t ", forward(j, i, pin, pwhdata, pwodata, phdo, po) );
		}
		printf("\n");
	}
	
	
	// メモリ解放
	for(n=0; n < r_cnt; ++n){
		free(plrndata[n]);
	}
	free(pwhdata);
	free(pwodata);
	free(phdo);
	free(po);
	free(pflt);
	free(pin);
	
	return 0;
	
}


