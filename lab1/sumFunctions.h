#pragma once

static void sumInt(void* result, void* a, void* b);
static void sumFloat(void* result, void* a, void* b);
static void sumDouble(void* result, void* a, void* b);
static void sumComplex(void* result, void* a, void* b);
// ���� ����� �������� ������� ��� ������������� ���� ������
extern void (*ptrSumArr[])(void*, void*, void*);
