// Lesson 4 RGB Led + Fade in and out
// This is an Arduino Mega 2560 project
// made for fun by Kacy Stocks- June 12th, 2020
#include <stdlib.h>
#include <time.h>

// Define Pins
#define BLUE 3
#define GREEN 5
#define RED 6

void setup() {
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  Serial.begin(9600);
  srand(time(NULL));
}

int red_b, blue_b, green_b;

void loop() {
  int random_color = (rand() % 3) + 4;
  int random_time = (rand() % 25) + 25;
  int random_brightness = (rand() % 50);

  if (random_color == RED) {
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

  if (random_color == GREEN) {
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

  if (random_color == BLUE) {
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
