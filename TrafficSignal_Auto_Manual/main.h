/*
 * main.h
 *
 * Created: 2019-09-03 오후 1:59:53
 *  Author: rhoblack@naver.com
 */ 


#ifndef MAIN_H_
#define MAIN_H_

#define F_CPU	16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "button.h"
#include "LED.h"
#include "auto.h"
#include "manual.h"
#include "trafficSignal.h"



uint8_t GetTrafficState(); // 신호 단계 받음
uint8_t GetTrafficMode(); // 신호 모드 받음


#endif /* MAIN_H_ */