#include<avr/io.h>
#include<util/delay.h>
void main()
{
int a=0xff;
DDRB=0XFF;
TCCR0=0X03;
TCNT0=0X82;
while(1)
{
while((TIFR&0X01)!=0X01);
TIFR|=0X01;
PORTB=a;
a=~a;
TCNT0=0X82;
}
while(1);
}