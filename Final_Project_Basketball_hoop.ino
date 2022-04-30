#include <Adafruit_NeoPixel.h>

//make my neopixel pbject
int numLights = 60;
int stripPin = 9;
Adafruit_NeoPixel strip (numLights, stripPin);

int index = 0;
boolean isIncreasing;

unsigned long startTime = millis();
unsigned long endTime = millis();

int interval = 1;

//make a color
uint32_t red = strip.Color(255, 0, 0);
uint32_t orange = strip.Color(255, 165, 0);
uint32_t yellow = strip.Color(255, 255, 0);
uint32_t green = strip.Color(0, 128, 0);
uint32_t cyan = strip.Color(0, 255, 255);
uint32_t blue = strip.Color(0, 255, 0);

//make an array manually
int testArray[] = {2, 4, 10};
int photoPin = A0;
int photoReading;

int sum = 0;
const int arrayLen = 100;
int dynamicArray [arrayLen];
unsigned long average;
int state = 0;




void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  strip.begin();
  strip.clear();
  strip.show();

  isIncreasing = true;

  //set the brightness
  strip.setBrightness(255);

  //if statement for photoresistor
  // if (photoReading <= 300){
  // state += 1;
  //}
  Serial.println(state);
}




void loop() {
  // put your main code here, to run repeatedly:


  //get new value
  photoReading = analogRead(photoPin);
  Serial.println(photoReading);

  //if statement for photoresistor
  if (photoReading <= 500 && state < 13) {
    state += 1;
    delay(500);

  }
  Serial.println(state);


  //switch states
  switch (state) {
    case 0:
      strip.clear();
      //make entire neopixel strip white
      for (int i = 0; i < strip.numPixels(); i++) {
        strip.setPixelColor(i, 255, 255, 255);
      }
      strip.show();
      break;
    case 1:
      strip.clear();
      //make entire neopixel strip red
      for (int i = 0; i < strip.numPixels(); i++) {
        strip.setPixelColor(i, 255, 0, 0);
      }
      strip.show();
      break;
    case 2:
      //make entire neopixel strip red orange
      for (int i = 0; i < strip.numPixels(); i++) {
        strip.setPixelColor(i, 255, 83, 73);
      }
      strip.show();
      break;
    case 3:
      //make entire neopixel strip orange
      for (int i = 0; i < strip.numPixels(); i++) {
        strip.setPixelColor(i, 255, 128, 0);
      }
      strip.show();
      break;
    case 4:
      //make entire neopixel strip orange
      for (int i = 0; i < strip.numPixels(); i++) {
        strip.setPixelColor(i, 255, 178, 102);
      }
      strip.show();
      break;
    case 5:
      //make entire neopixel strip yellow
      for (int i = 0; i < strip.numPixels(); i++) {
        strip.setPixelColor(i, 255, 255, 0);
      }
      strip.show();
      break;
    case 6:
      //make entire neopixel strip yellow
      for (int i = 0; i < strip.numPixels(); i++) {
        strip.setPixelColor(i, 255, 255, 0);
      }
      strip.show();
      break;
    case 7:
      //make entire neopixel strip hard green
      for (int i = 0; i < strip.numPixels(); i++) {
        strip.setPixelColor(i, 25, 51, 0);
      }
      strip.show();
      break;
    case 8:
      strip.clear();
      //make entire neopixel strip green
      for (int i = 0; i < strip.numPixels(); i++) {
        strip.setPixelColor(i, 0, 255, 0);
      }
      strip.show();
      break;
    case 9:
      strip.clear();
      //make entire neopixel strip cyan
      for (int i = 0; i < strip.numPixels(); i++) {
        strip.setPixelColor(i, 0, 255, 255);
      }
      strip.show();
      break;
    case 10:
      strip.clear();
      //make entire neopixel strip blue
      for (int i = 0; i < strip.numPixels(); i++) {
        strip.setPixelColor(i, 0, 0, 255);
      }
      strip.show();
      break;
    case 11:
      strip.clear();
      //make entire neopixel strip purple
      for (int i = 0; i < strip.numPixels(); i++) {
        strip.setPixelColor(i, 127, 0, 255);
      }
      strip.show();
      break;
    case 12:
      strip.clear();
      //make entire neopixel strip pink
      for (int i = 0; i < strip.numPixels(); i++) {
        strip.setPixelColor(i, 255, 0, 255);
      }
      strip.show();
      break;
    case 13:
      strip.clear();
      strip.setPixelColor(index, 0, 255, 255);
      strip.show();

      endTime = millis();
      if (endTime - startTime > interval) {
        startTime = millis();

        if (isIncreasing == true) {
          index += 1;

          if (index >= 59) {
            isIncreasing = false;
          }
        }
        else if (isIncreasing == false) {
          index -= 1;
          if (index <= 0) {
            isIncreasing = true;
          }
        }
      }
  }



}
