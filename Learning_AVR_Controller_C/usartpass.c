#include<avr/io.h>
#include<util/delay.h>
#include<string.h>

void main()
{
 int i,c;
 char m[10]="123",b[10],f[20]=" access granted",g[20]="access denied ",ch;
 char e[20]="enter the password";
 DDRD=0XFF;
 UBRR0L=95;
 UCSR0B=0X18;

 while(1)
  {
   for(i=0;i<20;i++) 
     {
     UDR0=e[i];
     while((UCSR0A&0x40)!=0X40);
     UCSR0A|=0X40;
     }
  for(i=0;i<9;i++)
   {
    while((UCSR0A&0X80)!=0x80);
    UCSR0A|=0X80;
	ch=UDR0;
	if(ch==13)
     {
     break;
     }
    b[i]=ch;
    UDR0='*';
     while((UCSR0A&0x40)!=0X40);
     UCSR0A|=0X40;
  }
  b[i]='\0';
  
  for(i=0;b[i]!='\0';i++)
  {
	UDR0=b[i];
	while((UCSR0A&0x40)!=0X40);
    UCSR0A|=0X40;
  }
  
 c=strcmp(m,b);
 if(c==0)
  {
    for(i=0;i<16;i++)
     {
       UDR0=f[i];
       while((UCSR0A&0x40)!=0X40);
       UCSR0A|=0X40;
     }
   while(1);
  }
 else
  {
    for(i=0;i<15;i++)
    {
     UDR0=g[i];
     while((UCSR0A&0x40)!=0X40);
     UCSR0A|=0X40;
    }
  }
 }
}