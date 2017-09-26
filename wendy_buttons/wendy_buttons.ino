int lastButtonState = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(A0, INPUT);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(digitalRead(A0));
  int buttonState = digitalRead(A0);
  if( buttonState != lastButtonState ){
    //Button state has changed, start doing something
    if( buttonState == HIGH ){
      Serial.println("Button is depressed");
    } else {
      Serial.println("Button is raised");
    }
  }
}
