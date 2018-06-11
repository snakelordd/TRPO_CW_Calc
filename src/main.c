#include "calc.h"


int main() {
	char str[SIZE] = " ";
	while(1) {
		interface(str);
		//printf("Enter expression: ");
		//fgets(str, SIZE, stdin);
		double result = 0.0;
		size_t i = 0;
		result = summ(str, &i);
		printf("Result = %.2lf\n\n", result);
	}
	return 0;
}