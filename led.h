#ifndef __led_h__
#define __led_h__
/*
 * LED Blink Class 
 */ 
#include "Arduino.h"

class ledBlink  {
    private:
        byte __pinLED;

        boolean __ledState = LOW;

        unsigned long __delayTime;
        unsigned long __nextChangeState=0;
    public:
        ledBlink(byte ledpin);
        void setBlink(unsigned long time);
        void _loop();
        byte getPin();
        unsigned long getBlink();
};



#endif