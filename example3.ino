const int LEYE = 2;
volatile int count = 0;

void setup() {
  Serial.begin(9600);
  attachInterrupt( digitalPinToInterrupt(LEYE), ir_isr, RISING);
  pinMode(LEYE, INPUT);
}

void ir_isr(){
  count = count + 1;
}

void loop() {
   delay( 1000 );
   Serial.print("IR counter: ");
   Serial.println( count );
}
