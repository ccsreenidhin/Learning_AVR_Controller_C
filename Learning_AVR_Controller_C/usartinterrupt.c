#include<avr/io.h>
#include<util/delay.h>
#include<avr/interrupt.h>
int a=0xff;
ISR(USART0_TX_vect)
{
PORTB=a;
a=~a;
UCSR0A=0X40;
}

void main()
{
UCSR0B=0X48;
UBRR0L=0X19;
sei();
UDR0='H';
while(1);
}