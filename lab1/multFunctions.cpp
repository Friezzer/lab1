#include "otherStructs.h"// умножение элементов универсальной коллекции
void multInt(void* result, void* a, void* b)
{
	*(int*)result = *(int*)a * *(int*)b;
}
void multFloat(void* result, void* a, void* b)
{
	*(float*)result = *(float*)a * *(float*)b;
}
void multDouble(void* result, void* a, void* b)
{
	*(double*)result = *(double*)a * *(double*)b;
}
void multComplex(void* result, void* a, void* b)
{
	(*(complex*)result).re = (*(complex*)a).re * (*(complex*)b).re - (*(complex*)a).im * (*(complex*)b).im;
	(*(complex*)result).im = (*(complex*)a).re * (*(complex*)b).im + (*(complex*)a).im * (*(complex*)b).re;
}
void (*ptrMultArr[])(void*, void*, void*) { multInt, multFloat, multDouble, multComplex };
const size_t ptrMultSize = sizeof(ptrMultArr) / sizeof(ptrMultArr[0]);// размер массива указателей на функции