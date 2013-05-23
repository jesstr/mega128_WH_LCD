/*
 * mega128_nRF24L01.c
 *
 * Created: 17.07.2012 11:26:44
 *  Author: Черствов
 */ 
#define F_CPU 16000000

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "spi.h"
#include "wh_lcd.h"


char *IntToStr(int value, int radix)
{
char buffer[8];
char *ptr;
ptr = itoa(value, buffer, radix);
return ptr;
}


ISR(INT0_vect)
{
	unsigned char buff, i=0;
	SPI_CS1_LOW;
	buff=SPI_ReceiveByte_Master(); //чтение статусного регистра
	SPI_CS1_HIGH;
}


int main(void)
{
	unsigned char count, rx_buff; 
	
	InitLcd();
	SPI_Init_Slave();
 	LcdWriteString("HELLO");
	
    while(1)
    {
		rx_buff=SPI_ReceiveByte_Slave();
		LcdWriteCom(FIRST_STRING);
		LcdWriteString("        ");
		LcdWriteCom(FIRST_STRING);
		LcdWriteString("Rx: ");
		LcdWriteString(IntToStr(rx_buff,16));		
    }
	*/
}