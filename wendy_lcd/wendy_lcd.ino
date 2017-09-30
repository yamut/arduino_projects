#include <LiquidCrystal.h>
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

//Declare globals
int lastButtonState   = LOW;
int currentButton     = false;
int currentNumber     = 0;
int buttonPressCount  = 0;
String decimalString  = "0";
int zeroButton        = A0;
int oneButton         = A1;
int twoButton         = A2;
int threeButton       = A3;
int fourButton        = A4;
int fiveButton        = A5;
int sixButton         = 6;
int sevenButton       = 7;
int eightButton       = 8;
int nineButton        = 9;
int ones                = 0;
bool oneDigitState      = false;
int tens                = 0;
bool tenDigitState      = false;
int hundreds            = 0;
bool hundredDigitState  = false;
int thousands           = 0;
bool thousandDigitState = false;

void setup() {
  // set up the number of columns and rows on the LCD
  lcd.begin(16, 2);
  delay( 2000 );
  lcd.print("Begin");
  //Begin serial output at 9600 baud
  //Serial.begin(9600);
  
  //Need to allow input from the number pins
  pinMode( zeroButton, INPUT );
  pinMode( oneButton, INPUT );
  pinMode( twoButton, INPUT );
  pinMode( threeButton, INPUT );
  pinMode( fourButton, INPUT );
  pinMode( fiveButton, INPUT );
  pinMode( sixButton, INPUT );
  pinMode( sevenButton, INPUT );
  pinMode( eightButton, INPUT );
  pinMode( nineButton, INPUT );
  lcd.clear();
  printOutput();
}

void loop() {
  int zeroState   = digitalRead( zeroButton );
  int oneState    = digitalRead( oneButton );
  int twoState    = digitalRead( twoButton );
  int threeState  = digitalRead( threeButton );
  int fourState   = digitalRead( fourButton );
  int fiveState   = digitalRead( fiveButton );
  int sixState    = digitalRead( sixButton );
  int sevenState  = digitalRead( sevenButton );
  int eightState  = digitalRead( eightButton );
  int nineState   = digitalRead( nineButton );
  // Are we expecting a button to lose state?
  if( lastButtonState == HIGH ){
    //Then determine once the button press has ended
    if( zeroState   == LOW
      && oneState   == LOW
      && twoState   == LOW
      && threeState == LOW
      && fourState  == LOW
      && fiveState  == LOW
      && sixState   == LOW
      && sevenState == LOW
      && eightState == LOW
      && nineState  == LOW ){
        lastButtonState = LOW;
      }
      // We do not want to continue processing here because it could lead to the board reporting multiple button presses, which would seriously bug this out
      // This will end up returning from the loop whether the button has returned or not, but this is to prevent additional processing if it remains pressed during multiple loop calls(highly likely)
      return;
  } else {
    // We are expecting a button to be pressed now because there is no last nutton pressed
    // Quick detection to see if any button has been pressed so we can exit this poll if not and not have contention issues
    if( zeroState   == HIGH
      || oneState   == HIGH
      || twoState   == HIGH
      || threeState == HIGH
      || fourState  == HIGH
      || fiveState  == HIGH
      || sixState   == HIGH
      || sevenState == HIGH
      || eightState == HIGH
      || nineState  == HIGH ){
        lastButtonState = HIGH;
      } else {
        return;
      }
  }
  // If we get here, then we should be able to confidently say that a button has been pressed and this is the first iteration of it being pressed
  if( zeroState == HIGH ){
    attachNumeral( 0 );
  }
  if( oneState == HIGH ){
    attachNumeral( 1 );
  }
  if( twoState == HIGH ){
    attachNumeral( 2 );
  }
  if( threeState == HIGH ){
    attachNumeral( 3 );
  }
  if( fourState == HIGH ){
    attachNumeral( 4 );
  }
  if( fiveState == HIGH ){
    attachNumeral( 5 );
  }
  if( sixState == HIGH ){
    attachNumeral( 6 );
  }
  if( sevenState == HIGH ){
    attachNumeral( 7 );
  }
  if( eightState == HIGH ){
    attachNumeral( 8 );
  }
  if( nineState == HIGH ){
    attachNumeral( 9 );
  }
  printOutput();
}

void attachNumeral( int digit ){
  //Serial.println( digit );
  if( oneDigitState == false ){
    ones = digit;
    oneDigitState = true;
  } else if( tenDigitState == false ){
    tens = digit * 10;
    tenDigitState = true;
  } else if( hundredDigitState == false ){
    hundreds = digit * 100;
    hundredDigitState = true;
  } else if( thousandDigitState == false  ){
    thousands = digit * 1000;
    thousandDigitState = true;
  }
}


void printOutput(){
  
  if( oneDigitState == false && tenDigitState == false && hundredDigitState == false && thousandDigitState == false ){
    lcd.clear();
    lcd.setCursor( 0, 0 );
    lcd.print( "Please input a" );
    lcd.setCursor( 0, 1 );
    lcd.print( "number, up to 4" );
    // No need to continue, just break out
    return;
  }
  
  // Set these after that check to save memory
  String numberOutput = "";
  String equationOutput = "";
  String equalityOutput = "";
  delay( 500 );
  
  equationOutput = thousands + hundreds + tens + ones;
  
  String equationFirstOutput = "";
  String equationSecondOutput = "";
  if( thousands > 0 ){
    equationFirstOutput.concat( equationOutput );
    equationFirstOutput.concat( " " );
    equationFirstOutput.concat( thousands );
    equationFirstOutput.concat( "+" );
    equationFirstOutput.concat( hundreds );
    equationFirstOutput.concat( "+" );
    equationFirstOutput.concat( tens );
    equationSecondOutput.concat( "+" );
    equationSecondOutput.concat( ones );
    equationSecondOutput.concat( "=" );
    equationSecondOutput.concat( equationOutput );
    equationSecondOutput.concat( " Wendy :)" );
  } else if( hundreds > 0 ){
    equationFirstOutput.concat( equationOutput );
    equationFirstOutput.concat( " " );
    equationFirstOutput.concat( hundreds );
    equationFirstOutput.concat( "+" );
    equationFirstOutput.concat( tens );
    equationFirstOutput.concat( "+" );
    equationFirstOutput.concat( ones );
    equationSecondOutput.concat( "=" );
    equationSecondOutput.concat( equationOutput );
  } else if( tens > 0 ){
    equationFirstOutput.concat( equationOutput );
    equationFirstOutput.concat( " " );
    equationFirstOutput.concat( tens );
    equationFirstOutput.concat( "+" );
    equationFirstOutput.concat( ones );
    equationSecondOutput.concat( "=" );
    equationSecondOutput.concat( equationOutput );
  } else {
    equationFirstOutput.concat( equationOutput );
    equationFirstOutput.concat( " " );
    equationFirstOutput.concat( ones );
    equationSecondOutput.concat( "=" );
    equationSecondOutput.concat( equationOutput );
  }
  
  lcd.clear();
  lcd.setCursor( 0, 0 );
  lcd.print( equationFirstOutput );
  lcd.setCursor( 0, 1 );
  lcd.print( equationSecondOutput );
}

