const int greenLEDPin = 9;
const int redLEDPin = 10;
const int blueLEDPin = 11;

int isOff = 0;

const int redSensorPin = A0;
const int greenSensorPin = A1;
const int blueSensorPin = A2;

int redValue = 0;
int greenValue = 0;
int blueValue = 0;

int redSensorValue = 0;
int greenSensorValue = 0;
int blueSensorValue = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(greenLEDPin,OUTPUT);
  pinMode(redLEDPin,OUTPUT);
  pinMode(blueLEDPin,OUTPUT);
}

void loop() {
  if(isOff==1){
    return;
  }
  // put your main code here, to run repeatedly:
  redSensorValue = analogRead(redSensorPin);
  delay(5);
  greenSensorValue = analogRead(greenSensorPin);
  delay(5);
  blueSensorValue = analogRead(blueSensorPin);

  Serial.print("Raw sensor values \t R: ");
  Serial.print(redSensorValue);
  Serial.print("\t G: ");
  Serial.print(greenSensorValue);
  Serial.print("\t B: ");
  Serial.println(blueSensorValue);

  redValue = redSensorValue/4;
  greenValue = greenSensorValue/4;
  blueValue = blueSensorValue/4;
  
  Serial.print("Mapped sensor values \t R: ");
  Serial.print(redValue);
  Serial.print("\t G: ");
  Serial.print(greenValue);
  Serial.print("\t B: ");
  Serial.println(blueValue);

  analogWrite(redLEDPin,1023);
  analogWrite(greenLEDPin,1023);
  analogWrite(blueLEDPin,1023);

  delay(10000);
  analogWrite(redLEDPin,0);
  analogWrite(greenLEDPin,0);
  analogWrite(blueLEDPin,0);
  isOff=1;
  
  
}
