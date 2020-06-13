// Arduino Lesson 5: Digital Inputs
// This is an Arduino Mega 2560 project
// made for fun by Kacy Stocks- June 13th, 2020
int ledPin = 5;
int buttonApin = 9;
int buttonBpin = 8;

void setup()
{
  pinMode(ledPin, OUTPUT);
  pinMode(buttonApin, INPUT_PULLUP);
  pinMode(buttonBpin, INPUT_PULLUP);
}

//void loop() // this is the original project, kinda boring
//{
//  if (digitalRead(buttonApin) == LOW)
//  {
//    digitalWrite(ledPin, HIGH);
//  }
//  if (digitalRead(buttonBpin) == LOW)
//  {
//    digitalWrite(ledPin, LOW);
//  }
//}

void light_up(int bright, int wait) {

  analogWrite(ledPin, bright);
  delay(wait);

}

void strobe(int times) {
  for (int i = 0; i < times; i++) {

    for (int j = 0; j < 255; j++) {

      light_up(j, 1);

    }
    for (int j = 255; j > 0; j--) {

      light_up(j, 1);

    }
  }
}

void loop()
{
  int i;
  if (digitalRead(buttonApin) == LOW)
  {
    for (i = 0; i < 200; i++ ) {

      light_up(i, 5);

      if (digitalRead(buttonBpin) == LOW)

        strobe(5);

    }
    for (i = 200; i >= 0; i--) {

      light_up(i, 5);

      if (digitalRead(buttonBpin) == LOW)

        strobe(5);

    }
  }
  if (digitalRead(buttonBpin) == LOW) {

    strobe(5);

  }
}
