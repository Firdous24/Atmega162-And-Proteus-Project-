/*
 * main.c
 *
 * Created: 8/12/2021 9:32:39 PM
 *  Author: Hp
 * CS-18141
 */ 

#include <avr/io.h>
#define F_CPU 1000000UL
#include<util/delay.h>
int main(void)
{
	DDRD&=~(1<<PD0);
	DDRD|=(1<<PD1);
	DDRA=0xFF;
	DDRC=0xFF;
	//int UBRR_Value=25;
	//UBRR0H=(unsigned char)(UBRR_Value>>8);
	//UBRR0L=(unsigned char)UBRR_Value;
	UBRR0H=0x00;
	UBRR0L=0x05;
	UCSR0B=(1<<RXEN0);
	UCSR0C=(1<<USBS0)|(3<<UCSZ00);
	unsigned char receiveData;
	while(1)
	{ PORTC=0;
		receiveData=0;
		while(!(UCSR0A&(1<<RXC0)));
		receiveData=UDR0;
		PORTC=receiveData;
		if(receiveData==0b11110000)
		{
			PORTA^=(1<<PA0);
			_delay_ms(1000);
		}
	}
}