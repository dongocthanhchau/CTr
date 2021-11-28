#ifndef __fs_h__
#define __fs_h__

#include "arduino.h"
#include "SPIFFS.h"

class LedModel  {
    private:
        byte __pinLED;

        boolean __ledState = LOW;

        unsigned long __delayTime;
    public:
        LedModel(byte pinLed);
        void setState(boolean state);
        void setDelaytime(unsigned long time);
        boolean getState();
        unsigned long getDelaytime();
        byte getPin();
};
#endif
