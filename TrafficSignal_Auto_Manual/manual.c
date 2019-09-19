/*
* manual.c
*
* Created: 2019-09-03 오후 2:33:07
*  Author: 6층교수실PC
*/

#include "manual.h"

void ManualTraffic(uint8_t *eTrafficState)
{
	if ( GetTrafficSignalButtonState())
	{
		uint8_t traffic = GetTrafficState() + 1;
		
		if (traffic == 4)
		{
			SetTrafficState(VRHG);
		}
		else
		{
			SetTrafficState(traffic);
		}
	}
	
	switch(*eTrafficState)
	{
		case VRHG:
		SetTrafficLED((1<<V_RED) | (1<<H_GREEN));
		break;
		
		case VRHY:
		SetTrafficLED((1<<V_RED) | (1<<H_YELLOW));
		break;
		
		case VGHR:
		SetTrafficLED((1<<V_GREEN) | (1<<H_RED));
		break;
		
		case VYHR:
		SetTrafficLED((1<<V_YELLOW) | (1<<H_RED));
		break;
	}
}


