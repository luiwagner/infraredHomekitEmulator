/*
 * ReceiveAndSendDistanceWidth.cpp
 *
 * Record and play back last received distance width IR signal at button press.
 * Using DistanceWidthProtocol covers a lot of known and unknown IR protocols,
 * and requires less memory than raw protocol.
 *
 * The logic is:
 * If the button is pressed, send the IR code.
 * If an IR code is received, record it.
 *
 * An example for simultaneous receiving and sending is in the UnitTest example.
 *
 * An IR detector/demodulator must be connected to the input IR_RECEIVE_PIN.
 *
 * A button must be connected between the input SEND_BUTTON_PIN and ground.
 * A visible LED can be connected to STATUS_PIN to provide status.
 *
 * See also https://dronebotworkshop.com/ir-remotes/#ReceiveAndSendDistanceWidth_Code
 *
 *  This file is part of Arduino-IRremote https://github.com/Arduino-IRremote/Arduino-IRremote.
 *
 ************************************************************************************
 * MIT License
 *
 * Copyright (c) 2023 Armin Joachimsmeyer
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is furnished
 * to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
 * PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
 * CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE
 * OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 ************************************************************************************
 */
#include <Arduino.h>

//#include "PinDefinitionsAndMore.h" // Define macros for input and output pin etc.

#include <IRremote.hpp>

#include "LampControl.h"

#define IR_SEND_PIN 33

LampControl roofLamp(false, 6, 3);

void setup() {

  Serial.begin(115200);
  delay(100);
  Serial.println(33);
  
  IrSender.begin(IR_SEND_PIN); // Start with IR_SEND_PIN -which is defined in PinDefinitionsAndMore.h- as send pin and enable feedback LED at default feedback LED pin
  

}

void loop() {
  Serial.println("Sending...");
  IrSender.sendPulseDistanceWidth(38, 4550, 4550, 550, 1750, 550, 600, 0x1505, 24, PROTOCOL_IS_LSB_FIRST, 0, 0);
  roofLamp.changeState();
  roofLamp.changeBrightness();
  roofLamp.changeColorTemp();

  delay(5000);
}



