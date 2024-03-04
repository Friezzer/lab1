#pragma once

typedef enum// пользовательские типы данных
{
	INT, FLOAT, DOUBLE, COMPLEX
} types;
typedef struct
{
	void* arr;// массив, который хранит нужные данные
	types type;//тип данных
	size_t size;//размер массива
	size_t elementSize;// размер одного элемента массива
} vector;