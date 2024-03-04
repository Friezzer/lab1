
#include "allCustomHeaders.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "otherFunctions.h"
// Тест на корректное сложение векторов
void setUp() { /* Инициализация ресурсов перед каждым тестом */ }
void tearDown() { /* Освобождение ресурсов после каждого теста */ }
void test_sumArr_correct_Int()
{
	size_t n = 10000;
	vector* v1 = initialization(INT, n, sizeof(int));
	vector* v2 = initialization(INT, n, sizeof(int));
	int* testArr = (int*)malloc(n * sizeof(int));
	if (testArr == NULL)
	{
		printf("failure alloc memory\n");
		return;
	}
	for (size_t i = 0; i < n; i++)
	{
		int a = rand() - rand(); // чтобы в a были всевозможные числа в том числе и отрицательные
		int b = rand() - rand();
		set(v1, i, &a);
		set(v2, i, &b);
		testArr[i] = a + b;// массив с заведомо правильными значениями суммы
	}
	vector* result = sumArr(v1, v2);

	// Проверка, что результат сложения корректен
	for (size_t i = 0; i < n; i++)
	{
		TEST_ASSERT_EQUAL_INT(testArr[i], *(int*)get(result, i));
	}
	deallocate(v1);
	deallocate(v2);
	deallocate(result);
}

void test_sumArr_correct_Float()
{
	size_t n = 10000;
	vector* v1 = initialization(FLOAT, n, sizeof(float));
	vector* v2 = initialization(FLOAT, n, sizeof(float));
	float* testArr = (float*)malloc(n * sizeof(float));
	if (testArr == NULL)
	{
		printf("failure alloc memory\n");
		return;
	}
	for (size_t i = 0; i < n; i++)
	{
		float a = rand()*1.0f - rand()*1.0f; // чтобы в a были всевозможные числа в том числе и отрицательные
		float b = rand()*1.0f - rand()*1.0f;
		set(v1, i, &a);
		set(v2, i, &b);
		testArr[i] = a + b;// массив с заведомо правильными значениями суммы
	}
	vector* result = sumArr(v1, v2);

	// Проверка, что результат сложения корректен
	for (size_t i = 0; i < n; i++)
	{
		TEST_ASSERT_EQUAL_INT(testArr[i], *(float*)get(result, i));
	}
	deallocate(v1);
	deallocate(v2);
	deallocate(result);
}
void test_sumArr_correct_Double()
{
	size_t n = 10000;
	vector* v1 = initialization(DOUBLE, n, sizeof(double));
	vector* v2 = initialization(DOUBLE, n, sizeof(double));
	double* testArr = (double*)malloc(n * sizeof(double));
	if (testArr == NULL)
	{
		printf("failure alloc memory\n");
		return;
	}
	for (size_t i = 0; i < n; i++)
	{
		double a = rand() * 1.0f - rand() * 1.0f; // чтобы в a были всевозможные числа в том числе и отрицательные
		double b = rand() * 1.0f - rand() * 1.0f;
		set(v1, i, &a);
		set(v2, i, &b);
		testArr[i] = a + b;// массив с заведомо правильными значениями суммы
	}
	vector* result = sumArr(v1, v2);

	// Проверка, что результат сложения корректен
	for (size_t i = 0; i < n; i++)
	{
		TEST_ASSERT_EQUAL_FLOAT(testArr[i], *(double*)get(result, i));
	}
	deallocate(v1);
	deallocate(v2);
	deallocate(result);
}
void test_sumArr_correct_Complex()
{
	size_t n = 10000;
	vector* v1 = initialization(COMPLEX, n, sizeof(complex));
	vector* v2 = initialization(COMPLEX, n, sizeof(complex));
	complex* testArr = (complex*)malloc(n * sizeof(complex));
	if (testArr == NULL)
	{
		printf("failure alloc memory\n");
		return;
	}
	for (size_t i = 0; i < n; i++)
	{
		complex a; 
		setComplex(&a, rand() * 1.0f - rand() * 1.0f, rand() * 1.0f - rand() * 1.0f);
		complex b;
		setComplex(&b, rand() * 1.0f - rand() * 1.0f, rand() * 1.0f - rand() * 1.0f);
		
		set(v1, i, &a);
		set(v2, i, &b);
		setComplex(&testArr[i], a.re + b.re, a.im + b.im);
	}
	vector* result = sumArr(v1, v2);

	// Проверка, что результат сложения корректен
	for (size_t i = 0; i < n; i++)
	{
		TEST_ASSERT_EQUAL_FLOAT(testArr[i].re, (*(complex*)get(result, i)).re);
		TEST_ASSERT_EQUAL_FLOAT(testArr[i].im, (*(complex*)get(result, i)).im);
	}
	deallocate(v1);
	deallocate(v2);
	deallocate(result);
}

