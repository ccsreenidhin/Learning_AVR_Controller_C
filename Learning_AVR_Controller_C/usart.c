#include<avr/io.h>
#include<util/delay.h>

void main()
{
int i;
char a[10]="pass";
UBRR0L=0x19;
UCSR0B=0X08;
for(i=0;i<10;i++)
{
UDR0=a[i];
while(UCSR0A!=0X60);
}
while(1);
}