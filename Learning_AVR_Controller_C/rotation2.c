#include<avr/io.h>
#include<util/delay.h>
void main()
{
int i,a=0x01;
DDRD=0XFF;
while(1)
{
PORTD=a;
a=a<<1;
if(a==0x80)
{
PORTD=a;
a=0x01;
}
}
}