#pragma once

static void multInt(void* result, void* a, void* b);
static void multFloat(void* result, void* a, void* b);
static void multDouble(void* result, void* a, void* b);
static void multComplex(void* result, void* a, void* b);
// ���� ����� �������� ������� ��� ������������� ���� ������
extern void (*ptrMultArr[])(void*, void*, void*);
