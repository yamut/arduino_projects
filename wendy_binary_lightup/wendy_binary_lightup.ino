int countTo = 200;
int currentCount = 0;

void setup() {
  Serial.begin(19200);
  // put your setup code here, to run once:
  pinMode(1,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  delay(2000);
  Serial.print("Value of countTo is " );
  Serial.println( countTo );
  Serial.print("Value of currentCount is " );
  Serial.println( currentCount );
  for( int i = 0; i<= countTo; i++){
    lightLeds(i);
    delay(1000);
  }
}

void loop() {
}

void lightLeds( int num ){
  //Try to light the leds as a binary representation of the numbers
  for( int i = 2; i <= 10; i++ ){
    if( num%2==0 ){
      digitalWrite(i, LOW);
    } else {
      digitalWrite(i, HIGH);
    }
    num/=2;
  }
  
}

