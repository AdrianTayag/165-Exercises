/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* 																														                                             */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include "NUC1xx.h"
#include "Driver\DrvSYS.h"
#include "Driver\DrvGPIO.h"
#include "Driver\DrvUART.h"
#include "Seven_Segment.h"
#include "ScanKey.h"

#define init_led0 DrvGPIO_Open(E_GPC, 12, E_IO_OUTPUT)
#define init_led1 DrvGPIO_Open(E_GPC, 13, E_IO_OUTPUT)
#define init_led2 DrvGPIO_Open(E_GPC, 14, E_IO_OUTPUT)
#define init_led3 DrvGPIO_Open(E_GPC, 15, E_IO_OUTPUT)


#define led0_ON DrvGPIO_ClrBit(E_GPC, 12)
#define led1_ON DrvGPIO_ClrBit(E_GPC, 13)
#define led2_ON DrvGPIO_ClrBit(E_GPC, 14)
#define led3_ON DrvGPIO_ClrBit(E_GPC, 15)
#define led0_OFF DrvGPIO_SetBit(E_GPC, 12)
#define led1_OFF DrvGPIO_SetBit(E_GPC, 13)
#define led2_OFF DrvGPIO_SetBit(E_GPC, 14)
#define led3_OFF DrvGPIO_SetBit(E_GPC, 15)

#define DELAY DrvSYS_Delay(300000)

void delay(void)
{
	int j;
	for(j=0;j<1000;j++);
}


void init_LED(){
	
	init_led0;
	init_led1;
	init_led2;
	init_led3;
	
	led0_OFF;
	led1_OFF;
	led2_OFF;
	led3_OFF;
	
	close_seven_segment();

}

void OpenKeyPad(void){
	
	uint8_t i;
	
	for(i = 0; i < 6; i++) 
	DrvGPIO_Open(E_GPA, i, E_IO_QUASI);
}

uint8_t Scankey(void){
	
	uint8_t act[4]={0x3b, 0x3d, 0x3e};    
	uint8_t i,temp,pin;

	for(i=0;i<3;i++)
	{
		temp=act[i];
		for(pin=0;pin<6;pin++)
		{
			if((temp&0x01)==0x01)
				DrvGPIO_SetBit(E_GPA,pin);
			else
				DrvGPIO_ClrBit(E_GPA,pin);
			temp>>=1;
		}
		delay();
		if(DrvGPIO_GetBit(E_GPA,3)==0)
			return(i+1);
		if(DrvGPIO_GetBit(E_GPA,4)==0)
			return(i+4);
		if(DrvGPIO_GetBit(E_GPA,5)==0)
			return(i+7);
	}
		return 0;

}


int main(void){
	
	int8_t num, i, counter;
	counter = 3;
	UNLOCKREG();
	DrvSYS_Open(48000000);
	LOCKREG();
	
	init_LED();
	
	OpenKeyPad();
	while(1){

//LED 5,6,7,8
		num = 0;
		while(num == 0){
			num = Scankey();
			counter = 3;
		}
		for(i=num; i>=0; i--){
			if (counter <0){
				counter = 3;
				}
			show_seven_segment(counter,i);
			DELAY;
			close_seven_segment();
			counter = counter-1;
			}
	
		
		
		/*led0_ON;
		show_seven_segment(3,num);
		DELAY;
		led0_OFF;
		close_seven_segment();
		DELAY;
		led1_ON;
		show_seven_segment(2,num);
		DELAY;
		led1_OFF;
		close_seven_segment();
		DELAY;
		led2_ON;
		show_seven_segment(1,num);
		DELAY;
		led2_OFF;
		close_seven_segment();
		DELAY;
		led3_ON;
		show_seven_segment(0,num);
		DELAY;
		led3_OFF;
		close_seven_segment();
		DELAY;*/
		
		
	}
}