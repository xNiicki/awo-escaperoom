// DEFINES
// Macros to retrieve the fractional seconds and minute parts of a time
// supplied in ms
// INCLUDES
// https://github.com/avishorp/TM1637
#include <TM1637Display.h>
// CONSTANTS
const uint8_t OFF[] = {0, 0, 0, 0};
// In this library, the byte order is .GFEDCBA
const uint8_t PLAY[] = {B01110011, B00111000, B01011111, B01101110};
// GLOBALS
// cCreate a display object, specifying parameters (Clock pin, Data pin)
TM1637Display display (3, 4);
long c = 0;
long s = 900;
long myTime;
long milis;
long seconds;
long minutes;
long a;


void setup(){
// Set brightness
display.setBrightness (0x0c) ;
// Clear the display
display.setSegments (OFF) ;
// See the word PLAY 
Serial.begin(9600);
a = 1000;
}

void countdown() {
  milis = millis();
  myTime = milis / 1000;
  c = s - myTime;


  minutes = c / 60;
  seconds = c % 60;
  Serial.print("Minutes ");
  Serial.print(minutes);
  Serial.print(" : ");
  Serial.println(seconds);
      display.showNumberDecEx(seconds, 0, true, 2, 2);
    display.showNumberDecEx(minutes, 0x80>>3, true, 2, 0) ;
    a = a+1000;
    Serial.print("a = ");
    Serial.println(a);

  
}


void loop() { 
  if (millis() == a){
    countdown();
  }
  
}
