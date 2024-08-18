#include "LampControl.h"
#include <Arduino.h>

LampControl::LampControl(bool osInit, int bInit, int ctInit) : onState(osInit), brightness(bInit), colorTemp(ctInit) {
  // todo: lampe tatsächlich inizialisieren
}
void LampControl::changeState() {
  Serial.println("changeState function");
}

void LampControl::changeBrightness() {
  Serial.println("changeBrightness function");
}
void LampControl::changeColorTemp() {
  Serial.println("changeColorTemp function");
}
