#include "ILI9341.h"
#include "STM32F4_Driver.h"


//Функция инициализации дисплея
void DisplayDriver_Init(DisplayOrientation Orientation)
{
	SendCommand(LCD_SWRESET);


	SendCommand(LCD_POWERA);

	DataBuffer[0] = 0x39;
	DataBuffer[1] = 0x2C;
	DataBuffer[2] = 0x00;
	DataBuffer[3] = 0x34;
	DataBuffer[4] = 0x02;
	SendData(DataBuffer, 5);



	SendCommand(LCD_POWERB);

	DataBuffer[0] = 0x00;
	DataBuffer[1] = 0xC1;
	DataBuffer[2] = 0x30;
	SendData(DataBuffer, 3);



	SendCommand(LCD_DTCA);

	DataBuffer[0] = 0x85;
	DataBuffer[1] = 0x00;
	DataBuffer[2] = 0x78;
	SendData(DataBuffer, 3);



	SendCommand(LCD_DTCB);

	DataBuffer[0] = 0x00;
	DataBuffer[1] = 0x00;
	SendData(DataBuffer, 2);



	SendCommand(LCD_POWER_SEQ);

	DataBuffer[0] = 0x64;
	DataBuffer[1] = 0x03;
	DataBuffer[2] = 0x12;
	DataBuffer[3] = 0x81;
	SendData(DataBuffer, 4);



	SendCommand(LCD_PRC);

	DataBuffer[0] = 0x20;
	SendData(DataBuffer, 1);



	SendCommand(LCD_POWER1);

	DataBuffer[0] = 0x26;
	SendData(DataBuffer, 1);



	SendCommand(LCD_POWER2);

	DataBuffer[0] = 0x11;
	SendData(DataBuffer, 1);



	SendCommand(LCD_VCOM1);

	DataBuffer[0] = 0x3E;
	DataBuffer[1] = 0x28;
	SendData(DataBuffer, 2);



	SendCommand(LCD_VCOM2);

	DataBuffer[0] = 0x86;
	SendData(DataBuffer, 1);



	Display_SetOrientation(Orientation);



	SendCommand(LCD_PIXEL_FORMAT);

	DataBuffer[0] = 0x55;
	SendData(DataBuffer, 1);



	SendCommand(LCD_FRMCTR1);

	DataBuffer[0] = 0x00;
	DataBuffer[1] = 0x18;
	SendData(DataBuffer, 2);



	SendCommand(LCD_DFC);

	DataBuffer[0] = 0x08;
	DataBuffer[1] = 0x82;
	DataBuffer[2] = 0x27;
	SendData(DataBuffer, 3);



	SendCommand(LCD_3GAMMA_EN);

	DataBuffer[0] = 0x08;
	SendData(DataBuffer, 1);



	SendCommand(LCD_COLUMN_ADDR);

	DataBuffer[0] = 0x00;
	DataBuffer[1] = 0x00;
	DataBuffer[2] = 0x00;
	DataBuffer[3] = 239;
	SendData(DataBuffer, 4);




	SendCommand(LCD_PAGE_ADDR);

	DataBuffer[0] = 0x00;
	DataBuffer[1] = 0x00;
	DataBuffer[2] = 0x00;
	DataBuffer[3] = 320;
	SendData(DataBuffer, 4);



	SendCommand(LCD_GAMMA);

	DataBuffer[0] = 0x01;
	SendData(DataBuffer, 1);



	SendCommand(LCD_PGAMMA);

	DataBuffer[0] = 0x0F;
	DataBuffer[1] = 0x31;
	DataBuffer[2] = 0x2B;
	DataBuffer[3] = 0x0C;
	DataBuffer[4] = 0x0E;
	DataBuffer[5] = 0x08;
	DataBuffer[6] = 0x4E;
	DataBuffer[7] = 0xF1;
	DataBuffer[8] = 0x37;
	DataBuffer[9] = 0x07;
	DataBuffer[10] = 0x10;
	DataBuffer[11] = 0x03;
	DataBuffer[12] = 0x0E;
	DataBuffer[13] = 0x09;
	DataBuffer[14] = 0x00;
	SendData(DataBuffer, 15);



	SendCommand(LCD_NGAMMA);

	DataBuffer[0] = 0x00;
	DataBuffer[1] = 0x0E;
	DataBuffer[2] = 0x14;
	DataBuffer[3] = 0x03;
	DataBuffer[4] = 0x11;
	DataBuffer[5] = 0x07;
	DataBuffer[6] = 0x31;
	DataBuffer[7] = 0xC1;
	DataBuffer[8] = 0x48;
	DataBuffer[9] = 0x08;
	DataBuffer[10] = 0x0F;
	DataBuffer[11] = 0x0C;
	DataBuffer[12] = 0x31;
	DataBuffer[13] = 0x36;
	DataBuffer[14] = 0x0F;
	SendData(DataBuffer, 15);



	SendCommand(LCD_SLEEP_OUT);

	HAL_Delay(100);

	SendCommand(LCD_DISPLAY_ON);

	SendCommand(LCD_GRAM);
}

void Display_Backlight_On(GPIO_TypeDef* Backlight_GPIO, uint16_t Backlight_Pin)
{
	Backlight_GPIO->BSRR = Backlight_Pin;
}

void Display_Backlight_Off(GPIO_TypeDef* Backlight_GPIO, uint16_t Backlight_Pin)
{
	Backlight_GPIO->BSRR = Backlight_Pin << 16;
}
