#include <Bounce.h>


#define startPin 18
#define numPins  3

char keys[numPins] = {
 KEY_LEFT_GUI,
 KEY_LEFT_SHIFT,
 KEY_LEFT_ALT
//  'A',
//  'B',
//  'C'
};

Bounce buttons[numPins] = {
  Bounce( 18, 5 ),
  Bounce( 19, 5 ),
  Bounce( 20, 5 ),
};

void setup() {
  for(int i = 0; i <  numPins; i++){
    int pin = startPin + i;
    pinMode(pin, INPUT);
    digitalWrite(pin, INPUT_PULLUP);
  }
  Keyboard.begin();
}

void loop() {
  // put your main code here, to run repeatedly: 
  for(int i = 0; i <  numPins; i++){
    if(buttons[i].update()){
      if(buttons[i].read() == HIGH){
        Keyboard.release(keys[i]);
      }
      else{
        Keyboard.press(keys[i]);
      }
    }
  }
}

