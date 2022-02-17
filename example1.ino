//IR Sensor code

// The D0 of the Eye sensor is connected to Arduino pin D2
const int LEYE = 2;


void setup() {
  Serial.begin( 9600 );
  pinMode(LEYE, INPUT);
}

void loop() {
  bool all_clear = digitalRead( LEYE );
  
  if( !all_clear ){
    Serial.println("I see a line!");
  }else{
    Serial.println("Looks clear to me");
  }
  delay( 1000 );
}
