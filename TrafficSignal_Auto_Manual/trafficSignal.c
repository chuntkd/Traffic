/*
* button.c
*
* Created: 2019-09-03 오전 10:34:03
* Author : rhoblack@naver.com
*/
#include "trafficSignal.h"
 


void SetTrafficState(uint8_t trafficState) // 신호 단계 설정
{
	eTrafficState = trafficState; //신호 단계 설정
}

void SetTrafficMode(uint8_t trafficMode) //신호 모드 설정
{
	eTrafficMode = trafficMode; // 신호 모드 설정
}

uint8_t GetTrafficState() // 신호 단계 받는 함수
{
	return eTrafficState; // 단계 출력
}

uint8_t GetTrafficMode() // 모드 상태 받는 함수 
{
	return eTrafficMode;
}


void AutoTraffic(uint8_t *eTrafficState) // 자동 상태 동작 
{
	switch(*eTrafficState) // 신호 단계를 받아서 작동 
	{
		case VRHG: 
			SetTrafficLED((1<<V_RED) | (1<<H_GREEN)); // 세로 빨간불, 가로 초록불 점등
			if (Delay(5000)) //5초동안 유지
			{
				SetTrafficState(VRHY); // 다음 단게로 변경
			}
			break;
		
		case VRHY:
			SetTrafficLED((1<<V_RED) | (1<<H_YELLOW)); // 세로 빨간불, 가로 노란불 점등
			if (Delay(2000)) // 2초동안 유지
			{
				SetTrafficState(VGHR); // 다음 단계로 변경
			}
			break;
		
		case VGHR:
			SetTrafficLED((1<<V_GREEN) | (1<<H_RED)); // 세로 초록불, 가로 빨간불 점등
			if (Delay(5000)) // 5초동안 유지
			{
				SetTrafficState(VYHR); // 다음 단계로 변경
			}
			break;
		
		case VYHR:
			SetTrafficLED((1<<V_YELLOW) | (1<<H_RED)); //세로 노란불, 가로 빨간불 점등
			if (Delay(2000)) // 2초동안 유지
			{
				SetTrafficState(VRHG); // 처음 단계로 돌아감
			}
			break;
	}
}

void ManualTraffic(uint8_t *eTrafficState) // 수동 상태 동작
{
	if ( GetTrafficSignalButtonState() ) // 신호 단계 변경 버튼 입력
	{
		uint8_t traffic = GetTrafficState() + 1; // 다음 단계로 변경
		
		if (traffic == 4) // 단계가 4단계까지 도달하면
		{
			SetTrafficState(VRHG); // 처음단계로 돌아감
		}
		else
		{
			SetTrafficState(traffic); // 아니라면 다음단계로 진행
		}
	}
	
	switch(*eTrafficState) // 신호 단계를 받아서 동작
	{
		case VRHG:
			SetTrafficLED((1<<V_RED) | (1<<H_GREEN)); // 세로 빨간불, 가로 초록불 점등
			break;
		
		case VRHY:
			SetTrafficLED((1<<V_RED) | (1<<H_YELLOW)); // 세로 빨간불, 가로 노란불 점등
			break;
		
		case VGHR:
			SetTrafficLED((1<<V_GREEN) | (1<<H_RED)); // 세로 초록불, 가로 빨간불 점등
			break;
		
		case VYHR:
			SetTrafficLED((1<<V_YELLOW) | (1<<H_RED)); // 세로 노란불, 가로 빨간불 점등
			break;
	}
}



