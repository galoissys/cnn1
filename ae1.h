/*********************************************************/
/*  ae1.h                                                */
/*                                                       */
/*  階層型ニューロネットプログラム                       */
/*                                                       */
/*  畳み込みニューラルネット(CNN)の基本構造(骨子)        */
/*                                                       */
/*********************************************************/
#ifndef _AE1_H_
#define _AE1_H_

#include "lcommon.h"
#include "lrndata.h"
#include "wdata.h"

/*  forward関数                               */
double forward(int o_cnt, int r_cnt, Input *in, Whdata *whdata, Wodata *wodata, Hd_output *hdo, Output *o);

/*  シグモイド関数                            */
// double f(double u);

/*  olearn関数                                */
void olearn(int o_cnt, int r_cnt, Input *in, Wodata *wodata, Hd_output *hdo, Output *o);

/*  hlearn関数                                */
void hlearn(int o_cnt, int r_cnt, Input *in, Whdata *whdata, Wodata *wodata, Hd_output *hdo, Output *o);


#endif

