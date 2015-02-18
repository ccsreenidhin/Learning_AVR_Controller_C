#include<avr/io.h>
#include<util/delay.h>

void main()
{
int i,a=0x00;
DDRA=0XFF;
while(1)
{
PORTA=a;
_delay_ms(1000);
a=~a;
}
while(1);
}