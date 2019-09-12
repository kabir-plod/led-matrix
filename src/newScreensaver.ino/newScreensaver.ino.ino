#define FASTLED_ESP8266_D1_PIN_ORDER
#include <FastLED.h>
#define NUM 220
#define DATA_PIN D6


#define BOARD_HEIGHT 32
#define BOARD_WIDTH 16


CRGB leds[NUM];
int n=0;

void setup() {
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM);
}

uint rcToIndex(uint row, uint col) {
    // Converts 0-indexed row and col co-ords into a single index position
    // for the snake layout of the board. Assumes data in is bottom right corner
    if (col & 0x01) {  // col is odd
        return (BOARD_WIDTH - 1 - col)*BOARD_HEIGHT + BOARD_HEIGHT - 1 - row;
    } else {  // col is even
        return (BOARD_WIDTH - 1 - col)*BOARD_HEIGHT + row;
    }
}


int r = 127;
int g=127;
int b=127;
int number = 220;
void loop() {

  leds[n] = CRGB(r,g,b);
  r=r-2;
  g=g-3;
  leds[(n+1)%number] = CRGB(r,g,b);
  leds[(n-2)%number] = CRGB(0,0,0);
  FastLED.show();
  
  n = (n+1) % number;

  if (n==0){
    number = number -2;
    leds[((n-1)%(number+2))]=CRGB(r,g,b);
        
  }
  if (number <5){
    for (int k=0; k<220; k++){
      leds[k] = CRGB (0,0,0);
    }
    number = 220; 
  }
  delay(50);

// lights up the selected LEDs 
//  for (int r = 15; r<21; r++){ 
//    for (int c = 12;c <16 ; c++){
//      leds[rcToIndex(r,c)] = CRGB(0,80,0);
//      //   n = (n+1) % NUM;
//   }
// }


//leds[n] = CRGB(127,127,127);
//n+1;
//FastLED.show();

}
