#include<avr/io.h>
#include<util/delay.h>
#include<avr/interrupt.h>
int a=0xff;
ISR(TIMER0_OVF_vect)
{
PORTB=a;
a=~a;
TCNT0=0X82;
TIFR|=0X01;
}
void main()
{

DDRB=0XFF;
TCCR0=0X03;
TCNT0=0X82;
TIMSK=0X01;
sei();
while(1);
}