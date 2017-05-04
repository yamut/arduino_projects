// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// set up the temperature sensor pin
const int tempPin = A0;

void setup() {
  // set up the number of columns and rows on the LCD
  lcd.begin(16, 2);
  // set up the switch pin as an input
  pinMode(tempPin, INPUT);
  lcd.print("Temperature:");
  lcd.setCursor(0, 1);
}

void loop() {
  int tempVal = analogRead(tempPin);
  float voltage = ( tempVal / 1024.0 ) * 5.0;
  String lcdOutput = String( String( ( ( voltage - .5 ) * 100 ) + 32, 1 ) + String( " F, " ) + String( ( voltage - .5 ) * 100, 1 ) + String( " C" ) );
  lcd.setCursor(0, 1);
  lcd.print(lcdOutput);
  delay(10000);
}
