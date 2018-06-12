#include "calc.h"

int check(char *str, int x, int y, size_t *i) {
	if ( x == 4) {
		if (y == 6) {
			int t;
			for (t = 0; t < SIZE; t++) {
				str[t] = ' ';
			}
			str[SIZE] = '\0';
			*i = 0;
		}
		if (y == 8) {
			str[*i] = '(';
			++*i;
		}
		if (y == 10) {
			str[*i] = ')';
			++*i;
		}
		if (y == 12) {
			str[*i] = '^';
			++*i;
		}
	}
	if (x == 9) {
		if ( y == 6){
			str[*i] = '7';
			++*i;
		}
		if (y == 8) {
			str[*i] = '4';
			++*i;
		}
		if (y ==10) {
			str[*i] = '1';
			++*i;
		}
		if (y == 12) {
			str[*i] = '0';
			++*i;
		}
	}	
	if (x == 14){ 
		if(y == 6) {
			str[*i] = '8';
			++*i;
		}
		if (y == 8) {
			str[*i] = '5';
			++*i;
		}
		if (y == 10) {
			str[*i] = '2';
			++*i;
		}
		if ( y == 12) {
			str[*i] = '.';
			++*i;
		}
	}
	if (x == 19)  {
		if(y == 6) {
			str[*i] = '9';
			++*i;
		}
		if (y == 8){
			str[*i] = '6';
			++*i;
		}
		if (y == 10) {
			str[*i] = '3';
			++*i;
		}
		if (y == 12) {
			str[*i] = '\0';
			return *i;
		}
	}
	if ( x == 24) {
		if ( y == 6) {
			str[*i] = '/';
			++*i;
		}
		if ( y == 8) {
			str[*i] = '*';
			++*i;
		}
		if ( y == 10) {
			str[*i] = '-';
			++*i;
		}
		if ( y == 12) {
			str[*i] = '+';
			++*i;
		}
	}
	if ( *i > SIZE) {
		int t;
		for (t = 0; t <=SIZE ; t++) {
			str[t] = ' ';
		}
		return 1;
	}
	
	return 0;

}