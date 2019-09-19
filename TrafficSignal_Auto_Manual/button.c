/*
* button.c
*
* Created: 2019-09-03 오전 10:34:03
* Author : rhoblack@naver.com
*/

#include "button.h"

void ButtonInit()
{
	BUTTON_MODE_DDR &= ~(1<<MODE_BUTTON); // 모드 변경 버튼 입력 설정
	BUTTON_SIGNAL_DDR &= ~(1<<SIGNAL_BUTTON); // 신호 변경 LED 설정
}

uint8_t GetTrafficModeButtonState()
{
	static uint8_t prevModeButtonState = 1; // 모드버튼의 기본상태 1
	
	return GetButtonState(MODE_BUTTON, &prevModeButtonState); // 원래 메모리 값을 기억해서 변경하기 위해서 포인터로 버튼 상태를 포인터로 지정
	
}

uint8_t GetTrafficSignalButtonState() // 신호 변경 버튼 상태
{
	static uint8_t prevSignalButtonState = 1; // 신호 변경 버튼 기본 상태
	
	return GetButtonState(SIGNAL_BUTTON, &prevSignalButtonState); // prevSignalButtonState 를 GetButtonState로 보냄
}


uint8_t GetButtonState(uint8_t button, uint8_t *prevButtonState) // 범용버튼 번호, 범용버튼 상태 
{
	uint8_t curButtonState = 1; // 현재 버튼 상태 = 1
	static uint32_t prevTime=0;  // 이전 시간 = 0 (처음만)
	uint32_t curTime; // 현재시간
	
	curButtonState = (BUTTON_PIN & (1<<button)) >> button; // 버튼이 입력을 받는다 
	if ( (curButtonState == 0) && (*prevButtonState == 1) ) // 버튼이 눌렸을때
	{
		*prevButtonState = curButtonState; 
		prevTime = GetMillis();// millisCount;
		return 0;
	}
	else if ( (curButtonState == 1) && (*prevButtonState == 0) ) // 버튼을 때고있을때
	{
		curTime = GetMillis();// millisCount; 
		if (curTime - prevTime > DEBOUNCE) // 20ms가 경과하면
		{
			*prevButtonState = curButtonState; 
			return 1; // 버튼이 떨어질때 동작
		}
		return 0;
	}
	
	return 0;
}
