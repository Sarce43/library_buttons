/*
 * ButtonLibrary.h (A library for button control)
 * Autor: Pedro H. P. Silva
 * Date: 21/06/2022
 * Update: __/__/____, by ________ , because ____________.
 * 
 */

 #ifndef ButtonLibrary
 #define ButtonLibrary

 class Button{
  public:
    
    Button(int pin, uint8_t type);
    void pressed(void function(void));
    void released(void function(void));
    int getStateButton();
    void setDebounceTime(unsigned long newDebounceTime);

  private:
    int _pin;
    uint8_t _type;
    int stateButton, lastStateButton;
    unsigned long debounceTime = 300;
    unsigned long timeMillis;

 };
 #endif
