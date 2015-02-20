#include<avr/io.h>
#include<util/delay.h>
void main()
{
int a,b;
DDRD=0XFF;
DDRE=0XFF;
DDRB=0XFF;
while(1)
{
ADMUX=0X21;
ADCSRA=0XC3;
while((ADCSRA&0X10)!=0x10);
ADCSRA|=0X10;
b=ADCL;
a=ADCH;
if(a<64)
{
PORTB=0X01;
}
else if(a<128)
{
PORTB=0X02;
}
else if(a<192)
{
PORTB=0X04;
}
else
{
PORTB=0X08;
}
}
}