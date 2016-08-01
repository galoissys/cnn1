/*********************************************************/
/*  rnd.h                                                */
/*                                                       */
/*  —”¶¬ƒvƒƒOƒ‰ƒ€                                   */
/*                                                       */
/*                                                       */
/*********************************************************/
#ifndef _RND_H_
#define _RND_H_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


/*  —”¶¬ ŠÖ”                       */
double rand1();                      // 0`1‚ÌÀ”‚ğ•Ô‚·
double drnd(void);                   // -1`1‚ÌÀ”‚ğ•Ô‚·
int rand01();                        // 0 or 1 ‚Ì®”‚ğ•Ô‚·
int rand100();                       // 0`100‚Ì®”‚ğ•Ô‚·
int rndn(int n);                     // n–¢–‚Ì—”¶¬

#endif

