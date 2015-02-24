#include<avr/io.h>
#include<util/delay.h>
#include<avr/interrupt.h>
int a=0xff;

ISR(INT0_vect)
{
PORTB=a;
a=~a;
EIFR=0x01;
}

void main()
{
DDRB=0XFF;
EICRA=0X02;
EIMSK=0X01;
sei();
while(1);
}