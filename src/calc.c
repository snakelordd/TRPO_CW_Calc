#include "calc.h"


double number(char *str, size_t *idx) {
	double result = 0.0;
	double div = 10.0;
	int sign = 1;
	if (str[*idx] == '-') {
		sign = -1;
		++*idx;
	}
	while (str[*idx] >= '0' && str[*idx] <= '9') {
		result = result * 10.0 + (str[*idx] - '0');
		++*idx;
	}
	if (str[*idx] == '.') {
		++*idx;
		while (str[*idx] >= '0' && str[*idx] <= '9') {
			result = result + (str[*idx] - '0') / div;
			div *= 10.0;
			++*idx;
		}
	}
	return sign * result;
}

double summ(char *str, size_t *idx) {
	double result = multiple(str, idx);
	while (str[*idx] == '+' || str[*idx] == '-') {
		switch (str[*idx]) {
		case '+':
			++*idx;
			result += multiple(str, idx);
			break;
		case '-':
			++*idx;
			result -= multiple(str, idx);
			break;
		}
	}
	return result;
}

double multiple(char *str, size_t *idx) {
	double result, div;
	result = factor(str, idx);
	char sign;
	while (str[*idx] == '*' || str[*idx] == '/') {
		switch (str[*idx]) {
		case '*':
			++*idx;
			sign = '*';
			result *= factor(str, idx);
			break;
		case '/':
			++*idx;
			sign = '/';
			div = factor(str, idx);
			if (div == 0) {
				//mvprintw( 2, 15, "Zero div!");
				//exit(-2);
		}
			result /=  div;
			break;
		}
	}
	return result;
}

double factor(char *str, size_t *idx) {
	double result;
	int sign = 1;
	if (str[*idx] == '-') {
		sign = -1;
		++*idx;
	}
	result = brackets(str, idx);
	if (str[*idx] == '^') {
		++*idx;
		result = pow(result, factor(str, idx));
	}
	return sign * result;
}


double brackets(char *str, size_t *idx){
	double result;
	if (str[*idx] == '(') {
		++*idx;
		result = summ(str, idx);
		if (str[*idx] != ')') {
			char err[] = "Brackets unbalanced!";
			mvaddstr(3, (33-strlen(err))/2, err);
			//printw("Brackets unbalanced!\n");
			//exit(-2);
			return ;
		}
		++*idx;
	}
	else
		result = number(str, idx);
	return result;
}

void clrscr(void) {
	printf("\033[2J");
	printf("\033[0;0f");
}