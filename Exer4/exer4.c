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
#include "LCD_Driver.h"

#define DELAY DrvSYS_Delay(300000)

#define Blue DrvGPIO_Open(E_GPA, 12, E_IO_OUTPUT)
#define Green DrvGPIO_Open(E_GPA, 13, E_IO_OUTPUT)
#define Red DrvGPIO_Open(E_GPA, 14, E_IO_OUTPUT)
#define Buzzer DrvGPIO_Open(E_GPB, 11, E_IO_OUTPUT)

#define BlueOff DrvGPIO_SetBit(E_GPA, 12)
#define GreenOff DrvGPIO_SetBit(E_GPA, 13)
#define RedOff DrvGPIO_SetBit(E_GPA, 14)
#define buzzerOff DrvGPIO_SetBit(E_GPB, 11)

#define BlueOn DrvGPIO_ClrBit(E_GPA, 12)
#define GreenOn DrvGPIO_ClrBit(E_GPA, 13)
#define RedOn DrvGPIO_ClrBit(E_GPA, 14)
#define buzzerOn DrvGPIO_ClrBit(E_GPB, 11)


int main(void){
	char txt1[20], txt2[20], txt3[20], txt4[20];
	UNLOCKREG();
	DrvSYS_Open(48000000);
	LOCKREG();
	DrvGPIO_Open(E_GPB,11, E_IO_OUTPUT);
	Initial_panel();
	clr_all_panel();
	
	while(1){			
		uint8_t i;
		
		//Red
		sprintf(txt1, " TRAFFIC  LIGHT");
		sprintf(txt4, "****************");
		sprintf(txt2, "      Red");
		RedOn;
		for(i=10;i>0;i--){
			print_lcd(1, txt2);
			sprintf(txt3, "...... %d ......", i);
			print_lcd(2, txt3);
			print_lcd(0, txt1);
			print_lcd(3, txt4);
			DELAY;
			DELAY;
			DELAY;
			DELAY;
			clr_all_panel();
			}

		//Green
		sprintf(txt2, "     Green");	
		RedOff;
		GreenOn;
		for(i=20;i>0;i--){
			print_lcd(1, txt2);
			sprintf(txt3, "...... %d ......", i);
			print_lcd(2, txt3);
			print_lcd(0, txt1);
			print_lcd(3, txt4);
			DELAY;
			DELAY;
			DELAY;
			DELAY;
			clr_all_panel();
			}
		clr_all_panel();		
			
		//Yellow
		sprintf(txt2, "     Yellow");
		RedOn;
		for(i=5;i>0;i--){
			print_lcd(1, txt2);
			sprintf(txt3, "...... %d ......", i);
			print_lcd(2, txt3);
			print_lcd(0, txt1);
			print_lcd(3, txt4);
			buzzerOn;
			DELAY;
			buzzerOff;
			DELAY;
			DELAY;
			DELAY;
			clr_all_panel();
			}
		RedOff;
		GreenOff;
	}
	
}
