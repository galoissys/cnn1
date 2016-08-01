/*********************************************************/
/*  lcommon.h                                            */
/*                                                       */
/*  階層型ニューロネットプログラム                       */
/*  Deep Learning                                        */
/*                                                       */
/*                                                       */
/*********************************************************/
#ifndef _LCOMMON_H_
#define _LCOMMON_H_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "rnd.h"

#define IN_NUM 9      /* 入力層セル数 */
#define HD_NUM 3      /* 中間層セル数 */
#define OUT_NUM 1     /* 出力層人口ニューロン数 */

#define INPUT_MAX 10       /* トレーニングデータ件数 */

#define ALPHA 10      /* 学習係数 */

#define LIMIT 0.001   /* 誤差上限値 */
#define LIMIT1 0.001   /* 誤差上限値１ */


/*  畳み込みとプーリング処理関連  */
#define INPUTSIZE 11   /*  入力数   */
#define FILTERSIZE 3   /*  フィルタの大きさ   */
#define FILTERNO 2     /*  フィルタの個数   */
#define POOLSIZE 3     /*  プーリングサイズ   */
#define POOLOUTSIZE 3  /*  プーリングの出力サイズ   */


#endif

