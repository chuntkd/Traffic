/*
 * button.h
 *
 * Created: 2019-09-03 오후 12:45:08
 *  Author: rhoblack@naver.com
 */ 

#ifndef BUTTON_H_
#define BUTTON_H_

#define F_CPU	16000000UL
#include <avr/io.h>
#include "util.h"

#define BUTTON_DDR	DDRA // 버튼 입력 설정
#define BUTTON_PIN	PINA // 버튼 입력 

#define BUTTON_MODE_DDR	DDRA // 모드 버튼 설정
#define BUTTON_MODE_PIN	PINA // 모드 버튼 입력
#define MODE_BUTTON		0 

#define BUTTON_SIGNAL_DDR	DDRA // 신호 변경 버튼 설정
#define BUTTON_SIGNAL_PIN	PINA // 신호 변경 버튼 입력
#define SIGNAL_BUTTON		1

#define DEBOUNCE	20 // debounce time

void ButtonInit(); // 버튼 설정
uint8_t GetTrafficModeButtonState(); // 모드 변경 버튼의 상태를 받음
uint8_t GetTrafficSignalButtonState(); // 신호 변경 버튼의 상태를 받음
uint8_t GetButtonState(uint8_t button, uint8_t *prevButtonState); // 버튼 동작


#endif /* BUTTON_H_ */