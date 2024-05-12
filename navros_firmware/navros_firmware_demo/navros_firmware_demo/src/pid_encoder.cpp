// #include <Arduino.h>
// #include <util/atomic.h> // For the ATOMIC_BLOCK macro

// //// Make sure you connect the output pins of the encoder to pins with interrupts 
// //// (for an Arduino Uno that means pins 2 and 3)
// #define ENCA 2  // YELLOW
// #define ENCB 3  // WHITE
// #define PWM 6   // En1 pin   
// #define IN2 4   // IN1 Pin
// #define IN1 5   // IN2 Pin

// volatile int posi = 0; // specify posi as volatile: https://www.arduino.cc/reference/en/language/variables/variable-scope-qualifiers/volatile/
// long prevT = 0;
// float eprev = 0;
// float eintegral = 0;
// // int target;   // Target position

// void setMotor(int dir, int pwmVal, int pwm, int in1, int in2){
//   analogWrite(pwm,pwmVal);
//   if(dir == 1){
//     digitalWrite(in1,HIGH);
//     digitalWrite(in2,LOW);
//   }
//   else if(dir == -1){
//     digitalWrite(in1,LOW);
//     digitalWrite(in2,HIGH);
//   }
//   else{
//     digitalWrite(in1,LOW);
//     digitalWrite(in2,LOW);
//   }  
// }

// void readEncoder(){
//   int b = digitalRead(ENCB);
//   if(b > 0){
//     posi++;
//   }
//   else{
//     posi--;
//   }
// }

// void setup() {
//   Serial.begin(9600);   // Initialize serial monitor

//   pinMode(ENCA,INPUT);
//   pinMode(ENCB,INPUT);
//   attachInterrupt(digitalPinToInterrupt(ENCA),readEncoder,RISING);
  
//   pinMode(PWM,OUTPUT);
//   pinMode(IN1,OUTPUT);
//   pinMode(IN2,OUTPUT);
  
//   Serial.println("target pos");
// }

// void loop() {

//   // set target position
//   // while (Serial.available() == 0) {
//   // }
//   // String t = Serial.parseString();
//   // target = t.toInt();
//   // target = target + totarget;
//   // int target = 250*sin(prevT/1e6);
//   // int target = 180;
  
//   while (!Serial.available()) {
//   }
//   // Once data is available, read the target position from the Serial monitor
//   int target = Serial.readString().toInt();

//   // PID constants
//   float kp = 1;
//   float kd = 0.02;
//   float ki = 0.0;

//   // time difference
//   long currT = micros();
//   float deltaT = ((float) (currT - prevT))/( 1.0e6 );
//   prevT = currT;

//   // Read the position in an atomic block to avoid a potential
//   // misread if the interrupt coincides with this code running
//   // see: https://www.arduino.cc/reference/en/language/variables/variable-scope-qualifiers/volatile/
//   int pos = 0; 
//   ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
//     pos = posi;
//   }
  
//   // error
//   int e = pos - target;

//   // derivative
//   float dedt = (e-eprev)/(deltaT);
//   Serial.println(dedt);

//   // integral
//   eintegral = eintegral + e*deltaT;
//   Serial.println(eintegral);

//   // control signal
//   float u = kp*e + kd*dedt + ki*eintegral;
//   Serial.println(u);

//   // motor power
//   float pwr = fabs(u);
//   if( pwr > 255 ){
//     pwr = 255;
//   }

//   // motor direction
//   int dir = 1;
//   if(u<0){
//     dir = -1;
//   }

//   // signal the motor
//   setMotor(dir,pwr,PWM,IN1,IN2);


//   // store previous error
//   eprev = e;

//   // Serial.print(target);
//   // Serial.print(" ");
//   // Serial.print(pos);
//   // Serial.println();
//   Serial.print("New target position received: ");
//   Serial.println(target);
// }

