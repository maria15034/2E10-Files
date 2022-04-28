

// CHANGE THESE TO MATCH YOUR WIRING, THEN DELETE THE PREVIOUS "#error" LINE
const int LEYE = 11;
const int REYE = 12;

int L_Val = HIGH;
int R_Val = HIGH;

void setup() {
  Serial.begin(9600);

  pinMode( LEYE, INPUT );
  pinMode( REYE, INPUT );
  pinMode(10, OUTPUT);
  pinMode(7, OUTPUT);
}

void loop() {
   if( digitalRead ( LEYE ) != L_Val ){
    if( digitalRead( LEYE ) == HIGH ){
      Serial.println("low  ");
    }else{
      Serial.println("high ");
    }
    L_Val = digitalRead( LEYE );
  }
  if( digitalRead ( REYE ) != R_Val ){
    if( digitalRead( REYE ) == HIGH ){
      Serial.println("low  ");
    }else{
      Serial.println("high ");
    }
    R_Val = digitalRead( REYE );
  }

 if(L_Val == HIGH){
    digitalWrite(10, HIGH);
  }else{
    digitalWrite(10, LOW);
  }

  if(R_Val == HIGH){
    digitalWrite(7, HIGH);
  }else{
    digitalWrite(7, LOW);
  }
  
  delay(1000);
}
