#pragma once
typedef enum// типы возможных ошибок
{
	ERROR_DIFFERENT_SIZES, ERROR_DIFFERENT_TYPES, ERROR_OUT_OF_INDEX
} errors;
void errorHandler(int error);// функция обработки ошибок