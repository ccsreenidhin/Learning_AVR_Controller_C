#include<avr/io.h>
#include<util/delay.h>

void main()
{
UBRR0L=0x19;
UCSR0B=0X18;


EEAR=0X00;
while(EECR&0x02!=0X02);
EEDR='j';
EECR|=0X04;
EECR|=0X02;
_delay_ms(30);
EEAR=0X00;
while(EECR&0x02!=0X02);
EECR|=0X01;

while((UCSR0A&0x40)!=0X40);
UCSR0A|=0X40;
UDR0=EEDR;

while(1);
}
