#include <stdio.h>// печать одного элемента универсальной коллекции на экран
#include "printFunctions.h"
#include "otherStructs.h"
void printInt(vector* v, size_t i)
{
	printf("%d", ((int*)v->arr)[i]);
}
void printFloat(vector* v, size_t i)
{
	printf("%f", ((float*)v->arr)[i]);
}
void printDouble(vector* v, size_t i)
{
	printf("%lf", ((double*)v->arr)[i]);
}
void printComplex(vector* v, size_t i)
{
	printf("%lf + %lfi", ((complex*)v->arr)[i].re, ((complex*)v->arr)[i].im);
}
void (*ptrPrint[])(vector*, size_t i) = { printInt, printFloat, printDouble, printComplex };
const size_t ptrPrintSize = sizeof(ptrPrint) / sizeof(ptrPrint[0]);//размер массива указателей на функции