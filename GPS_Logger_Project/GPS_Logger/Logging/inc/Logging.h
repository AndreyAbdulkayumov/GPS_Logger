#pragma once

#include "stm32f4xx_hal.h"
#include "fatfs.h"

typedef enum
{

	Logging_OK,
	Logging_ERROR

} Logging_Status;

typedef enum
{

	SD_Card,
	External_Memory

} TypeOfMemory;

Logging_Status Logging_Init(TypeOfMemory SelectedType, char* SelectedFileName);

Logging_Status Logging_WriteLog(char* LogString, uint32_t StringSize);
