#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define SIZE 1024
#define STACK_MAX_SIZE 20
#define STACK_OVERFLOW -1
#define STACK_UNDERFLOW -2

typedef struct Stack {
	int data[STACK_MAX_SIZE];
	size_t size;
} stack_t;

void PushStack(stack_t *stack, const int value);
int pop(stack_t *stack);
double number(char *str, size_t *idx);

int main() {
	double result;
	char str[SIZE];
	size_t i;
	printf("Enter expression: ");
	fgets(str, SIZE, stdin);
	i = 0;
	result = number(str, &i);
	printf("\n\n%f\n", result);


}

double number(char *str, size_t *idx) {
	double result = 0.0;
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
 
	return sign * result;

}

void PushStack(stack_t *stack, const int value) {
	if (stack->size >= STACK_MAX_SIZE) {
		exit(STACK_OVERFLOW);
	}
	stack->data[stack->size] = value;
	stack->size++;
}


int pop(stack_t *stack) {
	if (stack->size == 0) {
		exit(STACK_UNDERFLOW);
	}
	stack->size--;
	return stack->data[stack->size];
}