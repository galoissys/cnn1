/*********************************************************/
/*  wdata.h                                              */
/*                                                       */
/*  �K�w�^�j���[���l�b�g�v���O����                       */
/*  �j���[���� �d�݂Ƃ������l�f�[�^                      */
/*                                                       */
/*********************************************************/
#ifndef _WDATA_H_
#define _WDATA_H_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "lcommon.h"

/*  ���ԑw�j���[���� �d�݂Ƃ������l �f�[�^�\��           */
typedef struct{
	double wh[HD_NUM][POOLOUTSIZE * POOLOUTSIZE * FILTERNO + 1];
} Whdata;

// ���ԑw�̏o�͊i�[
typedef struct{
	double hi[HD_NUM];
} Hd_output;


/*  ���ԑw�j���[���� �֐�                                */
void init_wh(Whdata *whdata);
void get_wh(Whdata *whdata);


/*  �o�͑w�j���[���� �d�݂Ƃ������l �f�[�^�\��           */

typedef struct{
	double wo[OUT_NUM][HD_NUM + 1];
} Wodata;

// �o�͑w�̏o�͊i�[
typedef struct{
	double output[OUT_NUM];
} Output;


/*  �o�͑w�j���[���� �֐�                                */
void init_wo(Wodata *wodata);
void get_wo(Wodata *wodata);


// �S�����w�ւ̓��̓f�[�^
typedef struct{
	double input[POOLOUTSIZE * POOLOUTSIZE * FILTERNO + 1];
} Input;

#endif

