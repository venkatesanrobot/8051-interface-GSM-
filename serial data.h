#include<reg51.h>
#include<stdio.h>

void serial();
void tx( char Q);
void str(char *F);

void serial()
 {
TMOD = 0x20 ;	    
SCON = 0x50 ; 
TH1 =  0xFD ; 				
TR1 = 1 ;	
}  
 void str(char *F)
{
	while(*F!='\0') 
	tx(*F++);
			}

void tx( char Q)
{
SBUF = Q; 
while(!TI); 
TI = 0; 
}
