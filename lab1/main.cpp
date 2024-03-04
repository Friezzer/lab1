#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>
#include <algorithm>
#include <time.h>
#include "allCustomHeaders.h"

jmp_buf env;
int errorCode = -1;
void deallocate(vector* v)// удаление структуры из динамически выделенной памяти
{
	if (v != NULL)
	{
		if (v->arr != NULL)
		{
			free(v->arr);
		}
		free(v);
	}
}
void print(vector *vec, size_t index)// печать одного элемента
{
	if (index >= vec->size)
	{
		longjmp(env, ERROR_OUT_OF_INDEX);
	}
	ptrPrint[vec->type](vec, index);
}
void* get(vector* vec, size_t index)
{
	if (index >= vec->size)
	{
		longjmp(env, ERROR_OUT_OF_INDEX);
	}
	return (int8_t*)vec->arr + index * vec->elementSize;
}
void set(vector* vec, size_t index, void* elem)
{
	if (index >= vec->size)
	{
		longjmp(env, ERROR_OUT_OF_INDEX);
	}
	memcpy(get(vec, index), elem, vec->elementSize);
}
// инициализация вектора количеством элементов size и элементом elem
vector* initialization(types type, size_t size, size_t elementSize, void* elem = NULL)
{
	vector* vec = (vector*)malloc(sizeof(vector));
	if (vec == NULL)
	{
		printf("failed to allocate memory\n");
		return NULL;
	}
	vec->elementSize = elementSize;
	vec->size = size;
	vec->type = type;
	vec->arr = malloc(size * elementSize);
	if (elem != NULL)
	{
		for (int i = 0; i < size; i++)
			set(vec, i, elem);
	}
	return vec;
}
void resize(vector** vec, size_t n, void* elem = NULL)// метод resize аналогичен методу вектора C++
{
	vector *tmp = initialization((*vec)->type, n, (*vec)->elementSize, elem);
	if ((*vec)->arr != NULL && n > (*vec)->size)
	{
		memcpy(tmp->arr, (*vec)->arr, (*vec)->size*(*vec)->elementSize);
	}
	deallocate(*vec);
	*vec = tmp;
}
void setComplex(complex *obj, double a, double b)
{
	obj->re = a;
	obj->im = b;
}
void getComplex(complex* obj, double* a, double* b)
{
	*a = obj->re;
	*b = obj->im;
}
vector* sumArr(vector *v1, vector *v2)// векторное сложение векторов
{
	vector *res = initialization(v1->type, v1->size, v1->elementSize);
	if (v1->size != v2->size)
	{
		longjmp(env, ERROR_DIFFERENT_SIZES);
	}
	if (v1->type != v2->type)
	{
		longjmp(env, ERROR_DIFFERENT_TYPES);
	}
	for (size_t i = 0; i < v1->size; i++)
	{
		ptrSumArr[res->type](get(res, i), get(v1,i), get(v2,i));
	}
	return res;
}
void* scalarProd(vector *v1, vector *v2)// скалярное произведение векторов
{
	if (v1->size != v2->size)
	{
		longjmp(env, ERROR_DIFFERENT_SIZES);
	}
	if (v1->type != v2->type)
	{
		longjmp(env, ERROR_DIFFERENT_TYPES);
	}
	void* ans = calloc(1,v1->elementSize);// ответ, calloc делаем, чтобы в ans было не NULL значение
	void* intermediateAns = calloc(1, v1->elementSize);// промежуточный результат
	for (size_t i = 0; i < v1->size; i++)
	{
		// сохраняем в промежуточный результат произведение чисел векторов v1, v2
		ptrMultArr[v1->type](intermediateAns, get(v1, i), get(v2, i));
		// к ответу добавляем это произведение
		ptrSumArr[v1->type](ans, ans, intermediateAns);
	}
	return ans;
}


int main()
{
	srand(time(NULL));
	//примеры работы вектора для разных типов данных
	////1.int
	//// создаем 3 вектора произвольного типа данных
	//vector one{INT, NULL, 0, sizeof(int)};
	//vector two{INT, NULL, 0, sizeof(int)};
	//vector answer{INT, NULL, 0, sizeof(int)};
	//int n = 5;
	//// выделяем под него память на нужное кол-во элементов
	//allocation(&one, n);
	//allocation(&two, n);
	//int a = 5;
	//int b = 4;
	////заполняем вектор значениями
	//for (int i = 0; i < n; i++)
	//{
	//	set(&one, i, &a);
	//	a--;
	//}
	//for (int i = 0; i < n; i++)
	//{
	//	set(&two, i, &b);
	//	b+= 2;
	//}
	//print(&one);
	//print(&two);
	//// вектор answer это сумма векторов one и two
	//answer = *sumArr(&one, &two);
	//print(&answer);
	//// эта переменная хранит значение скалярного произведения
	//void* scalarans = scalarProd(&one, &two);
	//printf("%d", *(int*)scalarans);

	////2.float
	//// создаем 3 вектора произвольного типа данных
	//vector one{ FLOAT, NULL, 0, sizeof(float) };
	//vector two{ FLOAT, NULL, 0, sizeof(float) };
	//vector answer{ FLOAT, NULL, 0, sizeof(float) };
	//int n = 3;
	//// выделяем под него память на нужное кол-во элементов
	//allocation(&one, n);
	//allocation(&two, n);
	//float a = 3.14;
	//float b = 2.718;
	////заполняем вектор значениями
	//for (int i = 0; i < n; i++)
	//{
	//	set(&one, i, &a);
	//	a += 0.3;
	//}
	//for (int i = 0; i < n; i++)
	//{
	//	set(&two, i, &b);
	//	b -= 4.1;
	//}
	//print(&one);
	//print(&two);
	//// вектор answer это сумма векторов one и two
	//answer = *sumArr(&one, &two);
	//print(&answer);
	//// эта переменная хранит значение скалярного произведения
	//void* scalarans = scalarProd(&one, &two);
	//printf("%f ", *(float*)scalarans);

	////3.double
	//// создаем 3 вектора произвольного типа данных
	//vector one{ DOUBLE, NULL, 0, sizeof(double) };
	//vector two{ DOUBLE, NULL, 0, sizeof(double) };
	//vector answer{ DOUBLE, NULL, 0, sizeof(double) };
	//int n = 3;
	//// выделяем под него память на нужное кол-во элементов
	//allocation(&one, n);
	//allocation(&two, n);
	//double a = 3.14;
	//double b = 4.91;
	////заполняем вектор значениями
	//for (int i = 0; i < n; i++)
	//{
	//	set(&one, i, &a);
	//	a += 0.4;
	//}
	//for (int i = 0; i < n; i++)
	//{
	//	set(&two, i, &b);
	//	b += 1.5;
	//}
	//print(&one);
	//print(&two);
	//// вектор answer это сумма векторов one и two
	//answer = *sumArr(&one, &two);
	//print(&answer);
	//// эта переменная хранит значение скалярного произведения
	//void* scalarans = scalarProd(&one, &two);
	//printf("%lf ", *(double*)scalarans);

	//4.complex
	// создаем 3 вектора произвольного типа данных
	int n = 5;
	complex a;
	complex b;
	setComplex(&a, 3.59, 7.21);
	setComplex(&b, 1.14, 6.28);
	vector *one = initialization(COMPLEX, n, sizeof(complex), &a);
	vector *two = initialization(COMPLEX, n, sizeof(complex), &b);

	void* scalarans;
	errorCode = setjmp(env);
	if (!errorCode)
	{
		vector* answer = sumArr(one, two);// вектор answer это сумма векторов one и two
		for (size_t i = 0; i < one->size; i++)
		{
			print(one, i);
			printf(" ");
		}
		printf("\n");
		for (size_t i = 0; i < two->size; i++)
		{
			print(two , i);
			printf(" ");
		}
		printf("\n");
		for (size_t i = 0; i < answer->size; i++)
		{
			print(answer, i);
			printf(" ");
		}
		printf("\n");
		scalarans = scalarProd(one, two);// эта переменная хранит значение скалярного произведения
		printf("%lf + %lfi", (*(complex*)scalarans).re, (*(complex*)scalarans).im);
		deallocate(one);
		deallocate(two);
		deallocate(answer);
	}
	else
	{
		errorHandler(errorCode);
	}
	//errorCode = setjmp(env);
	//if (!errorCode)
	//{
	//	UNITY_BEGIN();
	//	RUN_TEST(test_scalarProd_correct_Complex);
	//	return UNITY_END();
	//}
	//else
	//{
	//	errorHandler(errorCode);
	//}

}



