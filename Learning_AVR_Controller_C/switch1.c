#include<avr/io.h>
#include<util/delay.h>

void main()
{
DDRA=0XFF;
DDRB=0XFE;
while(1)
{
while(PINB!=0x01);
PORTA=0XFF;             //switch on
while(PINB!=0X00);
PORTA=0X00;            //switch off
}
}