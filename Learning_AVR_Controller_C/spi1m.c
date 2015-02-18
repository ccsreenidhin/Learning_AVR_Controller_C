#include<avr/io.h>
#include<util/delay.h>
int a=0x01;
void spi_init()
{
	DDRB=(1<<PB0)|(1<<PB1)|(1<<PB2);//0x07
	SPCR=(1<<SPE)|(1<<MSTR)|(1<<SPR0);
	PORTB|=(1<<0);
}

void spi_tx(int c)
{
	PORTB&=~(1<<0);
	SPDR=c;
	while(!(SPSR&0X80));
	PORTB|=(1<<0);
}
void main()
{
	spi_init();
	while(1)
	{
	spi_tx(a);
	a=a<<1;
	_delay_ms(30);
	if(a==0x80)
	{
	a=0x01;
	}
	}
}	

