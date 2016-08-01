/*********************************************************/
/*  cvp1.h                                               */
/*                                                       */
/*  Deep Learning                                        */
/*  畳み込みとプーリング処理                             */
/*                                                       */
/*********************************************************/
#ifndef _CVP1_H_
#define _CVP1_H_

#include "lcommon.h"
#include "lrndata.h"

/*********************************************************/
/*  畳み込みとプーリング処理 データ構造                  */
/*********************************************************/
typedef struct{
	double filter[FILTERNO][FILTERSIZE][FILTERSIZE];  // フィルター
} Filter;


typedef struct{
	double convout[INPUTSIZE][INPUTSIZE];  // 畳み込み出力
} Convout;


typedef struct{
	double poolout[POOLOUTSIZE][POOLOUTSIZE];  // プーリング出力
} Poolout;


/*********************************************************/
/*  畳み込みとプーリング処理 関数                        */
/*********************************************************/
/*  init_filter関数: フィルターの初期化                  */
void init_filter(Filter *flt);

/*  get_filter関数: フィルター出力                       */
void get_filter(Filter *flt);

/*  conv関数: 畳み込みの計算                             */
void conv(int fltno, Filter *flt, Lrndata *lrndata, Convout *cvout);

/*  calcconv関数: フィルタの適用                         */
double calcconv(Filter *flt, Lrndata *lrndata, int i, int j, int fltno);

/*  get_convout関数: 畳み込み処理結果出力                */
void get_convout(Convout *cvout);

/*  pool関数: プーリングの計算                           */
void pool(Convout *cvout, Poolout *plout);

/*  maxpooling関数: プーリングの計算                     */
double maxpooling(Convout *cvout, int i, int j);

/*  get_poolout関数: プーリング処理結果出力              */
void get_poolout(Poolout *plout);

#endif

