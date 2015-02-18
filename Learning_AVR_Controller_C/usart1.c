#include<avr/io.h>
#include<util/delay.h>

void main()
{
int a,b;
DDRD=0XFF;
UBRR0L=0x19;
UCSR0B=0X18;
while(1)
{
while((UCSR0A&0X80)!=0x80);
UCSR0A|=0X80;
b=UDR0;
while((UCSR0A&0x40)!=0X40);
UCSR0A|=0X40;
UDR0=b;
PORTD=UDR0;
}

}