/*********************************************************/
/*  wdata.h                                              */
/*                                                       */
/*  階層型ニューロネットプログラム                       */
/*  ニューロン 重みとしきい値データ                      */
/*                                                       */
/*********************************************************/
#ifndef _WDATA_H_
#define _WDATA_H_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "lcommon.h"

/*  中間層ニューロン 重みとしきい値 データ構造           */
typedef struct{
	double wh[HD_NUM][POOLOUTSIZE * POOLOUTSIZE * FILTERNO + 1];
} Whdata;

// 中間層の出力格納
typedef struct{
	double hi[HD_NUM];
} Hd_output;


/*  中間層ニューロン 関数                                */
void init_wh(Whdata *whdata);
void get_wh(Whdata *whdata);


/*  出力層ニューロン 重みとしきい値 データ構造           */

typedef struct{
	double wo[OUT_NUM][HD_NUM + 1];
} Wodata;

// 出力層の出力格納
typedef struct{
	double output[OUT_NUM];
} Output;


/*  出力層ニューロン 関数                                */
void init_wo(Wodata *wodata);
void get_wo(Wodata *wodata);


// 全結合層への入力データ
typedef struct{
	double input[POOLOUTSIZE * POOLOUTSIZE * FILTERNO + 1];
} Input;

#endif

