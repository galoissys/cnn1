/*********************************************************/
/*  wdata.c                                              */
/*                                                       */
/*                                                       */
/*********************************************************/
#include "wdata.h"

/*********************************************************/
/*  ���ԑw�j���[���� �֐�                                */
/*********************************************************/
/*  init_wh�֐�                                          */
/*********************************************************/
void init_wh(Whdata *whdata){
	
	int i, j;
	
	srand((unsigned)time(NULL));    /* time�֐���p���������������̒�Ԏ� */
	
	for(i=0; i < HD_NUM; ++i){
		for(j=0; j < POOLOUTSIZE * POOLOUTSIZE * FILTERNO + 1; ++j){
			whdata->wh[i][j] = drnd();
		}
	}
	
}

/*********************************************************/
/*  get_wh�֐�                                           */
/*********************************************************/
void get_wh(Whdata *whdata){
	
	int i=0, j=0;
	
	printf("*** Weight Data of Hidden Layer ***\n");
	
	for(i=0; i < HD_NUM; ++i){
		for(j=0; j < POOLOUTSIZE * POOLOUTSIZE * FILTERNO + 1; ++j){
			printf("wh[%d][%d] = %.3lf\n", i, j, whdata->wh[i][j]);
		}
	}
	
}


/*********************************************************/
/*  �o�͑w�j���[���� �֐�                                */
/*********************************************************/
/*  init_wo�֐�                                          */
/*********************************************************/
void init_wo(Wodata *wodata){
	
	int i=0, j=0;
	
	srand((unsigned)time(NULL));    /* time�֐���p���������������̒�Ԏ� */
	
	for(i=0; i < OUT_NUM; ++i){
		for(j=0; j < HD_NUM + 1; ++j){
			wodata->wo[i][j] = drnd();
		}
	}
	
}

/*********************************************************/
/*  get_wo�֐�                                           */
/*********************************************************/
void get_wo(Wodata *wodata){
	
	int i=0, j=0;
	
	printf("*** Weight Data of Output Layer ***\n");
	
	for(i=0; i < OUT_NUM; ++i){
		for(j=0; j < HD_NUM + 1; ++j){
			printf("wo[%d][%d] = %.3lf\n", i, j, wodata->wo[i][j]);
		}
	}
	
}

