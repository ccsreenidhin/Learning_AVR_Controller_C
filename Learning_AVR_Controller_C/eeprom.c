#include<avr/io.h>
#include<util/delay.h>

void main()
{
EEAR=0X00;
while(EECR&0x02!=0X02);
EEDR='H';
EECR|=0X04;
EECR|=0X02;
while(1);
}

