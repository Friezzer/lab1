#include "otherStructs.h" // сложение элементов универсальной коллекции
void sumInt(void* result, void* a, void* b)
{
	*(int*)result = *(int*)a + *(int*)b;
}
void sumFloat(void* result, void* a, void* b)
{
	*(float*)result = *(float*)a + *(float*)b;
}
void sumDouble(void* result, void* a, void* b)
{
	*(double*)result = *(double*)a + *(double*)b;
}
void sumComplex(void* result, void* a, void* b)
{
	(*(complex*)result).re = (*(complex*)a).re + (*(complex*)b).re;
	(*(complex*)result).im = (*(complex*)a).im + (*(complex*)b).im;
}
void (*ptrSumArr[])(void*, void*, void*) { sumInt, sumFloat, sumDouble, sumComplex };
const size_t ptrSumSize = sizeof(ptrSumArr) / sizeof(ptrSumArr[0]);// размер массива указателей на функции