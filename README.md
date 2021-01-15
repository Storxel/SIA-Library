# SIA Library

This library was created as part of the SIA (a school subject). This project is a library for an Arduino. 
The library contains the following classes:
* Project
* Relay
* LED
* Button
* Barrier

A brief overview can be found below. More information is available in the code in the form of comments

## Relay
The class Relay consists of a constructor Relay(int) which takes as parameter the pin to which the relay is connected to.
The class consists of the following methods:
* relayOn() turns the relay on
* relayOff() turns it off
* timeControll(int t) turns the relay on, delays for t ms and turns it then off

## LED
The class LED consists of a constructor LED(int) which takes as parameter the pin to which the LED is connected to.
The class consists of the following methods:
* On() turns the LED on
* Off() turns it off
* timeControll(int t) turns the LED on, delays for t ms and turns it then off

## Button
The class Button consists of a constructor Button(int) which takes as parameter the pin to which the button is connected to.
The class consists of the following methods:
* isPressed() safes the current button state and returns it
* getPressed() returns a previous saved button state

## Barrier
The class Barrier is for adding light barriers. It consists of a constructor Barrier(int) which takes as parameter the pin to which the light barrier is connected to.
The class consists of the following methods:
* calibration() calibrates the light barrier
* interrupt() returns as boolean whether something has passed the light barrier
