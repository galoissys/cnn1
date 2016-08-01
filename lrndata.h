/*********************************************************/
/*  lrndata.h                                            */
/*                                                       */
/*  �K�w�^�j���[���l�b�g�v���O����                       */
/*  �w�K�f�[�^�Z�b�g                                     */
/*                                                       */
/*********************************************************/
#ifndef _LRNDATA_H_
#define _LRNDATA_H_

#include <stdio.h>
#include <string.h>
#include "lcommon.h"

/*  �w�K�f�[�^�Z�b�g �f�[�^�\��                          */

typedef struct{
	double ldata[INPUT_MAX][INPUTSIZE][INPUTSIZE];  // �P���f�[�^
	int t[INPUT_MAX];                               // ���t�f�[�^
	int num_of_data;                                // �f�[�^����
} Lrndatas;

typedef struct{
	double ldata[INPUTSIZE][INPUTSIZE];  // �P���f�[�^
	int t;                               // ���t�f�[�^
} Lrndata;

/*  �w�K�f�[�^�Z�b�g �֐�                                */
void initldatas(Lrndatas *lrndata);
int setldatas(Lrndatas *lrndata);
void getldatas(Lrndatas *lrndata);

int setldata(Lrndata *lrndata[]);
void getldata(int count, Lrndata *lrndata[]);


#endif

