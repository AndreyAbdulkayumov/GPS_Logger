#include "Logging.h"

FATFS SDFatFs;
FIL LogFile;
FRESULT ActionResult;

uint32_t RecordedBytes;

extern char SDPath[4];

char* FileName;

Logging_Status SD_Card_Init()
{
	// Монтировать диск
	ActionResult = f_mount(&SDFatFs, (TCHAR const*)SDPath, 1);

	if (ActionResult != FR_OK)
	{
		return Logging_ERROR;
	}

	return Logging_OK;
}

Logging_Status Logging_Init(TypeOfMemory SelectedType, char* SelectedFileName)
{
	FileName = SelectedFileName;

	switch(SelectedType)
	{
	case SD_Card:
		return SD_Card_Init();

	case External_Memory:
		return Logging_ERROR;

	default:
		return Logging_ERROR;
	}
}

Logging_Status OpenOrCreateFile()
{
	// Создать файл и открыть его на запись
	ActionResult = f_open(&LogFile, FileName, FA_CREATE_NEW | FA_WRITE);

	// Если такой файл уже существует
	if (ActionResult == FR_EXIST)
	{
		// Открыть файл на запись
		ActionResult = f_open(&LogFile, FileName, FA_OPEN_ALWAYS | FA_WRITE);

		if (ActionResult != FR_OK)
		{
			return Logging_ERROR;
		}

		return Logging_OK;
	}

	if (ActionResult != FR_OK)
	{
		return Logging_ERROR;
	}

	return Logging_OK;
}

Logging_Status Logging_WriteLog(char* LogString, uint32_t StringSize)
{
	if (OpenOrCreateFile() != Logging_OK)
	{
		return Logging_ERROR;
	}

	// Переход в конец файла
	ActionResult = f_lseek(&LogFile, f_size(&LogFile));

	if (ActionResult != FR_OK)
	{
		return Logging_ERROR;
	}

	// Записать в файл заданный текст
	ActionResult = f_write(&LogFile, LogString, StringSize, (void*)&RecordedBytes);

	// Если данные записались не полностью или возникла ошибка записи
	if ((RecordedBytes != StringSize) || (ActionResult != FR_OK))
	{
		return Logging_ERROR;
	}

	// Закрыть файл
	ActionResult = f_close(&LogFile);

	if (ActionResult != FR_OK)
	{
		return Logging_ERROR;
	}

	return Logging_OK;
}
