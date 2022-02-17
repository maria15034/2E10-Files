//Code for the ultrasonic sensors
const int US_TRIG = 9;
const int US_ECHO = 8;

// The D0 of the Eye sensor is connected to Arduino pin D2
const int LEYE = 2;


void setup() {
  Serial.begin( 9600 );
  pinMode(US_TRIG, OUTPUT);
  pinMode(US_ECHO, INPUT);
}

void loop(){

  int distance;
  long duration;

  digitalWrite( US_TRIG, LOW );
  delayMicroseconds(2);
  digitalWrite( US_TRIG, HIGH );
  delayMicroseconds( 10 );
  digitalWrite( US_TRIG, LOW );

  duration = pulseIn( US_ECHO, HIGH );

  distance = duration/58;

  Serial.print("Distance detected: ");
  Serial.print( distance );
  Serial.println(" cm");
}
