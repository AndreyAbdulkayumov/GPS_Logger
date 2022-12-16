#include "NEO_6M.h"

UART_HandleTypeDef* UART_Module = NULL;

uint8_t DataFrom_GPS_Module = 0;

uint16_t BufferIndex = 0;
char DataFromGPS[500];

uint8_t Is_Line_ID_Part = 0;

char Line_GPRMC[5] = {'G','P','R','M','C'};
char Line_GPVTG[5] = {'G','P','V','T','G'};
char Line_GPGGA[5] = {'G','P','G','G','A'};
char Line_GPGSA[5] = {'G','P','G','S','A'};
char Line_GPGSV[5] = {'G','P','G','S','V'};
char Line_GPGLL[5] = {'G','P','G','L','L'};

char ReceivedLineBuffer[5] = { 0, 0, 0, 0, 0 };

const uint8_t MaxLineLength = 5;
uint8_t LineLengthCounter = 0;

uint8_t IsLastLine = 0;

Logging_Status (*Action) (char* String, uint32_t StringSize);

void GPS_Module_Init(
		UART_HandleTypeDef* Selected_UART_Module,
		Logging_Status (*CallbackAction) (char* String, uint32_t StringSize)
		)
{
	UART_Module = Selected_UART_Module;

	Action = CallbackAction;
}


void GPS_Module_StartReceive()
{
	if (UART_Module != NULL)
	{
		HAL_UART_Receive_IT(UART_Module, &DataFrom_GPS_Module, 1);
	}
}


void RecognizeLineID(char* Buffer)
{
	if (strcmp(Buffer, Line_GPRMC) == 0)
	{

	}

	else if (strcmp(Buffer, Line_GPVTG) == 0)
	{

	}

	else if (strcmp(Buffer, Line_GPGGA) == 0)
	{

	}

	else if (strcmp(Buffer, Line_GPGSV) == 0)
	{

	}

	else if (strcmp(Buffer, Line_GPGLL) == 0)
	{
		IsLastLine = 1;
	}
}


void ReceiveLineID()
{
	ReceivedLineBuffer[LineLengthCounter] = DataFrom_GPS_Module;
	LineLengthCounter++;

	if (LineLengthCounter >= MaxLineLength)
	{
		Is_Line_ID_Part = 0;
		LineLengthCounter = 0;

		RecognizeLineID(ReceivedLineBuffer);

		for (uint8_t i = 0; i < MaxLineLength; i++)
		{
			ReceivedLineBuffer[i] = 0;
		}
	}
}


void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	if (huart == UART_Module)
	{
		if (Is_Line_ID_Part > 0)
		{
			ReceiveLineID();
		}

		if (DataFrom_GPS_Module == '$')
		{
			Is_Line_ID_Part = 1;
		}

		if (IsLastLine > 0 && DataFrom_GPS_Module == '\n')
		{
			if (Action != NULL)
			{
				Action(DataFromGPS, BufferIndex);
			}

			for (uint16_t i = 0; i < BufferIndex; i++)
			{
				DataFromGPS[i] = 0;
			}

			BufferIndex = 0;
			IsLastLine = 0;
		}

		else
		{
			DataFromGPS[BufferIndex] = DataFrom_GPS_Module;
			BufferIndex++;
		}

		HAL_UART_Receive_IT(UART_Module, &DataFrom_GPS_Module, 1);
	}
}
