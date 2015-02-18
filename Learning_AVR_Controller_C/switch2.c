#include<avr/io.h>
#include<util/delay.h>
void main()
{
int i,a=0xff,b=0x01;
DDRE=0XFE;
DDRD=0XFF;
while(1)
{
if(PINE==b)
{
while(1)
{
PORTD=a;
if(PINE==0X00)
{
PORTD=0X00;
while(PINE!=b);
}
}
}
}
while(1);
}