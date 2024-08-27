#include <HomeSpan.h>
#include <IRremote.hpp>
#include "roomLamp.h"          

void setup() {
  Serial.begin(115200); // Establish Serial Connection
  delay(100);
  IrSender.begin(14); // Create IR Sender on Pin 14
  delay(100);
  homeSpan.begin(Category::Lighting,"Zimmerlampe"); // Create Homespan Device
  homeSpan.setPairingCode("11112222"); //Set Pairing Code
  homeSpan.setWifiCredentials("SSID", "PASSWORD"); // Configure Wifi Credentials

  new SpanAccessory(); 
  
    new Service::AccessoryInformation();    
      new Characteristic::Identify();
      new Characteristic::Manufacturer("github: wagnerlui");
  
    new roomLamp();

}

void loop(){
  
  homeSpan.poll();
  
}
