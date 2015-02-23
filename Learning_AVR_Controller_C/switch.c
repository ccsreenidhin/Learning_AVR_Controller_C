#include<avr/io.h>
#include<util/delay.h>
void main()
{
DDRA=0XFF;
DDRE=0XFC;
int m,a=0x01,b=0x80;
while(1)
{

m=PINE;
switch (m)
{
case 0x00:
PORTA=0X00;
a=0x01;
b=0x80;
break;

case 0x01:
PORTA=a;
a=a<<1;
if(a==0x80)
{
PORTA=a;
a=0x01;
}
b=0x80;
break;

case 0x02:
PORTA=b;
b=b>>1;
if(b==0x01)
{
PORTA=b;
b=0x80;
}
a=0x01;
break;

case 0x03:
PORTA=0XFF;
a=0x01;
b=0x80;
break;
}
}
}