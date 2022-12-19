#include <ILI9341_Driver.h>

uint16_t DataBuffer[19200] = {0};


//Функция отправки команды дисплею
void SendCommand(uint16_t Command)
{
	FCMS_Send_COM(Command);
}


//Функция отправки данных дисплею
void SendData(uint16_t* Data, uint16_t DataSize)
{
	for(uint16_t i = 0; i < DataSize; i++)
	{
		FCMS_Send_DATA(Data[i]);
	}
}

