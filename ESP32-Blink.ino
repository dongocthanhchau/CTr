#include "led.h"
#define PINLED 14

ledBlink ledBlynk(PINLED);

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  ledBlynk.setBlink(500);
}

// the loop function runs over and over again forever
void loop() {
  ledBlynk._loop();
 }
