#include <Adafruit_NeoPixel.h>
#include <TM1637Display.h>

//display
const uint8_t OFF[] = {0, 0, 0, 0};
const uint8_t PLAY[] = {B01110011, B00111000, B01011111, B01101110};
TM1637Display display (
  3, 4);

//neopixel
  #include <Adafruit_NeoPixel.h>
  #ifdef __AVR__
   #include <avr/power.h> 
  #endif
  #define BRIGHTNESS   255
  #define LED_PIN     6
  #define LED_COUNT  300
  Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRBW + NEO_KHZ800);

  //variabel
  int CountdownZeit = 1;
  long Zeit = 900;
  uint32_t farben [0];
  int Numbers[5];
  int buttonState = 0;   
  const int PAUSE = 500; 
  long lastActionTime = -1; 
  int numberr = 0;
  int bombeTrue = 0;
    long  minutes;
    long seconds;
    int PrintWait = 1000;
    int NeopixelTrue = 0 ;
    long test = 5000;
    int NeopixelPause = 0;
 
 

void setup(){
    Serial.begin(9600);
    display.setBrightness (0x0c) ;
    display.setSegments (OFF) ;
    strip.begin();     
    strip.fill(strip.Color(0,0,0,255));
    strip.show();          
    strip.setBrightness(BRIGHTNESS);
    pinMode(8, INPUT);
}

void countdown() {

  long  milis = millis();
  long  myTime = milis / 1000;
  CountdownZeit = Zeit - myTime;
    minutes = CountdownZeit / 60;
   seconds = CountdownZeit % 60;
  display.showNumberDecEx(seconds, 0, true, 2, 2);
  display.showNumberDecEx(minutes, 0x80>>3, true, 2, 0) ;  
  if (CountdownZeit == -1)
    boombe();
  
}


void boombe() {
   while (true) {
    strip.fill(strip.Color(0, 0, 0, 255));
    strip.show();
    delay(20);
    strip.fill(strip.Color(0, 0, 0, 0));
    strip.show();
    delay(20);
   }
}


void number() {
     Numbers[0] = random(1,5);
               Serial.println(Numbers[0]);
     Numbers[1] = random(1,5);
     while(Numbers[1] == Numbers[0]) {
      Numbers[1] = random(1,5);
    }
                   Serial.println(Numbers[1]);
    Numbers[2] = random(1,5);
    while(Numbers[2] == Numbers[0] || Numbers[2] == Numbers[1]) {
      Numbers[2] = random(1,5);
    }
                   Serial.println(Numbers[2]);
     Numbers[3] = random(1,5);
      while(Numbers[3] == Numbers[0] || Numbers[3] == Numbers[1] || Numbers[3] == Numbers[2]) {
      Numbers[3] = random(1,5);
    }               Serial.println(Numbers[3]);



  NeopixelTrue = 1;
   
    
}

void Neopixel() {

  if (NeopixelTrue == 1){


  if(NeopixelPause<millis()){  


     if (Numbers[numberr] == 1){
        strip.fill(strip.Color(255,0,0));
        strip.show();
    } else if(Numbers[numberr] == 2) {
        strip.fill(strip.Color(0,255,0));
        strip.show();
    }else if(Numbers[numberr] == 3) {
        strip.fill(strip.Color(0,0,255));
        strip.show();
    }else if(Numbers[numberr] == 4) {
        strip.fill(strip.Color(255,0,255));
        strip.show();
    }
    else if(numberr == 4) {
      strip.fill(strip.Color(0,0,0, 255));
      strip.show();
    }
    
    if (numberr == 5){
      numberr = 0 ;
      NeopixelTrue = 0;
      strip.fill(strip.Color(0,0,0, 255));
      strip.show();
          strip.setBrightness(BRIGHTNESS);
      
    }
    numberr = numberr + 1;
    Serial.println(numberr);

    NeopixelPause = millis() + 500;  }

    if (numberr == 5){
      numberr = 0 ;
      NeopixelTrue = 0;
      strip.fill(strip.Color(0,0,0, 255));
      strip.show();
      
    }


  }  
}


void Prints(){
    if (millis() > PrintWait) {
      Serial.print(CountdownZeit);
      Serial.print(";");
          Serial.print(Numbers[0]);
    Serial.print(Numbers[1]);
    Serial.print(Numbers[2]);
    Serial.println(Numbers[3]);
      PrintWait = millis() + 1000;
    }
}




void loop() { 
  buttonState = digitalRead(8);
  Neopixel();
  countdown();
  Prints();

  if (millis() > test){
    number();
    test = 2147483647;
  }

}
