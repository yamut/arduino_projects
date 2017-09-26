#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int lastButtonState = 0;
int currentButton = null;
int currentNumber = 0;
int buttonPressCount = 0;

String decimalString = "0";

int zeroButton  = 6;
int oneButton   = 7;
int twoButton   = 8;
int threeButton = 9;
int fourButton  = 10;
int fiveButton  = A0;
int sixButton   = A1;
int sevenButton = A2;
int eightButton = A3;
int nineButton  = A4;

void setup() {
  // set up the number of columns and rows on the LCD
  lcd.begin(16, 2);
  //Begin serial output at 9600 baud
  Serial.begin(9600);
  //Set the cursor to the top left block, 0 of 15
  printZero(1);
}

void loop() {
  int buttonState = 0;
  if( digitalRead( zeroButton ) == HIGH  && lastButtonState != HIGH ){
    lastButtonState = HIGH;
    Serial.println( "Zero pressed" );
    if( currentNumber == 0 ){
      if( buttonPressCount == 0 ){
        //This is just zero
        printZero();
      }
    } else {
      decimalString.concat("0");
    }
    buttonsPressed++;
  } else if( digitalRead( zeroButton ) == LOW && lastButtonState == HIGH ){
    lastButtonState = LOW;
  }
  if( digitalRead( oneButton ) == HIGH && lastButtonState == LOW ){
    
  }
}

void printZero( int numZeros ){
  //Set cursor to 0 pos, output 0, move down a line, print 0 on both sides

  String zeros = "0";
  if( numZeros > 1 ){
    for( int i = 0; i < numZeros; i++ ){
      zeros.concat("0");
    }
  }
  lcd.setCursor( 0, 0 );
  lcd.print( "0               " );
  lcd.setCursor( 0, 1 );
  lcd.print( "0              0" );
}

void printNums( int decNum ){
  lcd.setCursor( 0, 0 );
  lcd.print( String( decNum ) );
  String binaryOut = "";
  int tempDecNum = decNum;
  while( tempDecNum >= 1 ){
    if( tempDecNum % 2 == 0 ){
      binaryOut.concat( "1" );
    } else {
      binaryOut.concat( "0" );
    }
    tempDecNum = (int)tempDecNum / 2;
  }
  Serial.print( binaryOut );
  Serial.println( " is the binary representation of your number." );
  lcd.setCursor( 0, 1 );
  lcd.print( binaryOut );
}

