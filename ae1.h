/*********************************************************/
/*  ae1.h                                                */
/*                                                       */
/*  �K�w�^�j���[���l�b�g�v���O����                       */
/*                                                       */
/*  ��ݍ��݃j���[�����l�b�g(CNN)�̊�{�\��(���q)        */
/*                                                       */
/*********************************************************/
#ifndef _AE1_H_
#define _AE1_H_

#include "lcommon.h"
#include "lrndata.h"
#include "wdata.h"

/*  forward�֐�                               */
double forward(int o_cnt, int r_cnt, Input *in, Whdata *whdata, Wodata *wodata, Hd_output *hdo, Output *o);

/*  �V�O���C�h�֐�                            */
// double f(double u);

/*  olearn�֐�                                */
void olearn(int o_cnt, int r_cnt, Input *in, Wodata *wodata, Hd_output *hdo, Output *o);

/*  hlearn�֐�                                */
void hlearn(int o_cnt, int r_cnt, Input *in, Whdata *whdata, Wodata *wodata, Hd_output *hdo, Output *o);


#endif

