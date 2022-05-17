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
  
  
  void setup() {
    // put your setup code here, to run once:
    strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
    strip.show();            // Turn OFF all pixels ASAP
    strip.setBrightness(BRIGHTNESS);
    c = 500;
  } 
  
  void loop() {
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
          c = c - 1;
  
  }
