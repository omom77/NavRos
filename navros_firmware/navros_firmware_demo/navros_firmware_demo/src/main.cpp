#include <Arduino.h>

// Steps per 360 Rotation - 345

#define EncoderPinA 3
#define EncoderPinB 2
#define mA1 4
#define mA2 5
#define mAEn 6
#define mB1 7
#define mB2 8
#define mBEn 9
volatile long Encodervalue=0;
int rps = 320;    // Rotations per Step
double nRotations;

void updateEncoder()
{
  if (digitalRead(EncoderPinA)> digitalRead(EncoderPinB))
    Encodervalue++;
  else
    Encodervalue--;
}

void forward(int pwma, int pwmb){
  analogWrite(mAEn, pwma);
  analogWrite(mBEn, pwmb);
 
  digitalWrite(mA1, HIGH);
  digitalWrite(mA2, LOW);
   
  digitalWrite(mB1, LOW);
  digitalWrite(mB2, HIGH);
  delay(730); 
   
  digitalWrite(mA1, LOW);
  digitalWrite(mA2, LOW);
  digitalWrite(mB1, LOW);
  digitalWrite(mB2, LOW);
}
void reverse(int pwma, int pwmb){
  analogWrite(mAEn, pwma);
  analogWrite(mBEn, pwmb);

  digitalWrite(mA1, LOW);
  digitalWrite(mA2, HIGH);
  
  digitalWrite(mB1, HIGH);
  digitalWrite(mB2, LOW);
  delay(730);

  digitalWrite(mA1, LOW);
  digitalWrite(mA2, LOW);
  digitalWrite(mB1, LOW);
  digitalWrite(mB2, LOW);
}
void left(int pwma, int pwmb){
  analogWrite(mAEn, pwma);
  analogWrite(mBEn, pwmb);
  
  digitalWrite(mA1, LOW);
  digitalWrite(mA2, LOW);
 
  digitalWrite(mB1, LOW);
  digitalWrite(mB2, HIGH);
  delay(730);

  digitalWrite(mA1, LOW);
  digitalWrite(mA2, LOW);
  digitalWrite(mB1, LOW);
  digitalWrite(mB2, LOW);
}
void right(int pwma, int pwmb){
  analogWrite(mAEn, pwma);
  analogWrite(mBEn, pwmb);
  
  digitalWrite(mA1, HIGH);
  digitalWrite(mA2, LOW);

  digitalWrite(mB1, LOW);
  digitalWrite(mB2, LOW);
  delay(730);

  digitalWrite(mA1,LOW);
  digitalWrite(mA2,LOW);
  digitalWrite(mB1,LOW);
  digitalWrite(mB2,LOW);
}

void setup() {
  pinMode(mA1,OUTPUT);
  pinMode(mA2,OUTPUT);
  pinMode(mAEn,OUTPUT);
  pinMode(mB1,OUTPUT);
  pinMode(mB2,OUTPUT);
  pinMode(mBEn,OUTPUT);
  pinMode(EncoderPinA, INPUT);
  pinMode(EncoderPinB, INPUT);
  attachInterrupt(digitalPinToInterrupt(EncoderPinA), updateEncoder, RISING);
  Serial.begin(115200);
}

void loop() {
    // digitalWrite(mA1,HIGH);
    // digitalWrite(mA2,LOW);
    // analogWrite(mAEn,255);
    int x = Serial.readString().toInt();
    int pwmA = 100;
    int pwmB = 100;
    if(x == 1){
      forward(pwmA, pwmB);
      Serial.print("Forward");
    }
    else if(x == 2){
      reverse(pwmA, pwmB);
      Serial.print("Reverse");
    }
    else if(x == 3){
      left(pwmA, pwmB);
      Serial.print("Left");
    }
    else if(x == 4){
      right(pwmA, pwmB);
      Serial.print("Right");
    }

    nRotations = Encodervalue/rps;

    Serial.print("Encoder Raw Values : ");
    Serial.println(Encodervalue);
    Serial.print("Rotation Values    : ");
    Serial.println(nRotations);
    // delay(100);
    
}
