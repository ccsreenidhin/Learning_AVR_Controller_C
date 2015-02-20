#include<avr/io.h>
#include<util/delay.h>
void main()
{
DDRD=0XFF;
DDRE=0XFC;
int m,a=0x01,b=0x80;
while(1)
{

m=PINE;
switch (m)
{
case 0x00:
PORTD=0X00;
a=0x01;
b=0x80;
break;

case 0x01:
PORTD=a;
a=a<<1;
if(a==0x80)
{
PORTD=a;
a=0x01;
}
b=0x80;
break;

case 0x02:
PORTD=b;
b=b>>1;
if(b==0x01)
{
PORTD=b;
b=0x80;
}
a=0x01;
break;

case 0x03:
PORTD=0XFF;
a=0x01;
b=0x80;
break;
}
}
}