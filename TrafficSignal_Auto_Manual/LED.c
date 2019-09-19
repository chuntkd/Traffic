/*
* LED.c
*
* Created: 2019-09-03 오후 12:41:29
*  Author: rhoblack@naver.com
*/
#include "LED.h"

void LEDInit() // 신호등 , 상태 LED 표시 설정
{
	TRAFFIC_SIGNAL_LED_DDR |= (1<<V_RED) | (1<<V_YELLOW) | 
		(1<<V_GREEN) | (1<<H_RED) | (1<<H_YELLOW) | (1<<H_GREEN); // 신호등
		
	TRAFFIC_MODE_LED_DDR |= (1<<TRAFFIC_MANUAL_LED) | (1<<TRAFFIC_AUTO_LED); //상태 LED
}

void SetTrafficLED(uint8_t posColor) //
{
	TRAFFIC_SIGNAL_LED_PORT &= ~((1<<V_RED) | (1<<V_YELLOW) | (1<<V_GREEN) | (1<<H_RED) | (1<<H_YELLOW) | (1<<H_GREEN));
	TRAFFIC_SIGNAL_LED_PORT |= posColor; // 설정한 LED 만 점등 
}

void SetAutoModeLED() // Auto led 설정
{
	TRAFFIC_MODE_LED_PORT &= ~(1<<TRAFFIC_MANUAL_LED); // Manual LED 꺼짐
	TRAFFIC_MODE_LED_PORT |= (1<<TRAFFIC_AUTO_LED); // Auto LED 켜짐
}

void SetManualModeLED()
{
	TRAFFIC_MODE_LED_PORT |= (1<<TRAFFIC_MANUAL_LED); // Manual LED 켜짐
	TRAFFIC_MODE_LED_PORT &= ~(1<<TRAFFIC_AUTO_LED); // Auto LED 꺼짐
}