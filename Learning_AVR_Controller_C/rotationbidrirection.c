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
_delay_ms(100);
if(a==0x80)
{
PORTA=a;
while(1)
{
a=a>>1;
_delay_ms(100);
if(a==0x01)
{
break;
}
}
}
}
}