/*
 * main.c
 *
 * Created: 9/6/2021 4:16:01 PM
 *  Author: Hp
 * CS-18141 and CS-18143 G2
 */ 



#include <avr/io.h>
#define F_CPU 1000000UL
#include <util/delay.h>
int GetKeyPressed(void);
int key1, key2, key3, key4;
int main(void)
{	char 
	password[4]={5,2,3,4};
	char
	digit[20]={0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08, 0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F};
	DDRD=0xF0;
	DDRA=0xFF;
	DDRC=0x00;
	DDRB=(1<<PINB1);
	
	char p1, p2, p3, p4, swch, i;
	//PORTA=digit[16];
	PORTA=0b11000110;
	while(1)
	{
		//TODO:: Please write your application code
			//PORTA=0b11000110;
			swch = PINC&0b00000010;
			if (PORTA==0b11000000 & swch==0){
				PORTA=0b11000110;
			}
			
		
		    //for(i=0;i<4;i++){
				//PORTA=0b10000000;
			key1=GetKeyPressed();
				//password[i]=key1;
			//}
				/*_delay_ms(500);
				PORTA=0b00000000;
				key2= GetKeyPressed();
			
				_delay_ms(500);
				PORTA=0b10000000;
				key3= GetKeyPressed();
				_delay_ms(500);
				PORTA=0b00000000;
				key4= GetKeyPressed();
				//_delay_ms(400);*/
			if(key1!=16)// & key2!=16 & key3!=16 & key4!=16)
				{
					//p1=digit[password[0]];//+digit[key2]+digit[key3]+digit[key4];
					//p2=digit[password[1]];
					//p3=digit[password[2]];
					//p4=digit[password[3]];
				
					if (digit[key1]==password[0] )//&& digit[key2]==password[1] && digit[key3]==password[2] && digit[key4]==password[3])//p1==2 && p2==3 && p3==4 && p4==5)// & p2==0x03 & p3==0x04 & p4==0x05)
					{
						PORTA=0b11000000;
						
					}
					else{
						PORTA=0b11000110;
						}
				}
			//}
					/*key2= GetKeyPressed();
					if(key2!=16)
					{
						p2=digit[key2];
						if (p2==0x03){
							key3= GetKeyPressed();
							if(key3!=16)
							{
								p3=digit[key3];
								if (p3==0x04){
									key4= GetKeyPressed();
									if(key4!=16)
									{
										p4=digit[key4];
										if (p4==0x05){
											PORTA=0b11000000;
												
										}
										else{
											PORTA=0b11000110;
										}
										}
									}
								}
							}
						}*/
					
					//p2=digit[key2];
					//p3=digit[key3];
					//p4=digit[key4];
				
			
					/*if (p1==0x02 & p2==0x03 & p3==0x04 & p4==0x05){
						PORTA=0b11000000;
					
					}
					else{
						PORTA=0b11000110;
					}*/
				
			
		
	}
}
int GetKeyPressed(void)
{
	char x;
	PORTB=0x00;
	int data =0;
	//while(data<4){
	x=PINC;
	if(x==0x03)
		{
			//if(data == 0){
			key1=(PIND&0x0F);
			return key1;
			/*}
			if(data == 1){
				key2=(PIND&0x0F);
				return key2;
			}
			if(data == 2){
				key3=(PIND&0x0F);
				return key3;
			}
			if(data == 3){
				key4=(PIND&0x0F);
				return key4;
			}*/
		}
		//data=data+1;
		return 16;
//}
}