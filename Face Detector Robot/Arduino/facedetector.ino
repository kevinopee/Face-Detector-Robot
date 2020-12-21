#include<Servo.h>

Servo servoX; //servo untuk sumbu X
Servo servoY; //Servo untuk sumbu Y
int x = 90; //nilai sudut awal untuk servo X
int y = 90; //nilai sudut awal untuk servo Y
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  servoX.attach(9);
  servoY.attach(10);
  servoX.write(x);
  servoY.write(y);
  delay(1000);
}
char input = ""; //variabel serial input
void loop() {
  // put your main code here, to run repeatedly:
 if(Serial.available()){ //Mengecek data serial
  input = Serial.read(); //Read data serial
  if(input == 'U'){
   servoY.write(y+1);    //Merubah nilai sudut servo dari input serial
   y += 1;               // Update nilai sudut servo
  }
  else if(input == 'D'){ 
   servoY.write(y-1);
   y -= 1;
  }
  else{
   servoY.write(y);
  } 
  if(input == 'L'){
  servoX.write(x-1);
  x -= 1;
  } else if(input == 'R'){
  servoX.write(x+1);
  x += 1;
  }
  else{
  servoX.write(x);
  }
  input = "";
  }
}
