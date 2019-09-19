/*
* button.c
*
* Created: 2019-09-03 오전 10:34:03
* Author : 6층교수실PC
*/
#include "auto.h"
 
void AutoTraffic(uint8_t *eTrafficState)
{
	switch(*eTrafficState)
	{
		case VRHG:
		SetTrafficLED((1<<V_RED) | (1<<H_GREEN));
		if (Delay(1000))
		{
			SetTrafficState(VRHY);
		}
		break;
		
		case VRHY:
		SetTrafficLED((1<<V_RED) | (1<<H_YELLOW));
		if (Delay(500))
		{
			SetTrafficState(VGHR);
		}
		break;
		
		case VGHR:
		SetTrafficLED((1<<V_GREEN) | (1<<H_RED));
		if (Delay(1000))
		{
			SetTrafficState(VYHR);
		}
		break;
		
		case VYHR:
		SetTrafficLED((1<<V_YELLOW) | (1<<H_RED));
		if (Delay(500))
		{
			SetTrafficState(VRHG);
		}
		break;
	}
}


