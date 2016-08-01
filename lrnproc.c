/*********************************************************/
/*  lrnproc.c                                            */
/*                                                       */
/*  �K�w�^�j���[���l�b�g�v���O����                       */
/*  �w�K�@                                               */
/*  ��ݍ��݃j���[�����l�b�g(CNN)�̊�{�\��(���q)        */
/*                                                       */
/*********************************************************/
#include "lrnproc.h"

int lrnproc(){
	
	/* �\���̂̃������m�� */
	
	// �w�K�f�[�^�\����
	int n=0;
	int r_cnt =0;  //  �f�[�^����
	
	Lrndata *plrndata[INPUT_MAX];
	for(n=0; n < INPUT_MAX; ++n){
		plrndata[n] = (Lrndata *)malloc(sizeof(Lrndata));
	}
	
	// �j���[�����̒��ԑw�y�яo�͑w�̏d�ݍ\����
	
	Whdata *pwhdata;
	Wodata *pwodata;
	pwhdata = (Whdata *)malloc(sizeof(Whdata));
	pwodata = (Wodata *)malloc(sizeof(Wodata));
	
	// �o�͍\����
	Hd_output *phdo;
	Output *po;
	phdo = (Hd_output *)malloc(sizeof(Hd_output));
	po = (Output *)malloc(sizeof(Output));
	
	//  Filter�\����
	Filter *pflt;
	pflt = (Filter *)malloc(sizeof(Filter));
	
	// �S�����w�ւ̓��̓f�[�^
	Input *pin;
	pin = (Input *)malloc(sizeof(Input));
	
	//  ��ݍ��ݏo��
	Convout *pconv;
	pconv = (Convout *)malloc(sizeof(Convout));
	
	//  �v�[�����O�o��
	Poolout *ppool;
	ppool = (Poolout *)malloc(sizeof(Poolout));
	
	/* �\���̂̃������m�ۊ��� */
	
	
	// �w�K�f�[�^���Z�b�g
	r_cnt = setldata(plrndata);
	
	// �f�[�^�����𒴂��Ċm�ۂ��������������
	for(n=r_cnt; n < INPUT_MAX; ++n){
		free(plrndata[n]);
	}
	
	//  �Z�b�g�f�[�^�m�F
	getldata(r_cnt, plrndata);
	
	
	// �d�݂Ƃ������l�̏�����
	init_wh(pwhdata);
	init_wo(pwodata);
	// debug_info
	get_wh(pwhdata);
	get_wo(pwodata);
	
	
	// Filter�̏�����
	init_filter(pflt);
	get_filter(pflt);
	
	
	// sleep(5);
	
	
	double err = 100;   // �덷�̏����l
	double err1 = 100;  // �덷�P�̏����l
	int count = 0;
	
	int i=0, j=0, k=0, a=0, b=0;
	
	/* �w�K */
	
	while(err1 > LIMIT1){
		err1 = 0.0;
		for(k=0; k < OUT_NUM; ++k){
			err = 0.0;
			for(i=0; i < r_cnt; ++i){  /*  �w�K�f�[�^���Ƃ̌J��Ԃ�      */
				for(j=0; j < FILTERNO; ++j){   /*  �t�B���^���Ƃ̌J��Ԃ�      */
					//  ��ݍ��݂̌v�Z
					conv(j, pflt, plrndata[i], pconv);
					//  �v�[�����O�̌v�Z
					pool(pconv, ppool);
					//  �v�[�����O�o�͂�S�����w�̓��͂փR�s�[
					for(a=0; a < POOLOUTSIZE; ++a){
						for(b=0; b < POOLSIZE; ++b){
							pin->input[j * POOLOUTSIZE * POOLOUTSIZE + POOLOUTSIZE * a + b] = ppool->poolout[a][b];
							pin->input[POOLOUTSIZE * POOLOUTSIZE * FILTERNO] = plrndata[i]->t;   //  ���t�f�[�^
						}
					}
				}
				// �������̌v�Z 
				forward(k, i, pin, pwhdata, pwodata, phdo, po);
				
				// �o�͑w�d�ݒ���
				olearn(k, i, pin, pwodata, phdo, po);
				
				// ���ԑw�d�ݒ���
				hlearn(k, i, pin, pwhdata, pwodata, phdo, po);
				
				// �덷�̐ώZ
				// t�͋��t�f�[�^�B��Z���邱�ƂŒl���{�Ƃ��ώZ����B
				err += (po->output[k] - plrndata[i]->t) * (po->output[k] - plrndata[i]->t);
			}
			printf("count = %d\t k = %d\t err = %lf\n", count, k, err);
			err1 += err;
		}
		printf("count = %d\t err1 = %lf\n", count, err1);
		++count;
		// fprintf(stderr, "%d\t err1 = %lf\n", count, err1);
	}
	/* �w�K�I�� */
	
	
	// �j���[�������ԑw�y�яo�͑w�̏d�݂Ƃ������l�̍ŏI���ʊm�F
	get_wh(pwhdata);
	get_wo(pwodata);
	
	
	// �w�K�f�[�^�ɑ΂���o��
	printf("*** Network output ***\n");
	printf("Num\t tercher\t output\t \n");
	for(i=0; i < r_cnt; ++i){
		printf("Num = %d\t ", i);
		for(j=0; j < FILTERNO; ++j){  //  �t�B���^���Ƃ̌J��Ԃ�
			// ��ݍ��݂̌v�Z
			conv(j, pflt, plrndata[i], pconv);
			// �v�[�����O�̌v�Z
			pool(pconv, ppool);
			//  �v�[�����O�o�͂�S�����w�̓��͂փR�s�[
			for(a=0; a < POOLOUTSIZE; ++a){
				for(b=0; b < POOLSIZE; ++b){
					pin->input[j * POOLOUTSIZE * POOLOUTSIZE + POOLOUTSIZE * a + b] = ppool->poolout[a][b];
					pin->input[POOLOUTSIZE * POOLOUTSIZE * FILTERNO] = plrndata[i]->t;   //  ���t�f�[�^
				}
			}
		}
		printf("%d\t\t", plrndata[i]->t);
		for(j=0; j< OUT_NUM; ++j){
			// �w�K��̌��ʏo��
			printf("%lf\t ", forward(j, i, pin, pwhdata, pwodata, phdo, po) );
		}
		printf("\n");
	}
	
	
	// ���������
	for(n=0; n < r_cnt; ++n){
		free(plrndata[n]);
	}
	free(pwhdata);
	free(pwodata);
	free(phdo);
	free(po);
	free(pflt);
	free(pin);
	
	return 0;
	
}


