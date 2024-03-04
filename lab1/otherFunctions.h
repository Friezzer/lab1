#pragma once
#include "myVectorStruct.h"
#include "otherStructs.h"

void deallocate(vector* v);
void print(vector* vec, size_t index);
void* get(vector* vec, size_t index);
void set(vector* vec, size_t index, void* elem);
vector* initialization(types type, size_t size, size_t elementSize, void* elem = NULL);
void resize(vector** vec, size_t n, void* elem = NULL);
void setComplex(complex* obj, double a, double b);
void getComplex(complex* obj, double* a, double* b);
vector* sumArr(vector* v1, vector* v2);
void* scalarProd(vector* v1, vector* v2);