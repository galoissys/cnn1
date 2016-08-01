/*********************************************************/
/*  cvp1.h                                               */
/*                                                       */
/*  Deep Learning                                        */
/*  ��ݍ��݂ƃv�[�����O����                             */
/*                                                       */
/*********************************************************/
#ifndef _CVP1_H_
#define _CVP1_H_

#include "lcommon.h"
#include "lrndata.h"

/*********************************************************/
/*  ��ݍ��݂ƃv�[�����O���� �f�[�^�\��                  */
/*********************************************************/
typedef struct{
	double filter[FILTERNO][FILTERSIZE][FILTERSIZE];  // �t�B���^�[
} Filter;


typedef struct{
	double convout[INPUTSIZE][INPUTSIZE];  // ��ݍ��ݏo��
} Convout;


typedef struct{
	double poolout[POOLOUTSIZE][POOLOUTSIZE];  // �v�[�����O�o��
} Poolout;


/*********************************************************/
/*  ��ݍ��݂ƃv�[�����O���� �֐�                        */
/*********************************************************/
/*  init_filter�֐�: �t�B���^�[�̏�����                  */
void init_filter(Filter *flt);

/*  get_filter�֐�: �t�B���^�[�o��                       */
void get_filter(Filter *flt);

/*  conv�֐�: ��ݍ��݂̌v�Z                             */
void conv(int fltno, Filter *flt, Lrndata *lrndata, Convout *cvout);

/*  calcconv�֐�: �t�B���^�̓K�p                         */
double calcconv(Filter *flt, Lrndata *lrndata, int i, int j, int fltno);

/*  get_convout�֐�: ��ݍ��ݏ������ʏo��                */
void get_convout(Convout *cvout);

/*  pool�֐�: �v�[�����O�̌v�Z                           */
void pool(Convout *cvout, Poolout *plout);

/*  maxpooling�֐�: �v�[�����O�̌v�Z                     */
double maxpooling(Convout *cvout, int i, int j);

/*  get_poolout�֐�: �v�[�����O�������ʏo��              */
void get_poolout(Poolout *plout);

#endif

