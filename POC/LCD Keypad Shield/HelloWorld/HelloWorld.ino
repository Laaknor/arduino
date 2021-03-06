// include the library code:
#include <LiquidCrystal.h>

//LCD RS pin to digital pin 8
//LCD Enable pin to digital pin 9
//LCD D4 pin to digital pin 4
//LCD D5 pin to digital pin 5
//LCD D6 pin to digital pin 6
//LCD D7 pin to digital pin 7

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("hello, world!");
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  lcd.print(millis() / 1000);
}

