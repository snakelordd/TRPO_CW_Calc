#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define SIZE 1024
#define STACK_MAX_SIZE 20
#define STACK_OVERFLOW -1
#define STACK_UNDERFLOW -2

typedef struct Stack { // стек чисел
	double data[STACK_MAX_SIZE];
	size_t size;
} stack_t;

typedef struct OperStack { // стек операций
	char data[STACK_MAX_SIZE];
	size_t size;
} operstack;

void PushStack(stack_t *stack, const double value); //заполнение стека числами
void push_oper_stack(operstack *signstack, const char value); //заполнение стека операций
double PopStack(stack_t *stack); // удаление вершины стека
double peek(const stack_t *stack);
char PopSign(operstack *signstack); // возвращает текущий элемент с вершины стека
double Number(char *str, size_t *idx);
void Eval(char *str);
char summ(char *str, size_t *idx);
char multiple(char *str, size_t *idx);
char PeekSign(const operstack *signstack);
double factor(char *str, size_t *idx);
double brackets(char *str, size_t *idx);


int main() {
	
	char str[SIZE];
	while(1) {
	printf("Enter expression: ");
	fgets(str, SIZE, stdin);
	Eval(str);
	}
}

void Eval(char *str) {
	char sign, n;
	stack_t stack;
	stack.size = 0;
	operstack signstack;
	signstack.size = 0;
	double result = 0.0;
	size_t i = 0;

	return summ(str, &i);

}

double Number(char *str, size_t *idx) {
	double result = 0.0;
	double div = 10.0;
	int sign = 1;
 
	if (str[*idx] == '-')
	{
		sign = -1;
		++*idx;
	}
 
	while (str[*idx] >= '0' && str[*idx] <= '9')
	{
		result = result * 10.0 + (str[*idx] - '0');
		
		++*idx;
	}

	if (str[*idx] == '.')
	{
		++*idx;
 
		while (str[*idx] >= '0' && str[*idx] <= '9')
		{
			result = result + (str[*idx] - '0') / div;
			div *= 10.0;
 
			++*idx;
		}
	}
	return result*sign;

}

char summ(char *str, size_t *idx) {
	double result = multiple(str, idx);
	while (str[*idx] == '+' || str[*idx] == '-')
    {
	switch (str[*idx])
	{
	case '+':
		++*idx;
		result = multiple(str, idx) + result;
		break;
	case '-':
		++*idx;
		result = multiple(str, idx) - result;
		break;
	}
	}
	return result;
}



char multiple(char *str, size_t *idx) {
	double result, div;
	char sign;
	while (str[*idx] == '*' || str[*idx] == '/')
    {
		switch (str[*idx])
		{
		case '*':	
		++*idx;
		sign = '*';
		result = factor(str, idx) * result;
		return result;
		break;
		case '/':
		++*idx;
		sign = '/';
		div = factor(str, idx);
		if (div == 0) {
			return -1;
		} 
		result = result / div;
		return result;
		break;
		}
	}
	
	

}

 
double factor(char *str, size_t *idx) {
    double result;
    int sign = 1;

 
    if (str[*idx] == '-')
    {
        sign = -1;
 
        ++*idx;
    }

    

    if (str[*idx] == '^')
    {
        ++*idx;
 
        result = pow(result, factor(str, idx));
    }
 
    return sign * result;

}





void PushStack(stack_t *stack, const double value) {
	if (stack->size >= STACK_MAX_SIZE) {
		exit(STACK_OVERFLOW);
	}
	stack->data[stack->size] = value;
	stack->size++;
}

void push_oper_stack(operstack *signstack, const char value) {
	if (signstack->size >= STACK_MAX_SIZE) {
		exit(STACK_OVERFLOW);
	}
	signstack->data[signstack->size] = value;
	signstack->size++;
}


double PopStack(stack_t *stack) {
	if (stack->size == 0) {
		exit(STACK_UNDERFLOW);
	}
	stack->size--;
	return stack->data[stack->size];
}



char PopSign(operstack *signstack) { //rename
    if (signstack->size <= 0) {
        exit(STACK_UNDERFLOW);
    }
    signstack->size--;
    return signstack->data[signstack->size];
}

double peek(const stack_t *stack) {
    if (stack->size <= 0) {
        exit(STACK_UNDERFLOW);
    }
    return stack->data[stack->size - 1];
}

char PeekSign(const operstack *signstack) {
    if (signstack->size <= 0) {
        exit(STACK_UNDERFLOW);
    }
    return signstack->data[signstack->size - 1];
}
