#include<avr/io.h>
#include<util/delay.h>
#include<string.h>
void main()
{
DDRD=0XFF;
DDRE=0XFF;
while(1)
{
ADMUX=0X01;
ADCSRA=0XC3;
while((ADCSRA&0X10)!=0x10);
ADCSRA|=0X10;
PORTD=ADCL;
PORTE=ADCH;
}
}