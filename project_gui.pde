import processing.net.*;
import controlP5.*;

PShape rectangle;
String readIn = " ";

int Printed = 0;

ControlP5 p5;
Button GOButton;
Button STOPButton;

Client myClient;
String data;

//Remember to double all gui sizes later!!!
void setup() {
  myClient = new
  Client(this, "192.168.208.242", 80);
  
  size(400, 300);
  p5 = new ControlP5(this);
  Button GOButton = p5.addButton("GO")
    .setValue(0)
    .setPosition(162.5, 25)
    .setSize(50, 50);
  Button STOPButton = p5.addButton("STOP")
    .setValue(0)
    .setPosition(162.5, 85)
    .setSize(50,50);
    
  background(255,255,255);
    
}



void draw(){
  /*data = myClient.readString();
  if(data == "Stopped for obstacle" || data == "Obstacle cleared"){
    
    println(data);
  
  }*/
  
  background(255, 255, 255);
  if(data == "GO"){

   myClient.write("1");
   
 }else if(data == "STOP"){

   myClient.write("0");
   
 }
 
 
  
  textSize(15);
  fill(255,0,0);
  text(readIn, 100, 285);

  /*if(readIn == "cm"){
    fill(255,0,0);
    rect(25, 200, 50, 25);
    fill(255, 50, 50);
    text("STOPPED", 27.5, 202.5);
  }
  
  if(readIn == "s"){
    fill(0,0,255);
    rect(325, 200, 50, 25);
    fill(50, 50, 255);
    text("CLEARED", 327.5, 202.5);
  }*/
}

public void controlEvent( ControlEvent ev ) {
 data = ev.getController().getName();
 
}

void clientEvent(Client myClient){
  readIn = myClient.readString();
  

  
  
}
