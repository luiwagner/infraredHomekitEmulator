#ifndef LAMPCONTROL_H
#define LAMPCONTROL_H

class LampControl {
  private:
    bool onState;
    int brightness;
    int colorTemp;
  
  public:
    LampControl(bool osInit, int bInit, int ctInit);

    void changeState();
    void changeBrightness();
    void changeColorTemp();
};

#endif LAMPCONTROL_H