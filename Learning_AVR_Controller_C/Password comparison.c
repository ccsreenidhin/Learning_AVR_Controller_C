#include<avr\io.h>
#include<util\delay.h>
#include<string.h>
char u0getc(void);
void u0puts(char *);
void u0putc(char);
void main()
{
	int i,d1=0,d2=0,d3=0,d4=0;
	char a[20]="123",b[20]="456",c[20]="789",d[20]="0AB",p[20];
	DDRA=0XFF;
	UCSR0B=0X18;
	UBRR0L=103;
	while(1)
	{
		u0puts("ENTER THE PASSWORD\n\r");
		i=0;
		while(1)
		{
			p[i]=u0getc();
			if(p[i]==13)
				break;
			i++;
		}
		p[i]=0;
		u0puts(p);
		u0puts("\n\r");
		if (strcmp(a,p)==0)
		{
			d1=(1&(~d1));
			
			PORTA=d1|d2|d3|d4;
			
			
		}
		if (strcmp(b,p)==0)
		{
			d2=(2&(~d2));
			PORTA=d1|d2|d3|d4;
			
			
		}
		
		if (strcmp(c,p)==0)
		{
			d3=(4&(~d3));
			PORTA=d1|d2|d3|d4;
			
			
		}
	
		if (strcmp(d,p)==0)
		{
			d4=(8&(~d4));
			PORTA=d1|d2|d3|d4;
			
			
		}
		
		
		
		
		
	}
}
char u0getc()
{
	char ch;
	while(!(UCSR0A&0X80));
	ch=UDR0;
	return ch;
}
void u0puts(char *q)
{
	while(*q)
	u0putc(*q++);
}
void u0putc(char w)
{
	UDR0=w;
	while(!(UCSR0A&0X20));
	
}
	