/*********************************************************/
/*  ae1.c                                                */
/*                                                       */
/*  階層型ニューロネットプログラム                       */
/*                                                       */
/*  畳み込みニューラルネット(CNN)の基本構造(骨子)        */
/*                                                       */
/*********************************************************/
#include "ae1.h"
#include <math.h>

double f(double u);

/*********************************************************/
/*  forward関数                                          */
/*********************************************************/
double forward(int o_cnt, int r_cnt, Input *in, Whdata *whdata, Wodata *wodata, Hd_output *hdo, Output *o){
	
	double u = 0;
	int i=0, j=0;
	
	for(i=0; i < HD_NUM; ++i){
		for(j=0; j < POOLOUTSIZE * POOLOUTSIZE * FILTERNO + 1; ++j){
			u += in->input[j] * whdata->wh[i][j];
			// printf("forward():wh in j = %d\n", j);
		}
		// printf("forward():wh out j = %d\n", j);
		u -= whdata->wh[i][j];
		hdo->hi[i] = f(u);
		u=0;
	}
	
	for(i=0; i < HD_NUM; ++i){
		u += hdo->hi[i] * wodata->wo[o_cnt][i];
		// printf("forward():wo in i = %d\n", i);
	}
	// printf("forward():wo out i = %d\n", i);
	u -= wodata->wo[o_cnt][i];
	o->output[o_cnt] = f(u);
	
	return o->output[o_cnt];
}


/*********************************************************/
/*  forward関数                                          */
/*********************************************************/
double f(double u){
	// if(u >= 0) return 1.0;
	// else return 0.0;
	
	// シグモイド関数
	return 1.0 / (1.0 + exp(-u));
}


/*********************************************************/
/*  olearn関数: 出力層の重みとしきい値学習               */
/*********************************************************/
void olearn(int o_cnt, int r_cnt, Input *in, Wodata *wodata, Hd_output *hdo, Output *o){
	
	int i=0;
	double d;  /* 重み計算に利用 */
	
	d = (in->input[POOLOUTSIZE * POOLOUTSIZE * FILTERNO] - o->output[o_cnt]) * o->output[o_cnt] * (1 - o->output[o_cnt]);  /* 誤差計算 */
	for(i=0; i < HD_NUM; ++i){
		wodata->wo[o_cnt][i] += ALPHA * hdo->hi[i] * d;  /* 重みの学習 */
	}
	wodata->wo[o_cnt][i] += ALPHA * (-1.0) * d;     /* しきい値の学習 */
	
}


/*********************************************************/
/*  hlearn関数: 中間層の重みとしきい値学習               */
/*********************************************************/
void hlearn(int o_cnt, int r_cnt, Input *in, Whdata *whdata, Wodata *wodata, Hd_output *hdo, Output *o){
	
	int i=0, j=0;
	double d;
	double dj;  /* 中間層の重み計算に利用 */
	
	for(j=0; j < HD_NUM; ++j){
		d = (in->input[POOLOUTSIZE * POOLOUTSIZE * FILTERNO] - o->output[o_cnt]) * o->output[o_cnt] * (1 - o->output[o_cnt]);  /* 誤差計算 */
		dj = wodata->wo[o_cnt][j] * d * hdo->hi[j] * (1 - hdo->hi[j]);    /* 誤差計算 */
		for(i=0; i < POOLOUTSIZE * POOLOUTSIZE * FILTERNO; ++i){
			whdata->wh[j][i] += ALPHA * in->input[i] * dj;
		}
		whdata->wh[j][i] += ALPHA * (-1.0) * dj;
	}
	
}



