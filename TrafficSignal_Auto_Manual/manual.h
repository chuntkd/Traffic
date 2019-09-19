/*
 * manual.h
 *
 * Created: 2019-09-03 오후 2:33:18
 *  Author: 6층교수실PC
 */ 


#ifndef MANUAL_H_
#define MANUAL_H_

#define F_CPU	16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "LED.h"
#include "button.h"
#include "util.h"
#include "main.h"

void ManualTraffic(uint8_t *eTrafficState);


#endif /* MANUAL_H_ */