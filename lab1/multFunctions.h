#pragma once

static void multInt(void* result, void* a, void* b);
static void multFloat(void* result, void* a, void* b);
static void multDouble(void* result, void* a, void* b);
static void multComplex(void* result, void* a, void* b);
// сюда можно добавить функцию для произвольного типа данных
extern void (*ptrMultArr[])(void*, void*, void*);
