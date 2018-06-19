#include "DigiKeyboard.h"

// Initialize Pins
const int  buttonPin = 0;
const int ledPin = 1;

// Initial Values

int buttonPushCounter = 0;   // counter for the number of button presses
int buttonState = 0;         // current state of the button
int lastButtonState = 0;     // previous state of the button

int starttime=0;
int endtime=0;
int count=0;
int temp = 5;

void setup() {
    pinMode(buttonPin, INPUT);
    pinMode(ledPin, OUTPUT);
}

int pushCount()
{
  while ((endtime - starttime) <=5000) // do this loop for up to 1000mS
  {
    buttonState = digitalRead(buttonPin); //Returns HIGH or LOW (true or false / 1 or 0).
    if (buttonState != lastButtonState) 
    {
      if (buttonState==HIGH)
      {
        count = count+1;
        digitalWrite(ledPin, HIGH);
        digitalWrite(ledPin, LOW);
      }
      delay(40);
    }
    endtime = millis();
    lastButtonState = buttonState;
  }
  return count;

}
void loop()
{
  DigiKeyboard.sendKeyStroke(0);
  starttime = millis();
  endtime = starttime;
  count =0;
  count = pushCount();
//  DigiKeyboard.println(count);

  digitalWrite(ledPin, HIGH);
  delay(100);
  digitalWrite(ledPin, LOW);

  if (count == 1)
  {
    DigiKeyboard.println("Nikhil");
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
  }
  if (count == 2)
  {
    DigiKeyboard.println("pass_1");
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
  }
  if (count == 3)
  {
    DigiKeyboard.println("pass_2");
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
  }
  if (count == 4)
  {
    DigiKeyboard.println("pass_3");
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
  }
  
}

