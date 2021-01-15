#include "Arduino.h"

#include "SIA.h"

Project::Project(float f, int s, int m, int l)
{
    flowRate = f;
    smallCupVol = s;
    mediumCupVol = m;
    largeCupVol = l;
}

void Project::setState(int z)
{
  state=z;
}
int Project::getState()
{
  return state;
}

void Project::setCupSize(int z)
{
  cupSize=z;
}
int Project::getCupSize()
{
  return cupSize;
}

void Project::setPrice(float f)
{
  price=f;
}
float Project::getPrice()
{
  return price;
}

void Project::setEndFill(int z)
{
  endFill=z;
}
int Project::getEndFill()
{
  return endFill;
}

void Project::setDebounceChipHere(int z)
{
  debounceChipHere=z;
}
int Project::getDebounceChipHere()
{
  return debounceChipHere;
}

void Project::setDebounceCupSize(int z)
{
  debounceCupSize=z;
}
int Project::getDebounceCupSize()
{
  return debounceCupSize;
}

String Project::numbToString(int z) //coverts a number to a String
{
  switch (z) {
    case 0: return "0"; break;
    case 1: return "1"; break;
    case 2: return "2"; break;
    case 3: return "3"; break;
    case 4: return "4"; break;
    case 5: return "5"; break;
    case 6: return "6"; break;
    case 7: return "7"; break;
    case 8: return "8"; break;
    case 9: return "9"; break;
    default: return "x"; break;

  }
}

void Project::setPaid(float f)
{
  paid=f;
}
void Project::addPaid(float f)
{
  paid +=f;
}
float Project::getPaid()
{
  return paid;
}

void Project::setPct(char p, float f)
{
  switch (p) {
    case 'A': pctA=f; break;
    case 'B': pctB=f; break;
    case 'C': pctC=f; break;
    case 'D': pctD=f; break;
    default: break;
  }
}

float Project::getPct(char p)
{
  switch (p) {
    case 'A': return pctA;
    case 'B': return pctB;
    case 'C': return pctC;
    case 'D': return pctD;
    default: return 0;
  }
}

void Project::setStartSeq(int z)
{
  startSeq=z;
}
int Project::getStartSeq()
{
  return startSeq;
}

void Project::setEndSeq(int z)
{
  endSeq=z;
}
int Project::getEndSeq()
{
  return endSeq;
}

float Project::pctTimeCalc(char p)
{
  float f=0;
  int s=0;
  switch (p) {
    case 'A': f=pctA; break;
    case 'B': f=pctB; break;
    case 'C': f=pctC; break;
    case 'D': f=pctD; break;
    default: break;
  }
  switch (cupSize) {
    case 1: s =smallCupVol;break;
    case 2: s =mediumCupVol;break;
    case 3: s =largeCupVol;break;
    default: break;
  }
  return ((f/100)*s)/flowRate;
}

void Project::setInsertCup(int z)
{
    insertCup = z;
}
int Project::getInsertCup()
{
  return insertCup;
}

void Project::setNoCup(int z)
{
    noCup = z;
}
int Project::getNoCup()
{
    return noCup;
}


float Project::priceCalc()
{
    setVolume(cupSize);
    price = ((((pctA / 100) * volume) / 100) * prices[0]);
    price = price + ((((pctB / 100) * volume) / 100) * prices[1]);
    price = price + ((((pctC / 100) * volume) / 100) * prices[2]);
    price = price + ((((pctD / 100) * volume) / 100) * prices[3]);
    price = floor(price * 10) / 10;
    return price;
}

void Project::setVolume(int z) {
    switch (z)
    {
    case 1:
        volume = smallCupVol;
        break;
    case 2:
        volume = mediumCupVol;
        break;
    case 3:
        volume = largeCupVol;
        break;
    default:
        break;
    }
}

void Project::setCupOut(int z)
{
    cupOut = z;
}

int Project::getCupOut()
{
    return cupOut;
}

String Project::getStringPart(String data, char separator, int index)
{
    int found = 0;
    int strIndex[] = { 0, -1 };
    int maxIndex = data.length() - 1;

    for (int i = 0; i <= maxIndex && found <= index; i++) {
        if (data.charAt(i) == separator || i == maxIndex) {
            found++;
            strIndex[0] = strIndex[1] + 1;
            strIndex[1] = (i == maxIndex) ? i + 1 : i;
        }
    }
    return found > index ? data.substring(strIndex[0], strIndex[1]) : "";
}


Relay::Relay(int z)
{
  pin=z;
  pinMode(pin, OUTPUT);
  relayOff();
}

void Relay::relayOn() //turns Relay on
{
  digitalWrite(pin, on);
}

void Relay::relayOff() //turns Relay off
{
  digitalWrite(pin, off);
}

void Relay::timeControll(int t) //turns Relay for t ms on
{
  relayOn();
  delay(t);
  relayOff();
}


LED::LED(int z)
{
  pin=z;
  pinMode(pin, OUTPUT);
}

void LED::On() //turns led on
{
  digitalWrite(pin, on);
}

void LED::Off() //turns LED off
{
  digitalWrite(pin, off);
}

void LED::timeControll(int t) //turns LED for t ms on
{
  On();
  delay(t);
  Off();
}


Button::Button(int z)
{
  pin=z;
}

bool Button::isPressed() //returns the state of a button - HIGH/LOW - and saves the state
{
  pressed=digitalRead(pin);
  return pressed;
}

bool Button::getPressed() //returns a previous saved state of the button
{
  return pressed;
}


Barrier::Barrier(int z)
{
  pin=z;
}

void Barrier::calibration()
{
  long t = millis();
  int z =0;
  do {
    int y = analogRead(pin);
    if (y>z) {
      z=y;
    }
  } while (millis()-t<2500);
  normalBrightness = z + 50; // plus 50 gegen Schwankungen
}

bool Barrier::interrupt()
{
  if (analogRead(pin)>normalBrightness) {
    return true;
  } else {
    return false;
  }
}
