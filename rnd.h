/*********************************************************/
/*  rnd.h                                                */
/*                                                       */
/*  ���������v���O����                                   */
/*                                                       */
/*                                                       */
/*********************************************************/
#ifndef _RND_H_
#define _RND_H_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


/*  �������� �֐�                       */
double rand1();                      // 0�`1�̎�����Ԃ�
double drnd(void);                   // -1�`1�̎�����Ԃ�
int rand01();                        // 0 or 1 �̐�����Ԃ�
int rand100();                       // 0�`100�̐�����Ԃ�
int rndn(int n);                     // n�����̗�������

#endif

