/*
 * main.c
 *
 * Created: 8/12/2021 9:29:49 PM
 *  Author: Hp
 * CS-18141
 */ 
#include <avr/io.h>
#define F_CPU 1000000UL
#include<util/delay.h>
int main(void)
{
	DDRD|=1<<PD1;
	DDRD&=~(1<<PD0);
	PORTD|=1<<PD0;
	DDRA=0x00;
	//int UBBRValue=25;
	UBRR0H=0x00;
	UBRR0L=0x05;
	UCSR0B=(1<<TXEN0);
	UCSR0C=(1<<USBS0)|(3<<UCSZ00);
	char y=0;
	while(1)
	{
		y=PINA&0b00000001;
		if(y==0)
		{
			while(!(UCSR0A&(1<<UDRE0)));
			UDR0=0b11110000;
			_delay_ms(1000);
		}
	}
}