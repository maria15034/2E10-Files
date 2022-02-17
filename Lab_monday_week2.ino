//using PWM to control speed
void setup() 
  Serial.begin(9600);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

//Part 1
  //Pin 5 = Right side PWM
  //Pin 6 = Left side PWM 
  // Goes Forward
/*digitalWrite(8, HIGH); // Right Side
digitalWrite(9, HIGH); // Left Side
delay(5000);
digitalWrite(8, LOW);
digitalWrite(9, LOW);
delay(3000);
// Goes Backwards
digitalWrite(7, HIGH); // Right Side
digitalWrite(10, HIGH); // Left Side
delay(5000);
digitalWrite(7, LOW);
digitalWrite(10, LOW);


//Set all low
delay(3000);
digitalWrite(7, LOW);
digitalWrite(10, LOW);
digitalWrite(8, LOW);
digitalWrite(9, LOW);
delay(3000);

//Left Forward - Right Backward
digitalWrite(7, HIGH);
digitalWrite(9, HIGH);
delay(5000);
digitalWrite(7, LOW);
digitalWrite(9, LOW);
delay(3000);
//Left Backward - Right Forward
digitalWrite(8, HIGH);
digitalWrite(10, HIGH);
delay(5000);
digitalWrite(8, LOW);
digitalWrite(10, LOW);*/


  //Part 2

/*//delay(3000);
digitalWrite(7, LOW);
digitalWrite(10, LOW);
digitalWrite(8, LOW);
digitalWrite(9, LOW);
//delay(3000);

analogWrite(6, 191.25);
digitalWrite(9, HIGH);
delay (3000);
digitalWrite(9, LOW);
delay(1000);

analogWrite(5, 191.25);
digitalWrite(8, HIGH);
delay (3000);
digitalWrite(8, LOW);
delay(1000);

analogWrite(6, 127.5);
digitalWrite(9, HIGH);
delay (3000);
digitalWrite(9, LOW);
delay(1000);

analogWrite(5, 127.5);
digitalWrite(8, HIGH);
delay (3000);
digitalWrite(8, LOW);
delay(1000);

analogWrite(6, 191.25);
analogWrite(5, 191.25);
digitalWrite(10, HIGH);
digitalWrite(8, HIGH);
delay (3000);
digitalWrite(10, LOW);
digitalWrite(8, LOW);
delay(1000);

analogWrite(6, 127.5);
digitalWrite(10, HIGH);
delay (3000);
digitalWrite(10, LOW);
delay(1000);

analogWrite(5, 127.5);
digitalWrite(7, HIGH);
delay (3000);
digitalWrite(7, LOW);
delay(1000);*/



// Part 3
digitalWrite(7, LOW);
digitalWrite(8, LOW);
digitalWrite(9, LOW);
digitalWrite(10, LOW);

  
analogWrite(5, 255);
analogWrite(6, 255);
//Soft turns
digitalWrite(8, HIGH); // Right Side
digitalWrite(9, HIGH); // Left Side
delay(2000);
analogWrite(6, 127.5);
delay(2000);
analogWrite(6, 255);
delay(2000);
analogWrite(5, 127.5);
delay(2000);
analogWrite(5, 255);
delay(2000);

//Hard Turns
digitalWrite(9, LOW);
digitalWrite(10, HIGH);
delay(500);
digitalWrite(10, LOW);
digitalWrite(9, HIGH);
delay(2000);
digitalWrite(8, LOW);
digitalWrite(7, HIGH);
delay(500);
digitalWrite(7, LOW);
digitalWrite(8, HIGH);
delay(2000);


digitalWrite(7, LOW);
digitalWrite(8, LOW);
digitalWrite(9, LOW);
digitalWrite(10, LOW);
delay(4000);

//Reversing turns
digitalWrite(9, LOW);
digitalWrite(8, LOW);
digitalWrite(10, HIGH);
digitalWrite(7, HIGH);
delay(2000);
digitalWrite(10, LOW);
digitalWrite(9, HIGH);
delay(500);
digitalWrite(9, LOW);
digitalWrite(10, HIGH);

delay(2000);
analogWrite(5, 127.5);
delay(2000);
analogWrite(5, 255);
delay(2000);


}
