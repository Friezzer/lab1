#pragma once

typedef enum// ���������������� ���� ������
{
	INT, FLOAT, DOUBLE, COMPLEX
} types;
typedef struct
{
	void* arr;// ������, ������� ������ ������ ������
	types type;//��� ������
	size_t size;//������ �������
	size_t elementSize;// ������ ������ �������� �������
} vector;