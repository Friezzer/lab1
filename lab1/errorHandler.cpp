#include <stdio.h>
#include "errorHandler.h"// функция обработки ошибок
void errorHandler(int error)
{
	switch (error)
	{
	case ERROR_DIFFERENT_SIZES:
		printf("vectors must be the same length\n");
		break;
	case ERROR_OUT_OF_INDEX:
		printf("you are out of range\n");
		break;
	case ERROR_DIFFERENT_TYPES:
		printf("vectors must be the same types\n");
		break;
	default:
		printf("Unknown error\n");
	}
}
