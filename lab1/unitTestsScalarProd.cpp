#include "allCustomHeaders.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "otherFunctions.h"
// Тест на корректное сложение векторов
void test_scalarProd_correct_Int()
{
	size_t n = 10000;
	vector* v1 = initialization(INT, n, sizeof(int));
	vector* v2 = initialization(INT, n, sizeof(int));
	int ansTest = 0;
	for (size_t i = 0; i < n; i++)
	{
		int a = rand() - rand(); // чтобы в a были всевозможные числа в том числе и отрицательные
		int b = rand() - rand();
		set(v1, i, &a);
		set(v2, i, &b);
		ansTest += a * b;// заведомо верный результат
	}
	void* result = scalarProd(v1, v2);

	// Проверка, что результат сложения корректен
	for (size_t i = 0; i < n; i++)
	{
		TEST_ASSERT_EQUAL_INT(ansTest, *(int*)result);
	}
	deallocate(v1);
	deallocate(v2);
}

void test_scalarProd_correct_Float()
{
	size_t n = 10000;
	vector* v1 = initialization(FLOAT, n, sizeof(float));
	vector* v2 = initialization(FLOAT, n, sizeof(float));
	float ansTest = 0;
	for (size_t i = 0; i < n; i++)
	{
		float a = rand() * 1.0f - rand() * 1.0f; // чтобы в a были всевозможные числа в том числе и отрицательные
		float b = rand() * 1.0f - rand() * 1.0f;
		set(v1, i, &a);
		set(v2, i, &b);
		ansTest += a * b;// заведомо верный результат
	}
	void* result = scalarProd(v1, v2);

	// Проверка, что результат сложения корректен
	for (size_t i = 0; i < n; i++)
	{
		TEST_ASSERT_EQUAL_FLOAT(ansTest, *(float*)result);
	}
	deallocate(v1);
	deallocate(v2);
}
void test_scalarProd_correct_Double()
{
	size_t n = 10000;
	vector* v1 = initialization(DOUBLE, n, sizeof(double));
	vector* v2 = initialization(DOUBLE, n, sizeof(double));
	double ansTest = 0;
	for (size_t i = 0; i < n; i++)
	{
		double a = rand() * 1.0f - rand() * 1.0f; // чтобы в a были всевозможные числа в том числе и отрицательные
		double b = rand() * 1.0f - rand() * 1.0f;
		set(v1, i, &a);
		set(v2, i, &b);
		ansTest += a*b;// заведомо верный результат
	}
	void* result = scalarProd(v1, v2);

	// Проверка, что результат сложения корректен
	for (size_t i = 0; i < n; i++)
	{
		TEST_ASSERT_EQUAL_FLOAT(ansTest, *(double*)result);
	}
	deallocate(v1);
	deallocate(v2);
}
void test_scalarProd_correct_Complex()
{
	size_t n = 10000;
	vector* v1 = initialization(COMPLEX, n, sizeof(complex));
	vector* v2 = initialization(COMPLEX, n, sizeof(complex));
	complex ansTest;
	setComplex(&ansTest, 0, 0);
	for (size_t i = 0; i < n; i++)
	{
		complex a;
		setComplex(&a, rand() * 1.0f - rand() * 1.0f, rand() * 1.0f - rand() * 1.0f);
		complex b;
		setComplex(&b, rand() * 1.0f - rand() * 1.0f, rand() * 1.0f - rand() * 1.0f);
		set(v1, i, &a);
		set(v2, i, &b);
		ansTest.re += a.re * b.re - a.im * b.im;
		ansTest.im += a.im * b.re + a.re * b.im;
	}
	void* result = scalarProd(v1, v2);
	// Проверка, что результат сложения корректен
	for (size_t i = 0; i < n; i++)
	{
		TEST_ASSERT_EQUAL_FLOAT(ansTest.re, (*(complex*)result).re);
		TEST_ASSERT_EQUAL_FLOAT(ansTest.im, (*(complex*)result).im);
	}
	deallocate(v1);
	deallocate(v2);
}
