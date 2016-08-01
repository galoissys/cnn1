/*********************************************************/
/*  lrndata.c                                            */
/*                                                       */
/*********************************************************/
#include "lrndata.h"

/*********************************************************/
/*  initldatas関数                                         */
/*********************************************************/
void initldatas(Lrndatas *lrndata){
	
	int i=0, j=0, k=0;
	
	memset(lrndata, 0, sizeof(Lrndatas));
	
	for(i=0; i < INPUT_MAX; ++i){
		for(j=0; j < INPUTSIZE; ++j){
			for(k=0; k < INPUTSIZE; ++k){
				lrndata->ldata[i][j][k] = 0.0;
			}
		}
	}
	
	
}


/*********************************************************/
/*  setldatas関数                                         */
/*********************************************************/
int setldatas(Lrndatas *lrndata){
	
	int i=0, j=0, k=0;
	
	while( scanf("%d", &lrndata->t[i]) != EOF){  //  教師データ読み込み
		/*  画像データ読み込み  */
		while( scanf("%lf", &lrndata->ldata[i][j][k]) != EOF){
			++k;
			if(k >= INPUTSIZE){  //  次のデータ
				k = 0;
				++j;
				if(j >= INPUTSIZE) break;  //  入力終了
			}
		}
		j=0; k=0;
		++i;
	}
	
	lrndata->num_of_data = i;
	
	return i;
}


/*********************************************************/
/*  getldatas関数                                         */
/*********************************************************/
void getldatas(Lrndatas *lrndata){
	
	int i=0, j=0, k=0;
	
	printf("*** Learnning Data Set ***\n");
	
	for(i=0; i < lrndata->num_of_data; ++i){
		printf("Num = %d  category=%d(teacher data)\n", i, lrndata->t[i]);
		printf("** INPUT Data **\n");
		for(j=0; j < INPUTSIZE; ++j){
			for(k=0; k < INPUTSIZE; ++k){
				printf("%lf ", lrndata->ldata[i][j][k]);
			}
			printf("\n");
		}
		printf("\n");
	}
	
}


/*********************************************************/
/*  setldata関数                                        */
/*********************************************************/
int setldata(Lrndata *lrndata[]){
	
	int i=0, j=0, k=0;
	
	while( scanf("%d", &lrndata[i]->t) != EOF){  //  教師データ読み込み
	/*  画像データ読み込み  */
		while( scanf("%lf", &lrndata[i]->ldata[j][k]) != EOF){
			++k;
			if(k >= INPUTSIZE){  //  次のデータ
				k = 0;
				++j;
				if(j >= INPUTSIZE) break;  //  入力終了
			}
		}
		j=0; k=0;
		++i;
	}
	
	return i;
}


/*********************************************************/
/*  getldata関数                                         */
/*********************************************************/
void getldata(int count, Lrndata *lrndata[]){
	
	int i=0, j=0, k=0;
	
	printf("*** Learnning Data Set 2 ***\n");
	
	for(i=0; i < count; ++i){
		printf("Num = %d  category=%d(teacher data)\n", i, lrndata[i]->t);
		printf("** INPUT Data **\n");
		for(j=0; j < INPUTSIZE; ++j){
			for(k=0; k < INPUTSIZE; ++k){
				printf("%lf ", lrndata[i]->ldata[j][k]);
			}
			printf("\n");
		}
		printf("\n");
	}
	
}


