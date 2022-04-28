#include <WiFiNINA.h> 
char ssid[] = "Diarmuids phone";
char pass[] = "Abseethe";
WiFiServer server(80);

char inP = 'S';

String message;
String sendOut;

float PWM = 191.25;

unsigned long timeStopped = 0;
float timeCleared = 0;
float timeSecs = 0;

int looper = 1;

const int US_TRIG = 3;
const int US_ECHO = 2;
const int LEYE = 11;
const int REYE = 12;
const int L_pow = 6;
const int R_pow = 5;
const int L_forw = 10;
const int R_forw = 7;

int count = 0;
int Status = 0;

int distance = 25;
long duration;

int L_Val = HIGH;
int R_Val = HIGH;

int Stopped = 0;


void setup() {
  Serial.begin(9600);
  
  pinMode( LEYE, INPUT );
  pinMode( REYE, INPUT );
  pinMode(R_pow, OUTPUT);
  pinMode(L_pow, OUTPUT);
  pinMode(L_forw, OUTPUT);
  pinMode(R_forw, OUTPUT);
  pinMode(US_TRIG, OUTPUT);
  pinMode(US_ECHO, INPUT);
 
  
  WiFi.begin(ssid, pass);
  IPAddress ip = WiFi.localIP();
  /*Serial.print("IP Address:");
  Serial.println(ip);*/
  server.begin();
}

void loop() {

  reader();
  
  if(inP == '1'){
    //Serial.println("'GO' button test (1)");
    
    count = sonar(count);

    eyes();
  
    drive();
    
    count = count + 1;
    //Serial.println(count);
  }
  
  if(inP == '0'){
    digitalWrite(L_forw, LOW);
    digitalWrite(R_forw, LOW);
    analogWrite(L_pow, 0);
    analogWrite(R_pow, 0);
    //Serial.println("'STOP' button test (7)");
  }
 
}



int sonar(int count){

   if(count == 75){
    //Serial.println("Echo loop test - 1 (2)");
    digitalWrite( US_TRIG, LOW );
    delayMicroseconds(2);
    digitalWrite( US_TRIG, HIGH );
    delayMicroseconds( 10 );
    digitalWrite( US_TRIG, LOW );

    duration = pulseIn( US_ECHO, HIGH );

    distance = duration/58;

    //Serial.println(distance);
    //Serial.write('\n');
  
    if(distance <= 10){
      digitalWrite(L_forw, HIGH);
      digitalWrite(R_forw, HIGH);

      if(Stopped == 0){
      shoutStopped();
      }
      
    }else{
      digitalWrite(L_forw, LOW);
      digitalWrite(R_forw, LOW);
      if(Stopped == 1){
      shoutCleared();
      }
    }
    if(distance <= 30 && Stopped == 0){
      if (distance > 22 && PWM <= 225){
        PWM = PWM + 1;
      }
      if (distance < 18 && PWM >= 50){
        PWM = PWM - 1;
      } 
    }
    if(Stopped == 0){
      shoutDistance();
    }
    Serial.println(PWM);
    return 0;
  }
  
}

void eyes(){
   if( digitalRead ( LEYE ) != L_Val ){
   
    L_Val = digitalRead( LEYE );
   }
  
  if(digitalRead ( REYE ) != R_Val ){
    //Serial.println("IR eyes test (4)");
    
    R_Val = digitalRead( REYE );
  }
}

void drive(){
  if(L_Val == HIGH){
    analogWrite(L_pow, PWM);
  }else{
    analogWrite(L_pow, (PWM/3)*2); 
  }
 
  if(R_Val == HIGH){
   //Serial.println("Motor control test (5)");
   analogWrite(R_pow, PWM);
  }else{
   //Serial.println("Motor control test (5.5)");
   analogWrite(R_pow, (PWM/3)*2);
  }
}

void reader(){
    WiFiClient client = server.available();
    inP = client.read();
}

void shoutStopped(){
   WiFiClient client = server.available();

   client.print('#');
   client.print("Stopped for obstacle at ");
   client.print(distance);
   client.write("cm");
   client.print('\n');

   Stopped = 1;
   timeStopped = millis();
}

void shoutCleared(){
  timeCleared = millis() - timeStopped;

  timeSecs = timeCleared * 0.001;
  WiFiClient client = server.available();

  client.print('#');
  client.write("Obstacle cleared after ");
  client.print(timeSecs);
  client.print('s');
  client.print('\n');
  Stopped = 0;
}

void shoutDistance(){
  WiFiClient client = server.available();

  if(distance < 30){
  client.print('#');
  client.print("Distance from Object: ");
  client.print(distance);
  client.print("cm");
  client.print('\n');
  }else{
  client.print('#');
  client.print("Distance from Object: ");
  client.print("30+");
  client.print("cm");
  client.print('\n');
  }
}
