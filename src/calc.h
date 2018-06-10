#ifndef  CALC_H
#define  CALC_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define SIZE 1024

double number(char *str, size_t *idx);

double summ(char *str, size_t *idx);

double multiple(char *str, size_t *idx);

double factor(char *str, size_t *idx);

double brackets(char *str, size_t *idx);

void clrscr(void);


#endif