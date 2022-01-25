#include <FastLED.h>
#include <Keyboard.h>

#define LED_PIN_ONE     7
#define LED_PIN_TWO     8

const int NUM_INPUTS = 6;
const byte SENSOR[NUM_INPUTS] = { A2, A3, A1, A6, A0, A7 };
const byte KEYS[NUM_INPUTS] = { 0x31, 0x32, 0x33, 0x34, 0x35, 0x36 };

#define NUM_LEDS    9
CRGB leds[NUM_LEDS];

void setup() {
  for(int i = 0; i < NUM_INPUTS; i++){
    pinMode(SENSOR[i], INPUT_PULLUP);
  }
  
  FastLED.addLeds<WS2812B, LED_PIN_ONE, RGB>(leds, NUM_LEDS);
  FastLED.addLeds<WS2812B, LED_PIN_TWO, RGB>(leds, NUM_LEDS);
  FastLED.setBrightness(255);
  
  Keyboard.begin();
}

void loop() {
  for(int i = 0; i < NUM_LEDS; ++i){
    //set this to whatever
    leds[i] = CRGB::White;
    //leds[i] = CRGB(255, 20, 255);
  }
  FastLED.show();
  
  for(int i = 0; i < NUM_INPUTS; i++){
    if(digitalRead(SENSOR[i]) > 0){
      Keyboard.press(KEYS[i]);
    }else{
      Keyboard.release(KEYS[i]);
    }
  }
}
