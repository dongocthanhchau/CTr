#include "led.h"
#include "fs.h"
#define PINLED 14

ledBlink ledBlynk(PINLED);
dataConfig data;
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  Serial.begin(115200);

  if(!SPIFFS.begin(true)){
    //Serial.println(F("An Error has occurred while mounting SPIFFS"));
    return;
  }
  
  File file = SPIFFS.open("/text.txt");
  if(!file){
    //Serial.println(F("Failed to open file for reading"));
    return;
  }
  
  //Serial.println(F("File Content:"));
  while(file.available()){
    Serial.write(file.read());
  }
  file.close();
  
  
  
  ledBlynk.setBlink(500);
  
}

// the loop function runs over and over again forever
void loop() {
  ledBlynk._loop();
 }
