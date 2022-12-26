#include "NEO_6M.h"

typedef enum
{
	Stop,
	Start
} GPS_Status;

GPS_Status GPS_Module_Status = Stop;

UART_HandleTypeDef* UART_Module = NULL;

uint8_t DataFrom_GPS_Module = 0;

uint16_t BufferIndex = 0;
char DataFromGPS[500];

char MainData[200];

char OutputString[200];

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
		for (uint16_t i = 0; i < BufferIndex; i++)
		{
			DataFromGPS[i] = 0;
		}

		BufferIndex = 0;
		IsLastLine = 0;

		GPS_Module_Status = Start;
		HAL_UART_Receive_IT(UART_Module, &DataFrom_GPS_Module, 1);
	}
}

void GPS_Module_StopReceive()
{
	GPS_Module_Status = Stop;
}


void RecognizeLineID(char* Buffer)
{
	if (strcmp(Buffer, Line_GPRMC) == 0)
	{

	}

	else if (strcmp(Buffer, Line_GPVTG) == 0)
	{
		strcpy(MainData, DataFromGPS);
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
			char* Line = NULL;
			char* Save = NULL;

			//char* qw = "$GPRMC,183058.00,A,5534.00034,N,03813.57065,E,0.270,,191222,,,A*71";

			char wer[100];

			sprintf(wer, "%s", MainData);

			Line = strtok_r(wer, ",", &Save);

			uint8_t counter = 0;
			uint8_t IsData = 0;

			while(Line != NULL)
			{
				if (*Line == 'V')
				{
					break;
				}

				else if (*Line == 'A')
				{
					IsData = 1;
				}

				Line = strtok_r(NULL, ",", &Save);

				if (IsData > 0 && counter < 4)
				{
					strcat(OutputString, Line);
					counter++;

					if (counter == 2)
					{
						strcat(OutputString, " ");
					}

					if (counter == 4)
					{
						strcat(OutputString, "\n");
					}
				}
			}

			if (Action != NULL)
			{
				//Action(DataFromGPS, BufferIndex);
				Action(OutputString, strlen(OutputString));
			}

			for (uint16_t i = 0; i < BufferIndex; i++)
			{
				DataFromGPS[i] = 0;
			}

			for (uint16_t i = 0; i < strlen(MainData); i++)
			{
				MainData[i] = 0;
			}

			BufferIndex = 0;
			IsLastLine = 0;
		}

		else
		{
			DataFromGPS[BufferIndex] = DataFrom_GPS_Module;
			BufferIndex++;
		}

		if (GPS_Module_Status == Start)
		{
			HAL_UART_Receive_IT(UART_Module, &DataFrom_GPS_Module, 1);
		}
	}
}
