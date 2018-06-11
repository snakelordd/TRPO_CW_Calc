#include <ctest.h>
#include <calc.h>
#include <stdlib.h>

CTEST(calc, digitalization) // Проверка на перевод строки в число
{
	//GIVEN
	char str[] = {'1', '2'};
	char str2[] = {'9', '1', '1'};
	size_t index = 0;

	//WHEN
	double result = number(str, &index);
	index = 0; 
	double result2 = number(str2, &index);
	
	const double expected = 12;
	const double expected2 = 911;
	
	//THEN
	
	ASSERT_EQUAL(expected, result);
	ASSERT_EQUAL(expected2, result2);
}

CTEST(calc, sum) // Проверка на сложение
{
	//GIVEN
	char str[] = {'1', '+', '2'}; //положительные
	size_t index = 0;
	//WHEN
	double result = summ(str, &index); 
	
	//THEN
	const double expected = 3;

	ASSERT_EQUAL(expected, result);

	//GIVEN
	char str2[] = {'-', '1', '+', '-', '2'}; //отрицательные
	index = 0;
	//WHEN
	result = summ(str2, &index);

	//THEN
	const double expected2 = -3;

	ASSERT_EQUAL(expected2, result);

	//GIVEN
	char str3[] = {'-', '4', '+', '5'}; // '-' && '+'
	index = 0;
	//WHEN
	result = summ(str3, &index);

	//THEN
	const double expected3 = 1;

	ASSERT_EQUAL(expected3, result);
}

CTEST(calc, sub) {

	//GIVEN
	char str[] = {'1', '-', '2'}; //вычитание
	size_t index = 0;
	//WHEN
	double result = summ(str, &index);

	//THEN
	double expected = -1;

	ASSERT_EQUAL(expected, result);

	//GIVEN
	char str2[] = {'-', '1', '-', '-', '2'}; //отрицательные
	index = 0;
	//WHEN
	result = summ(str2, &index);

	//THEN
	const double expected2 = 1;

	ASSERT_EQUAL(expected2, result);

	//GIVEN
	char str3[] = {'-', '4', '-', '5'}; // '-' && '+'
	index = 0;
	//WHEN
	result = summ(str3, &index);

	//THEN
	const double expected3 = -9;

	ASSERT_EQUAL(expected3, result);
}

CTEST(calc, multiplication) // Проверка на произведение
{
	//GIVEN
	char str[] = {'9', '*', '1', '0'}; //положительные
	size_t index = 0;
	//WHEN
	double result = multiple(str, &index); 
	
	//THEN
	const double expected = 90;

	ASSERT_EQUAL(expected, result);

	//GIVEN
	char str2[] = {'-', '3', '*', '-', '6'}; //отрицательные
	index = 0;
	//WHEN
	result = summ(str2, &index);

	//THEN
	const double expected2 = 18;

	ASSERT_EQUAL(expected2, result);

	//GIVEN
	char str3[] = {'-', '4', '*', '5'}; // '-' && '+'
	index = 0;
	//WHEN
	result = summ(str3, &index);

	//THEN
	const double expected3 = -20;

	ASSERT_EQUAL(expected3, result);

	//GIVEN
	char str4[] = {'-', '1', '0', '0', '*', '0'}; // умножение на 0
	index = 0;
	//WHEN
	result = summ(str4, &index);

	//THEN
	const double expected4 = 0;

	ASSERT_EQUAL(expected4, result);
}

CTEST(calc, division) // Проверка на деление
{
	//GIVEN
	char str[] = {'9', '/', '1', '0'}; //положительные
	size_t index = 0;
	//WHEN
	double result = multiple(str, &index); 
	
	//THEN
	const double expected = 0.9;

	ASSERT_EQUAL(expected, result);

	//GIVEN
	char str2[] = {'-', '6', '/', '-', '3'}; //отрицательные
	index = 0;
	//WHEN
	result = summ(str2, &index);

	//THEN
	const double expected2 = 2;

	ASSERT_EQUAL(expected2, result);

	//GIVEN
	char str3[] = {'-', '3', '/', '2'}; // '-' && '+'
	index = 0;
	//WHEN
	result = summ(str3, &index);

	//THEN
	const double expected3 = -1.5;

	ASSERT_EQUAL(expected3, result);

	//GIVEN
	char str4[] = {'-', '1', '0', '0', '/', '0'}; // деление на 0
	index = 0;
	//WHEN
	result = summ(str4, &index);

	//THEN
	const double expected4 = -0.000001;

	ASSERT_EQUAL(expected4, result);
}

CTEST(calc, power) // Проверка на степени
{
	//GIVEN
	char str[] = {'9', '^', '2'}; //положительные
	size_t index = 0;
	//WHEN
	double result = factor(str, &index); 
	
	//THEN
	const double expected = 81;

	ASSERT_EQUAL(expected, result);

	//GIVEN
	char str2[] = {'2', '^', '-', '2'}; //отрицательные
	index = 0;
	//WHEN
	result = summ(str2, &index);

	//THEN
	const double expected2 = 0.25;

	ASSERT_EQUAL(expected2, result);

	//GIVEN
	char str3[] = {'4', '^', '(', '1', '/', '2', ')' }; // корень
	index = 0;
	//WHEN
	result = summ(str3, &index);

	//THEN
	const double expected3 = 2;

	ASSERT_EQUAL(expected3, result);

	//GIVEN
	char str4[] = {'5', '1', '2', '^', '0'}; // степень 0
	index = 0;
	//WHEN
	result = summ(str4, &index);

	//THEN
	const double expected4 = 1;

	ASSERT_EQUAL(expected4, result);
}

CTEST(calc, brackets) // Проверка скобок
{
	//GIVEN
	char str[] = {'(', ')'}; //проверка на соответствие
	size_t index = 0;
	//WHEN
	double result = multiple(str, &index); 
	
	//THEN
	const double expected = 0;

	ASSERT_EQUAL(expected, result);

	//GIVEN
	char str2[] = {'(', '(', ')'}; //проверка на несоответствие
	index = 0;
	//WHEN
	result = multiple(str2, &index); 
	
	//THEN
	const double expected2 = -0.000001;

	ASSERT_EQUAL(expected2, result);

}
