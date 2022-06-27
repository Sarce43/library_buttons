/*
 * ButtonLibrary.cpp (A library for button control)
 * Autor: Pedro H. P. Silva
 * Date: 21/06/2022
 * Update: __/__/____, by ________ , because ____________.
 * 
 */

 #include "Arduino.h"
 #include "ButtonLibrary.h"

 Button::Button(int pin, uint8_t type){
  if(type == INPUT){
    //button in pull_down
    _type = 1;  
  }
  else {
    //buton in pull_up;
    _type = 0;
  }
  _pin = pin;
  pinMode(pin,type);
 }


 int Button::getStateButton(){
    int currentStateButton = digitalRead(_pin);
    return currentStateButton;
 }

 void Button::pressed(void function(void)){
    stateButton = getStateButton();
    if((stateButton == _type) && (stateButton != lastStateButton)){
      //button pressed
      timeMillis = millis();
      function();
    }
    if((millis() - timeMillis) <= debounceTime){
      //only wait
      delay(1);  
    }
    
    lastStateButton = stateButton;
 }

  void Button::released(void function(void)){
    stateButton = getStateButton();
    if((stateButton == _type) && (stateButton != lastStateButton)){
      //button pressed
      timeMillis = millis();  
    }
    if((millis() - timeMillis) > debounceTime){
      if((stateButton != _type) && (stateButton != lastStateButton)){
        //button release
          function();
      }
    }

    lastStateButton = stateButton;
  }

  void Button::setDebounceTime(unsigned long newDebounceTime){
    if(newDebounceTime < 50){
      newDebounceTime = 50;  
    }  
    debounceTime = newDebounceTime;
  }
 
