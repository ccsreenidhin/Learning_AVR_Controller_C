#include<avr/io.h>
#include<util/delay.h>
void main()
{
int a=0xff;
DDRA=0XFF;
DDRB=0XFE;
while(1)
{
while(PINB!=0X01);
while(PINB!=0X00);
PORTA=a;
a=~a;
}
}