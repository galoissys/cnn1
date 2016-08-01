/*********************************************************/
/*  lrndata.h                                            */
/*                                                       */
/*  階層型ニューロネットプログラム                       */
/*  学習データセット                                     */
/*                                                       */
/*********************************************************/
#ifndef _LRNDATA_H_
#define _LRNDATA_H_

#include <stdio.h>
#include <string.h>
#include "lcommon.h"

/*  学習データセット データ構造                          */

typedef struct{
	double ldata[INPUT_MAX][INPUTSIZE][INPUTSIZE];  // 訓練データ
	int t[INPUT_MAX];                               // 教師データ
	int num_of_data;                                // データ件数
} Lrndatas;

typedef struct{
	double ldata[INPUTSIZE][INPUTSIZE];  // 訓練データ
	int t;                               // 教師データ
} Lrndata;

/*  学習データセット 関数                                */
void initldatas(Lrndatas *lrndata);
int setldatas(Lrndatas *lrndata);
void getldatas(Lrndatas *lrndata);

int setldata(Lrndata *lrndata[]);
void getldata(int count, Lrndata *lrndata[]);


#endif

