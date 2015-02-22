#include<avr/io.h>
#include<util/delay.h>

void main()
{
	DDRD=0XFF;
	PORTD=0XFF;
	while(1);
}