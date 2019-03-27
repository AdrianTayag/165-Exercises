/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* 																														                                             */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include "NUC1xx.h"
#include "DrvSYS.h"
#include "Driver_PWM.h"
#include "NUC1xx-LB_002\LCD_Driver.h"
#include "ScanKey.h"
#include "music.h"


void delay(void)
{
	int j;
	for(j=0;j<1000;j++);
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

int32_t main (void)
{
  uint8_t i, duty_cycle;



//Enable 12Mhz and set HCLK->12Mhz

	char TEXT2[16]="Tone No.        ";
	char TEXT3[16]="Freq :        Hz";
	int num;

	duty_cycle = 50; // Duty = 50%

	UNLOCKREG();
	SYSCLK->PWRCON.XTL12M_EN = 1;
	SYSCLK->CLKSEL0.HCLK_S = 0;
	LOCKREG();

	Initial_panel();
	clr_all_panel();

 	print_lcd(0, "***   Tada!   ***");
	InitPWM(0); // initialize PWM0, output pin = GPA12

	OpenKeyPad();
	num = 0;
	while(1)
	{
		while(num == 0){
			num = Scankey();
		}

		if(num == 1){
			clr_all_panel();
			num = 0;
			for (i=0; i<17; i++) {
					PWM_Freq(0, tone[i],duty_cycle); // set PWM0 with frequency & duty cycle
					sprintf(TEXT2+9,"%d",i);
					sprintf(TEXT3+7,"%d",tone[i]);
					print_lcd(0, "***   Fun!   ***");
					print_lcd(1, "*** Snowman  ***");
					print_lcd(2, TEXT2);
					print_lcd(3, TEXT3);
					DrvSYS_Delay(length[i]); // delay between each note
					clr_all_panel();
			}
				while(num == 0){
					num = Scankey();
					print_lcd(0, "***   Fun!   ***");
				}
		}
		else if(num == 2){
			clr_all_panel();
			num = 0;
				for (i=0; i<30; i++) {
					PWM_Freq(0, tone2[i],duty_cycle); // set PWM0 with frequency & duty cycle
					sprintf(TEXT2+9,"%d",i);
					sprintf(TEXT3+7,"%d",tone2[i]);
					print_lcd(0, "***   Fun!   ***");
					print_lcd(1, "***Let it go ***");
					print_lcd(2, TEXT2);
					print_lcd(3, TEXT3);
					DrvSYS_Delay(length2[i]); // delay between each note
					clr_all_panel();
				}
				while(num == 0){
					num = Scankey();
					print_lcd(0, "***   Fun!   ***");
				}
		}

		else if(num == 3){
			clr_all_panel();
			num = 0;
				for (i=0; i<63; i++) {
					PWM_Freq(0, tone3[i],duty_cycle); // set PWM0 with frequency & duty cycle
					sprintf(TEXT2+9,"%d",i);
					sprintf(TEXT3+7,"%d",tone3[i]);
					print_lcd(0, "***Kakaibabe ***");
					print_lcd(1, "***  c AAMS  ***");
					print_lcd(2, TEXT2);
					print_lcd(3, TEXT3);
					DrvSYS_Delay(length3[i]); // delay between each note
					clr_all_panel();
				}
				while(num == 0){
					num = Scankey();
					print_lcd(0, "***   Fun!   ***");
				}
		}

		else if(num == 4){
			clr_all_panel();
			num = 0;
				for (i=0; i<90; i++) {
					PWM_Freq(0, tone4[i],duty_cycle); // set PWM0 with frequency & duty cycle
					sprintf(TEXT2+9,"%d",i);
					sprintf(TEXT3+7,"%d",tone4[i]);
					print_lcd(0, "***   Fun!   ***");
					print_lcd(1, "** Little Star**");
					print_lcd(2, TEXT2);
					print_lcd(3, TEXT3);
					DrvSYS_Delay(length2[i]); // delay between each note
					clr_all_panel();
				}
				while(num == 0){
					num = Scankey();
					print_lcd(0, "***   Fun!   ***");
				}
		}
		else if(num == 5){
			clr_all_panel();
			num = 0;
				for (i=0; i<180; i++) {
					PWM_Freq(0, tone5[i],duty_cycle); // set PWM0 with frequency & duty cycle
					sprintf(TEXT2+9,"%d",i);
					sprintf(TEXT3+7,"%d",tone4[i]);
					print_lcd(0, "***   Fun!   ***");
					print_lcd(1, "StairwaytoHeaven");
					print_lcd(2, TEXT2);
					print_lcd(3, TEXT3);
					DrvSYS_Delay(length2[i]); // delay between each note
					clr_all_panel();
				}
				while(num == 0){
					num = Scankey();
					print_lcd(0, "***   Fun!   ***");
				}
		}
		// fix for nuvoton looping when numpad input is out of bounds.
		else if(num > 5){
			while(num == 0){
				num = Scankey();
				print_lcd(0, "***   Fun!   ***");
			}
		}
}
}
