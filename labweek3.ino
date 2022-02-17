//simple code to get the buggy wheels going forward and backwards,
//no PWM to control speed involved yet
void setup() {
  
  Serial.begin(9600);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);

  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
}

void loop() {
  //right wheel
  digitalWrite(5,LOW);
  delay(5000);
  digitalWrite(5,LOW);
  delay(1000);
  digitalWrite(6,LOW);
  delay(5000);
  digitalWrite(6,LOW);
  delay(1000);
  //5 high goes forward
  //6 high goes backward

  //left wheel
  digitalWrite(9,LOW);
  delay(5000);
  digitalWrite(9,LOW);
  delay(1000);
  digitalWrite(10,HIGH);
  delay(5000);
  digitalWrite(10,HIGH);
  delay(1000);
  //9 high goes forward
  //10 high goes backward
  
}
