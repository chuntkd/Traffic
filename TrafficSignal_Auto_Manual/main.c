/*
* button.c
*
* Created: 2019-09-03 오전 10:34:03
* Author : rhoblack@naver.com
*/

#include "main.h"

int main(void)
{
	ButtonInit();  // 버튼 입력 설정
	LEDInit(); // LED 출력 설정 
	
	SetTrafficState(VRHG); //  신호를 VRGH로 설정
	SetTrafficMode(TRAFFIC_AUTO); // 기본 모드 자동 
	
	while (1)
	{
		if ( GetTrafficModeButtonState() )  // 모드 변경 버튼 입력
		{
			if (GetTrafficMode() == TRAFFIC_AUTO) // 신호 모드가 자동이면 
			{
				SetTrafficMode(TRAFFIC_MANUAL); // 신호 모드를 수동으로 바꿈
			}
			else
			{
				SetTrafficMode(TRAFFIC_AUTO); // 아니라면 신호 모드 자동으로 바꿈
			}
		}
		
		switch(eTrafficMode) 
		{
			case TRAFFIC_AUTO: // 자동 모드
				AutoTraffic(&eTrafficState); // 자동 신호, 신호등 동작 상태를 그대로 전환하기 위해서 포인터로 지정
				SetAutoModeLED(); // 자동 상태 LED 점등
				break;
			
			case TRAFFIC_MANUAL: //수동모드 
				ManualTraffic(&eTrafficState); // 수동신호
				SetManualModeLED(); // 수동 상태 LED 점등
				break;
		}
		
		_delay_ms(1);
		IncMillis();
	}
}

