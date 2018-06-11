#ifndef  NC_H
#define  NC_H


#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 1024


void interface(char *str);

int check(char *str, int x, int y, int *i);

void digit(WINDOW *win);


#endif