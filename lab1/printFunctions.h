#pragma once
#include "myVectorStruct.h"
static void printInt(vector* v, size_t i); 
static void printFloat(vector* v, size_t i);
static void printDouble(vector* v, size_t i);
static void printComplex(vector* v, size_t i); 
// сюда можно добавить функцию для произвольного типа данных
extern void (*ptrPrint[])(vector*, size_t i);
