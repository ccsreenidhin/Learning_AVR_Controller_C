#include<avr/io.h>
#include<util/delay.h>

void spi_init()
{
	DDRB=(1<<PB3);
	SPCR=(1<<SPE)|(1<<SPR0);
}

unsigned char spi_rx()
{
	
	while(!(SPSR&0X80));
	return(SPDR);
}
void main()
{
	DDRE=0XFF;
	spi_init();
	while(1)
	{
		PORTE=spi_rx();
	}
}