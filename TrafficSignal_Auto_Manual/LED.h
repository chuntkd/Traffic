/*
 * LED.h
 *
 * Created: 2019-09-03 오후 12:41:42
 *  Author: rhoblack@naver.com
 */ 


#ifndef LED_H_
#define LED_H_

#define F_CPU	16000000UL
#include <avr/io.h>


#define TRAFFIC_SIGNAL_LED_DDR		DDRC // 신호 LED 출력 설정
#define TRAFFIC_SIGNAL_LED_PORT		PORTC // 신호 LED 출력

#define V_RED		0
#define V_YELLOW	1
#define V_GREEN		2
#define H_RED		3
#define H_YELLOW	4
#define H_GREEN		5

#define TRAFFIC_MODE_LED_DDR	DDRD // 모드 LED 출력 설정
#define TRAFFIC_MODE_LED_PORT	PORTD // 모드 LED 출력

#define TRAFFIC_MANUAL_LED  1 // MANUAL LED 지정 
#define TRAFFIC_AUTO_LED  0 // AUTO LED 지정

void SetTrafficLED(uint8_t color); // 입력한 색의 신호 LED 출력
void LEDInit(); // LED 출력 설정
void SetAutoModeLED(); // AUTO LED 켜짐
void SetManualModeLED(); // MANUAL LED 켜짐


#endif /* LED_H_ */