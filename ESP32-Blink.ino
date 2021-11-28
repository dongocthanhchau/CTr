#include "led.h"
#include "fs.h"
#define PINLED 14

LedModel ledModel(PINLED);
ledBlink ledBlynk(PINLED);
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  Serial.begin(115200);
  //Serial.setTimeout(10);
  //ledBlynk.setBlink(ledModel.getDelaytime());
  ledBlynk.setBlink(200);
  
}

// the loop function runs over and over again forever
String Sdata="";
void loop() {
  ledBlynk._loop();
  if (Serial.available())
    if (Serial.find("SET TIME ")){
        Sdata = Serial.readString();
        Serial.println(Sdata);
        ledBlynk.setBlink(Sdata.toInt());
        ledModel.setDelaytime(Sdata.toInt());
    }
}
