/*
  TB6612FNG H-Bridge Demo
  TB6612-Demo.ino
  Demonstrates use of TB6612FNG H-Bridge Motor Controller
  Drives two DC Motors

  DroneBot Workshop 2019
  https://dronebotworkshop.com
*/

// Motor A

int pwmA = 6;
int in1A = 4;
int in2A = 5;

// Motor B

int pwmB = 6;
int in1B = 7;
int in2B = 8;

// Speed control potentiometers

int SpeedControl1 = A0;  
int SpeedControl2 = A1;


// Motor Speed Values - Start at zero

int MotorSpeed1 = 0;
int MotorSpeed2 = 0;

void setup()

{

  // Set all the motor control pins to outputs

  pinMode(pwmA, OUTPUT);
  pinMode(pwmB, OUTPUT);
  pinMode(in1A, OUTPUT);
  pinMode(in2A, OUTPUT);
  pinMode(in1B, OUTPUT);
  pinMode(in2B, OUTPUT);
   
}

void loop() {
  
  // Set Motor A forward

  digitalWrite(in1A, HIGH);
  digitalWrite(in2A, LOW);

 // Set Motor B forward

  digitalWrite(in1B, HIGH);
  digitalWrite(in2B, LOW);
  
  
  // Read potentiometers and convert to range of 0-255
  
  MotorSpeed1 = map(analogRead(SpeedControl1), 0, 1023, 0, 255);
  MotorSpeed2 = map(analogRead(SpeedControl2), 0, 1023, 0, 255);  
     
  
  // Set the motor speeds
  
  analogWrite(pwmA, MotorSpeed1);
  analogWrite(pwmB, MotorSpeed2);
  
}
//#include <Arduino.h>
//#include <util/atomic.h> // For the ATOMIC_BLOCK macro
//
//// Make sure you connect the output pins of the encoder to pins with interrupts 
//// (for an Arduino Uno that means pins 2 and 3)
//#define ENCA 2 // YELLOW
//#define ENCB 3 // PWM WHITE
//
//volatile int posi = 0; // specify posi as volatile
//
//void readEncoder(){
//  int b = digitalRead(ENCB);
//  if(b > 0){
//    posi++;
//  }
//  else{
//    posi--;
//  }
//}
//
//void setup() {
//  Serial.begin(9600);
//  pinMode(ENCA,INPUT);
//  pinMode(ENCB,INPUT);
//  attachInterrupt(digitalPinToInterrupt(ENCA),readEncoder,RISING);
//}
//
//void loop() {
//  // Read the position in an atomic block to avoid a potential
//  // misread if the interrupt coincides with this code running
//  // see: https://www.arduino.cc/reference/en/language/variables/variable-scope-qualifiers/volatile/
//  int pos = 0; 
//  ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
//    pos = posi;
//  }
//  
//  Serial.println(pos);
//}
//// Code 2
