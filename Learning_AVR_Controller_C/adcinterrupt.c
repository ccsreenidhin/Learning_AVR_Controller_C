#include<avr/io.h>
#include<util/delay.h>
#include<avr/interrupt.h>

ISR(ADC_vect)
{
PORTD=ADCL;
PORTE=ADCH;
ADCSRA|=0X10;
ADCSRA|=0X40;
}
void main()
{
DDRD=0XFF;
DDRE=0XFF;
ADCSRA=0XCB;
ADMUX=0X01;
sei();
while(1);
}