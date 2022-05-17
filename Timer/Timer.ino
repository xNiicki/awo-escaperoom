// DEFINES
// Macros to retrieve the fractional seconds and minute parts of a time
// supplied in ms
#define numberOfSeconds(_time_ ) ((_time_ / 1000) % 60)
#define numberOfMinutes(_time_) (((_time_ / 1000) / 60) % 15 - 14)

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

unsigned long c = 15000;

int seconds = 1;
int minutes = 1;

unsigned long timeLimit = 3600000;
  unsigned long timeRemaining = 150000;
void setup(){
Serial.begin(9600);
// Set brightness
display.setBrightness (0x0c) ;
// Clear the display
display.setSegments (OFF) ;
unsigned long timeRemaining = 15000;
}


void countdown() { 
    while(c > 0) {
      int seconds = numberOfSeconds(timeRemaining);
      int minutes = numberOfMinutes(timeRemaining);

      display.showNumberDecEx(seconds, 0, true, 2, 2);
      display.showNumberDecEx(minutes, 0x80>>3, true, 2, 0);

      int c = minutes + seconds;
      
      timeRemaining = timeLimit - millis();
    Serial.println(c);

  }
}
void displayText() {
  display.setSegments(PLAY);
  delay(2000);
}
void loop() {
  displayText();
  countdown();
}
