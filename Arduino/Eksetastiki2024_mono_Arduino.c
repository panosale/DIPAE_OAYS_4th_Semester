; Λύση άσκησης Arduino εξεταστικής Εργαστηρίου ΟΑΥΣ του Εαρ. 2024
; ΠΡΟΣΟΧΗ! Ίσως υπάρχουν κάποια λάθη.
// Arduino
// C++ code
//
#include <LiquidCrystal.h>

#define RED 10
#define BLUE 9
#define GREEN 6
#define BTN 2

int state = 1; // 1, 2, 3, or 4

LiquidCrystal lcd_1(12, 11, 5, 4, 3, 7);

void setup()
{
  pinMode(RED, INPUT);
  pinMode(GREEN, INPUT);
  pinMode(BLUE, INPUT);
  pinMode(BTN, OUTPUT);
  
  lcd_1.begin(16, 1); // Set up the number of columns and rows on the LCD.
  attachInterrupt(digitalPinToInterrupt(BTN), changeState, FALLING);
}
void lightRed() {
  analogWrite(RED, 255);
  analogWrite(GREEN, 0);
  analogWrite(BLUE, 0);
}
void lightBlue() {
  analogWrite(RED, 0);
  analogWrite(GREEN, 0);
  analogWrite(BLUE, 255);
}
void lightPurple() {
  analogWrite(RED, 168);
  analogWrite(GREEN, 0);
  analogWrite(BLUE, 255);
}
void lightGreen() {
  analogWrite(RED, 0);
  analogWrite(GREEN, 255);
  analogWrite(BLUE, 0);
}

void changeState() {
  if (state < 4)
    state++;
  else
    state = 1;
  Serial.println(state);
}

void changeColor(int st) {
  if (st == 1) {
      lightRed();
      lcd_1.clear();
      lcd_1.print("State A");
  }
  else if (st == 2) {
      lightBlue();
      lcd_1.clear();
      lcd_1.print("State B");
  }
  else if (st == 3) {
      lightPurple();
      lcd_1.clear();
      lcd_1.print("State C");
  }
  else if (st == 4) {
      lightGreen();
      lcd_1.clear();
      lcd_1.print("State C");
  }
}

void loop()
{
 changeColor(state);
  delay(100); // Προαιρετικό
}
