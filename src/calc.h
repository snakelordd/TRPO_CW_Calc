#ifndef  CALC_H
#define  CALC_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ncurses.h>
#include <string.h>
#define SIZE 30


double number(char *str, size_t *idx);

double summ(char *str, size_t *idx);

double multiple(char *str, size_t *idx);

double factor(char *str, size_t *idx);

double brackets(char *str, size_t *idx);

void clrscr(void);

void digit(WINDOW *win);

int check(char *str, int x, int y, int *i);

void interface(char *str);


#endif