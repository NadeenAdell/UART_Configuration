/*
 * HLCD_init.h
 *
 * Created: 3/27/2023 11:35:12 AM
 *  Author: Peter
 */ 


#ifndef HLCD_INIT_H_
#define HLCD_INIT_H_
////////////////////////////////////////////////INCLUDES///////////////////////////////////
#include "HLCD_cfg.h"




///////////////////////////////////////////////////Protype//////////////////////////////////
void HLCD_Void_Init(void);
void HLCD_Void_WirteCommand(u8 Copy_u8Cmd);
void HLCD_Void_WriteChar(u8 Copy_u8Char);
void HLCD_Void_WrireString(u8 *pstr);
void HLCD_Void_ClearLCD(void);
void HLCD_Void_Write_Num(s32 Copy_S32_Number);
void HLCD_Void_GenerateSpecialChar(u8 *pattern , u8 Location , u8 row , u8 col);
void HLCD_Void_GoTo(u8 Row , u8 Col);


#endif /* HLCD_INIT_H_ */