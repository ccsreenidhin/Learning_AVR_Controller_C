#include<avr/io.h>
#include<util/delay.h>
void main()
{
int i,a=0x01;
DDRA=0XFF;
while(1)
{
PORTA=a;
a=a<<1;
_delay_ms(500);
if(a==0x80)
{
PORTA=a;
a=0x01;
}
}
}