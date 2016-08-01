/*********************************************************/
/*  ae1.c                                                */
/*                                                       */
/*  �K�w�^�j���[���l�b�g�v���O����                       */
/*                                                       */
/*  ��ݍ��݃j���[�����l�b�g(CNN)�̊�{�\��(���q)        */
/*                                                       */
/*********************************************************/
#include "ae1.h"
#include <math.h>

double f(double u);

/*********************************************************/
/*  forward�֐�                                          */
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
/*  forward�֐�                                          */
/*********************************************************/
double f(double u){
	// if(u >= 0) return 1.0;
	// else return 0.0;
	
	// �V�O���C�h�֐�
	return 1.0 / (1.0 + exp(-u));
}


/*********************************************************/
/*  olearn�֐�: �o�͑w�̏d�݂Ƃ������l�w�K               */
/*********************************************************/
void olearn(int o_cnt, int r_cnt, Input *in, Wodata *wodata, Hd_output *hdo, Output *o){
	
	int i=0;
	double d;  /* �d�݌v�Z�ɗ��p */
	
	d = (in->input[POOLOUTSIZE * POOLOUTSIZE * FILTERNO] - o->output[o_cnt]) * o->output[o_cnt] * (1 - o->output[o_cnt]);  /* �덷�v�Z */
	for(i=0; i < HD_NUM; ++i){
		wodata->wo[o_cnt][i] += ALPHA * hdo->hi[i] * d;  /* �d�݂̊w�K */
	}
	wodata->wo[o_cnt][i] += ALPHA * (-1.0) * d;     /* �������l�̊w�K */
	
}


/*********************************************************/
/*  hlearn�֐�: ���ԑw�̏d�݂Ƃ������l�w�K               */
/*********************************************************/
void hlearn(int o_cnt, int r_cnt, Input *in, Whdata *whdata, Wodata *wodata, Hd_output *hdo, Output *o){
	
	int i=0, j=0;
	double d;
	double dj;  /* ���ԑw�̏d�݌v�Z�ɗ��p */
	
	for(j=0; j < HD_NUM; ++j){
		d = (in->input[POOLOUTSIZE * POOLOUTSIZE * FILTERNO] - o->output[o_cnt]) * o->output[o_cnt] * (1 - o->output[o_cnt]);  /* �덷�v�Z */
		dj = wodata->wo[o_cnt][j] * d * hdo->hi[j] * (1 - hdo->hi[j]);    /* �덷�v�Z */
		for(i=0; i < POOLOUTSIZE * POOLOUTSIZE * FILTERNO; ++i){
			whdata->wh[j][i] += ALPHA * in->input[i] * dj;
		}
		whdata->wh[j][i] += ALPHA * (-1.0) * dj;
	}
	
}



