/*********************************************************/
/*  cvp1.c                                               */
/*                                                       */
/*  Deep Learning                                        */
/*  ��ݍ��݂ƃv�[�����O����                             */
/*                                                       */
/*********************************************************/
#include "cvp1.h"

/*********************************************************/
/*  ��ݍ��݂ƃv�[�����O���� �֐�                        */
/*********************************************************/

/*********************************************************/
/*  init_filter�֐�: �t�B���^�[�̏�����                  */
/*********************************************************/
void init_filter(Filter *flt){
	
	int i=0, j=0, k=0;
	
	srand((unsigned)time(NULL));    /* time�֐���p���������������̒�Ԏ� */
	
	for(i=0; i < FILTERNO; ++i){
		for(j=0; j < FILTERSIZE; ++j){
			for(k=0; k < FILTERSIZE; ++k){
				flt->filter[i][j][k] = drnd();
			}
		}
	}
	
	
	/*  �c�t�B���^�[   */
	/*
	flt->filter[0][0] = 0;
	flt->filter[0][1] = 1;
	flt->filter[0][2] = 0;
	flt->filter[1][0] = 0;
	flt->filter[1][1] = 1;
	flt->filter[1][2] = 0;
	flt->filter[2][0] = 0;
	flt->filter[2][1] = 1;
	flt->filter[2][2] = 0;
	*/
	
	/*  ���t�B���^�[   */
	/*
	flt->filter[0][0] = 0;
	flt->filter[0][1] = 0;
	flt->filter[0][2] = 0;
	flt->filter[1][0] = 1;
	flt->filter[1][1] = 1;
	flt->filter[1][2] = 1;
	flt->filter[2][0] = 0;
	flt->filter[2][1] = 0;
	flt->filter[2][2] = 0;
	*/
	
}


/*********************************************************/
/*  get_filter�֐�: �t�B���^�[�o��                       */
/*********************************************************/
void get_filter(Filter *flt){
	
	int i=0, j=0, k=0;
	
	for(i=0; i < FILTERNO; ++i){
		printf("*** Filter:%d ( %d x %d ) ***\n", i, FILTERSIZE, FILTERSIZE);
		for(j=0; j < FILTERSIZE; ++j){
			for(k=0; k < FILTERSIZE; ++k){
				printf("%lf\t", flt->filter[i][j][k]);
			}
			printf("\n");
		}
	}
	
}


/*********************************************************/
/*  conv�֐�: ��ݍ��݂̌v�Z                             */
/*********************************************************/
void conv(int fltno, Filter *flt, Lrndata *lrndata, Convout *cvout){
	
	int i=0, j=0;
	int startpoint = FILTERSIZE / 2;    //  ��ݍ��ݔ͈͂̉���
	
	// debug_info
	// printf("startpoint = %d\n", startpoint);
	
	for(i = startpoint; i < INPUTSIZE - startpoint; ++i){
		for(j = startpoint; j < INPUTSIZE - startpoint; ++j){
			cvout->convout[i][j] = calcconv(flt, lrndata, i, j, fltno);
		}
	}
	
}


/*********************************************************/
/*  calcconv�֐�: �t�B���^�̓K�p                         */
/*********************************************************/
double calcconv(Filter *flt, Lrndata *lrndata, int i, int j, int fltno){
	
	int m=0, n=0;
	double sum = 0;
	
	for(m=0; m < FILTERSIZE; ++m){
		for(n=0; n < FILTERSIZE; ++n){
			sum += lrndata->ldata[i - FILTERSIZE / 2 + m][j - FILTERSIZE / 2 + n] * flt->filter[fltno][m][n];
		}
	}
	
	return sum;
}


/*********************************************************/
/*  get_convout�֐�: ��ݍ��ݏ������ʏo��                */
/*********************************************************/
void get_convout(Convout *cvout){
	
	int i=0, j=0;
	
	printf("*** Convout ( %d x %d ) ***\n", INPUTSIZE - 2, INPUTSIZE - 2);
	for(i = 1; i < INPUTSIZE - 1; ++i){
		for(j = 1; j < INPUTSIZE - 1; ++j){
			printf("%.3lf ", cvout->convout[i][j]);
		}
		printf("\n");
	}
	
}


/*********************************************************/
/*  pool�֐�: �v�[�����O�̌v�Z                           */
/*********************************************************/
void pool(Convout *cvout, Poolout *plout){
	
	int i=0, j=0;
	
	for(i=0; i < POOLOUTSIZE; ++i){
		for(j=0; j < POOLOUTSIZE; ++j){
			plout->poolout[i][j] = maxpooling(cvout, i, j);
		}
	}
}


/*********************************************************/
/*  maxpooling�֐�: �v�[�����O�̌v�Z                     */
/*********************************************************/
double maxpooling(Convout *cvout, int i, int j){
	
	int m=0, n=0;
	double max;
	int halfpool = POOLSIZE / 2;   //  �v�[�����O�̃T�C�Y��1/2
	
	max = cvout->convout[i * POOLOUTSIZE + 1 + halfpool][j * POOLOUTSIZE + 1 + halfpool];
	
	for(m = POOLOUTSIZE * i + 1; m <= POOLOUTSIZE * i + 1 + (POOLSIZE - halfpool); ++m){
		for(n = POOLOUTSIZE * j + 1; n <= POOLOUTSIZE * j + 1 + (POOLSIZE - halfpool); ++n){
			if(max < cvout->convout[m][n]) max = cvout->convout[m][n];
		}
	}
	
	return max;
}


/*********************************************************/
/*  get_poolout�֐�: �v�[�����O�������ʏo��              */
/*********************************************************/
void get_poolout(Poolout *plout){
	
	int i=0, j=0;
	
	printf("*** Poolout ( %d x %d ) ***\n", POOLOUTSIZE, POOLOUTSIZE);
	for(i=0; i < POOLOUTSIZE; ++i){
		for(j=0; j < POOLOUTSIZE; ++j){
			printf("%.3lf ", plout->poolout[i][j]);
		}
		printf("\n");
	}
	
}


