#include<avr/io.h>
#include<util/delay.h>

void main()
{
int i,a=0x00;
char b[10]="welcome";
UBRR0L=0x19;
UCSR0B=0X18;

for(i=0;i<7;i++)
{
EEAR=a;
while(EECR&0x02!=0X02);
EEDR=b[i];
EECR|=0X04;
EECR|=0X02;
a=a++;
}
_delay_ms(30);
a=0x00;
for(i=0;i<7;i++)
{
EEAR=a;
while(EECR&0x02!=0X02);
EECR|=0X01;

while((UCSR0A&0x40)!=0X40);
UCSR0A|=0X40;
UDR0=EEDR;
a=a++;
}

while(1);
}
