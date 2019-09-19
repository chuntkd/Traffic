/*
 * trafficSignal.h
 *
 * Created: 2019-09-03 오후 12:35:00
 *  Author: rhoblack@naver.com
 */ 

#ifndef TRAFFICSIGNAL_H_
#define TRAFFICSIGNAL_H_

#define F_CPU	16000000UL
#include <avr/io.h>
#include "LED.h"
#include "button.h"
#include "util.h"
#include "main.h"

enum _etrafficstate {
	VRHG, VRHY, VGHR, VYHR
} eTrafficState; // 신호 단계

enum _etrafficmode{
	TRAFFIC_AUTO, TRAFFIC_MANUAL
} eTrafficMode; // 모드 상태

void AutoTraffic(uint8_t *eTrafficState); // 자동 모드 동작
void ManualTraffic(uint8_t *eTrafficState); // 수동 모드 동작
void SetTrafficState(uint8_t trafficState); // 신호 단계 설정
void SetTrafficMode(uint8_t trafficMode); // 신호 모드 설정


#endif /* TRAFFICSIGNAL_H_ */
