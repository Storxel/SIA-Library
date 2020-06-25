#ifndef SIA_h
#define SIA_h
#include "Arduino.h"

class Project
{
  private:
    String tag = "";
    int state = 1;
    int cupSize = 0;
    float paid = 0;
    float pctA = 0;
    float pctB = 0;
    float pctC = 0;
    float pctD = 0;
    int startSeq = 0;
    int endSeq = 0;
    int smallCupVol = 0;
    int mediumCupVol = 0;
    int largeCupVol = 0;
    float price = 0;
    float prices[4] = { 5.5,3.6,2.8,4.0 };
    int endFill = 0;
    int debounceChipHere = 0;
    int debounceCupSize = 0;
    float flowRate = 0.00; //ml pro sec (1000ms)
    int insertCup = 0;
    int noCup = 0;
    int volume = 0;
    int cupOut = 0;


  public:
    int isPaid = 0;
    Project(float f, int s, int m, int l);
    void setState(int z);
    int getState();
    void setCupSize(int z);
    int getCupSize();
    String numbToString(int z);
    void setPaid(float f);
    void addPaid(float f);
    float getPaid();
    void setPct(char p, float f);
    float getPct(char p);
    void setStartSeq(int z);
    int getStartSeq();
    void setEndSeq(int z);
    int getEndSeq();
    void setEndFill(int z);
    int getEndFill();
    void setPrice(float f);
    float getPrice();
    void setDebounceChipHere(int z);
    int getDebounceChipHere();
    void setDebounceCupSize(int z);
    int getDebounceCupSize();
    float pctTimeCalc(char p);
    void setInsertCup(int z);
    int getInsertCup();
    void setNoCup(int z);
    int getNoCup();
    float priceCalc();
    void setVolume(int z);
    void setCupOut(int z);
    int getCupOut();

};

class Relay
{
  //low trigger Relay
  private:
    bool on = false;
    bool off = true;
    int pin;
  public:
    Relay(int z);
    void create();
    void timeControll(int t);
    void relayOn();
    void relayOff();
};

class LED
{
  private:
    bool on = true;
    bool off = false;
    int pin;
  public:
    LED(int z);
    void create();
    void timeControll(int t);
    void LEDOn();
    void LEDOff();

};

class Button {
  private:
    int pin;
    bool pressed;

  public:
    Button(int z);
    bool isPressed();
    bool getPressed();
};

class Barrier {
  private:
    int pin;
    int normalBrightness = 500;

  public:
    Barrier(int z);
    void calibration();
    bool interrupt();

};
#endif
