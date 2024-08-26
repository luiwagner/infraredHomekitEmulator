struct roomLamp : Service::LightBulb {               
  SpanCharacteristic *power;                         
  SpanCharacteristic *level;                         
  int oldBrightness;
  int oldPower;

  roomLamp() : Service::LightBulb(){                 

    power=new Characteristic::On(0);
                
    level=new Characteristic::Brightness(0);    //  NEW! Instantiate the Brightness Characteristic with an initial value of 50% (same as we did in Example 4)
    level->setRange(4,100,8);   //  Lamp got 12 Brightness level. 8 Percent per Step * 12 Steps + 4 rest = 100
    
    oldBrightness = 0;
    oldPower = 0;

    power->setVal(0);
    level->setVal(0);

  } // end constructor

  void sendIR(int newBrightness, int newPower) {
    if((newPower == 1) && (newPower != oldPower)) {   // On "On" Signal turn on if state was low before
      Serial.println("on");
      IrSender.sendPulseDistanceWidth(38, 4550, 4550, 550, 1750, 550, 600, 0x1505, 24, PROTOCOL_IS_LSB_FIRST, 0, 0);    //  Send On Signal with IrSender
      oldPower = 1;   //  set oldPower to 1 so state is recogniced as On
      //oldBrightness = 0;
    }else if(newPower == 0) {
      Serial.println("off");
      //todo: IrSender turn Lamp of
      oldPower = 0;   //  set oldPower to 0 so state is recogniced as Off
    }
    

    if(newBrightness > oldBrightness) {
      int differentialLevel = (newBrightness - oldBrightness) / 8;    //  Calculating how many steps are needed to reach the new power goal
      for(int i = 0; i < differentialLevel; i++) {    //  Repeat for loop for each step needed
        Serial.println("brighter");
        //todo: IrSender increase Brightness
        oldBrightness = newBrightness;    // set oldBrightness to newBrightness
        delay(100);
      }
    }else if(newBrightness < oldBrightness) {
      int differentialLevel = (oldBrightness - newBrightness) / 8;    //  Calculating how many steps are needed to reach the new power goal
      for(int i = 0; i < differentialLevel; i++) {    //  Repeat for loop for each step needed
        //todo: IrSender increase Brightness
        Serial.println("darker");
        oldBrightness = newBrightness;    // set oldBrightness to newBrightness
        delay(100);
      }
    }
  }

  boolean update(){

    sendIR(level->getNewVal(), power->getNewVal());
   
    return(true);
  
  }
};
