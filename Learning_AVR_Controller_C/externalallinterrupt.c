#include<avr/io.h>
#include<util/delay.h>
#include<avr/interrupt.h>
int a=0xff;

ISR(INT0_vect)
{
PORTB=0XFF;
EIFR=0x01;
}

ISR(INT1_vect)
{
PORTB=0X00;
EIFR=0x02;
}

ISR(INT2_vect)
{
PORTF=0X00;
EIFR=0x04;
}

ISR(INT3_vect)
{
PORTF=0XFF;
EIFR=0x08;
}

void main()
{
DDRB=0XFF;
DDRF=0XFF;
EICRA=0XFF;
EICRB=0XFF;
EIMSK=0XFF;
sei();
while(1);
}