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
long g = 0;
long s = 901;
int a1 = 1000;
uint32_t farben [4];

int j;

int q;


 // NeoPixel test program showing use of the WHITE channel for RGBW
  // pixels only (won't look correct on regular RGB NeoPixel strips).
  
  #include <Adafruit_NeoPixel.h>
  #ifdef __AVR__
   #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
  #endif
  
  // Which pin on the Arduino is connected to the NeoPixels?
  // On a Trinket or Gemma we suggest changing this to 1:
  #define LED_PIN     6
  
  // How many NeoPixels are attached to the Arduino?
  #define LED_COUNT  300
  
  // NeoPixel brightness, 0 (min) to 255 (max)
  #define BRIGHTNESS 255
  // Set BRIGHTNESS to about 1/5 (max = 255)
  
  // Declare our NeoPixel strip object:
  Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRBW + NEO_KHZ800);
  // Argument 1 = Number of pixels in NeoPixel strip
  // Argument 2 = Arduino pin number (most are valid)
  // Argument 3 = Pixel type flags, add together as needed:
  //   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
  //   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
  //   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
  //   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
  //   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)
  int c;
  
  

void setup(){
// Set brightness
display.setBrightness (0x0c) ;
// Clear the display
display.setSegments (OFF) ;
// See the word PLAY 
displayText();

//neopixel

    // put your setup code here, to run once:
    strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
    strip.show();            // Turn OFF all pixels ASAP
    strip.setBrightness(BRIGHTNESS);
    c = 500;

  farben [0] = strip.Color(0, 0, 0, 255);
  farben [1] = strip.Color(0, 0, 255 );
  farben [2] = strip.Color(0, 255, 0 );
  farben [3] = strip.Color(255, 0, 0 );
  farben [4] = strip.Color(255, 0, 255 );

  j = 0;

  Serial.begin(9600);

   q = 5;
}

void countdown() {
  // Math with the arduino to get the minutes and seconds
     Serial.print(q);
     Serial.print("   :   ");
     Serial.println(j); 
     
     g = s - 1 ;
     int minutes = g / 60;
     int seconds = g % 60;
     s = g;

     // the timer stop at 0 
    if( g <= 0){
      g = 0;
    }
    // show the Numbers 
    display.showNumberDecEx(seconds, 0, true, 2, 2);
    display.showNumberDecEx(minutes, 0b01000000, true, 2, 0) ;

    q = q -1 ;

      q = 5;
       strip.fill( farben [j]);
        strip.show();
        if (j == 0) {
          strip.fill( farben [j]);
          strip.show();
          delay(1000);
          j = j + 1 ;}
          else {
          strip.fill( farben [j]);
          strip.show();
            delay(250);
        j = j +1;
        if (j == 5)
          j = 0;
        strip.fill( farben [j]);
        strip.show();
            delay(250);
        j = j +1;
        if (j == 5)
          j = 0;
        strip.fill( farben [j]);
          strip.show();
            delay(250);
        j = j +1;
        if (j == 5)
          j = 0;
        strip.fill( farben [j]);
        strip.show();
            delay(250);
        j = j +1;
        if (j == 5)
          j = 0;}



    Serial.print(q);
    Serial.print("   :   ");
    Serial.println(j); 



    
}






void boombe() {

   while (s == 0) {
    strip.fill(strip.Color(0, 0, 0, 255));
    strip.show();
    delay(20);
    strip.fill(strip.Color(0, 0, 0, 0));
    strip.show();
    delay(20);
   }



  
}












void displayText() {
  // see the word PLAY
  display.setSegments(PLAY);
  delay(1000);
}

void Neopixel() {
             strip.fill(strip.Color(0, 0, 0, 255));
        strip.show();
        delay(2000);       
         strip.fill(strip.Color(0, 0, 255 ));
        strip.show();
        delay(c);
          strip.fill(strip.Color(0, 255, 0 ));
        strip.show();
        delay(c);
          strip.fill(strip.Color(255, 0, 0 ));
        strip.show();
        delay(c);
           strip.fill(strip.Color(255, 0, 255 ));
        strip.show();
        delay(c);
        if (c >100)
          c = c - 5;
          
  
}

void loop() { 
  countdown();
  boombe();
}
