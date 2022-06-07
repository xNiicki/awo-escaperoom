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
TM1637Display display (2, 3);
long c = 0;
long s = 901;

void setup(){
// Set brightness
display.setBrightness (0x0c) ;
// Clear the display
display.setSegments (OFF) ;
// See the word PLAY 
displayText();
}

void countdown() {
  // Math with the arduino to get the minutes and seconds
     c = s - 1 ;
     int minutes = c / 60;
     int seconds = c % 60;
     s = c;

     // the timer stop at 0 
    if( c <= 0){
      c = 0;
    }
    // show the Numbers 
    display.showNumberDecEx(seconds, 0, true, 2, 2);
    display.showNumberDecEx(minutes, 0x80>>3, true, 2, 0) ;
    delay(1000);
         c = s - 1 ;
      minutes = c / 60;
      seconds = c % 60;
     s = c;

     // the timer stop at 0 
    if( c <= 0){
      c = 0;
    }
    // show the Numbers 
    display.showNumberDecEx(seconds, 0, true, 2, 2);
    display.showNumberDecEx(minutes, 0b01000000, true, 2, 0) ;
    delay(1000);
}
void displayText() {
  // see the word PLAY
  display.setSegments(PLAY);
  delay(1000);
}
void loop() { 
  countdown();
}
