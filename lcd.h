#include <reg51.h>
#define lcd P0
sbit rs =P2^7;
sbit rw = P2^6;
sbit en = P2^5;
sbit bf=P0^7;


void delay(unsigned int itime)
{
unsigned int i,j;
for(i=0;i<itime;i++)
for(j=0;j<1275;j++);
}
 
void port()
{
  P0=0x00;
	P1=0x00;
	P2=0x00;
	P3=0xFF;
}
void ready()
		{
			bf=1;
			rs=0;
			rw=1;
			god:
			en=0;
			en=1;
			while(bf)
			goto god;
		}
		void lcd_com (char ll)
		{
			ready();
		lcd =ll;
		 en = 1;
		rs = 0;
		rw = 0;
		en = 0;
		}
		
		void lcd_data (char lll)
		{
			ready();
			lcd = lll;
			en = 1;
			rs = 1;
			rw = 0;
			en = 0;		
		}
			
		
		
		void lcd_initial()
{
	lcd_com (0x38);   
	lcd_com(0x0F);
  lcd_com (0x06);    
	lcd_com(0x01);
	lcd_com(0x1C);     /*ROTATE*/

}
		
	void lcd_string(char *c)
{
		while(*c!='\0') /*or while(*c)*/

	lcd_data(*c++);
			}
	

		
		