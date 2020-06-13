

#include <stdlib.h>
#include <time.h>

// Define Pins
#define BLUE 3
#define GREEN 5
#define RED 6
#define delayTime 10



void setup() {
  // put your setup code here, to run once:
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  Serial.begin(9600);
  srand(time(NULL));
}

//void loop() {
//  for (int i = 4; i < 7; i++ ) {
//    for (int x = 0; x < 200; x++) {
//      analogWrite(i, x);
//      delay(10);
//    }
//    for (int x = 200; x >=0; x--) {
//          analogWrite(i, x);
//          delay(10);
//    }
//  }
//}

//void loop() {
//  for (int i = 4; i < 7; i++ ) {
//    for (int x = 0; x < 75; x++) {
//      analogWrite(i, x);
//      delay(delayTime);
//    }
//    for (int x = 74; x >= 0; x--) {
//        analogWrite(i, x);
//        delay(delayTime);
//
//    }
//  }
//}
int last, prev, prev_color, red_b, blue_b, green_b;

void loop() {
  int random_color = (rand() % 3) + 4;
  int random_time = (rand() % 25) + 25;
  int random_brightness = (rand() % 50);

  // if red
  if (random_color == 4) {
    if (random_brightness > red_b) {
      for (int i = red_b; i <= random_brightness; i++) {
        analogWrite(random_color, i);
        delay(random_time);
      }
      red_b = random_brightness;
    } else {
      for (int i = red_b; i >= 0; i--) {
        analogWrite(random_color, i);
        delay(random_time);
      }
      red_b = 0;
    }
  }

  // if green
  if (random_color == 5) {
    if (random_brightness > green_b) {
      for (int i = green_b; i <= random_brightness; i++) {
        analogWrite(random_color, i);
        delay(random_time);
      }
      green_b = random_brightness;
    } else {
      for (int i = green_b; i >= 0; i--) {
        analogWrite(random_color, i);
        delay(random_time);
      }
      green_b = 0;
    }
  }

  // if blue
  if (random_color == 6) {
    if (random_brightness > blue_b) {
      for (int i = blue_b; i <= random_brightness; i++) {
        analogWrite(random_color, i);
        delay(random_time);
      }
      blue_b = random_brightness;

    } else {
      for (int i = blue_b; i >= 0; i--) {
        analogWrite(random_color, i);
        delay(random_time);
      }
      blue_b = 0;
    }
  }
  
}
