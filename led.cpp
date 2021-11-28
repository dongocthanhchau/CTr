#include "led.h"

ledBlink::ledBlink(byte ledpin){
    pinMode(ledpin,OUTPUT);
    __pinLED=ledpin;
}
void ledBlink::setBlink(unsigned long time){
    __nextChangeState=millis()+time;
    __delayTime=time;
}
void ledBlink::_loop(){
    if (__delayTime!=0 && millis()>=__nextChangeState){
        __ledState = !__ledState;
        digitalWrite(__pinLED,__ledState);
        __nextChangeState+=__delayTime;
    }
}
byte ledBlink::getPin() {
    return __pinLED;
}
unsigned long ledBlink::getBlink(){
    return __delayTime;
}