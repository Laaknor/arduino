// Yu Hin Hau
// Robotic Car via H-Bridge (L298)
// June 5, 2012
// Modified for infrared by: Lars Age Kamfjord github.com/laaknor

#include <IRremote.h> 

const int irPin = 3; 

IRrecv irrecv (irPin);
decode_results results;

//Define Pins
int enableA = 2; // ENA
int pinA1 = 1; // IN2
int pinA2 = 0; // IN1
 
int enableB = 6; // ENB
int pinB1 = 5; //IN4
int pinB2 = 4; // IN3

void setup() {
 
 pinMode(enableA, OUTPUT);
 pinMode(pinA1, OUTPUT);
 pinMode(pinA2, OUTPUT);
 
 pinMode(enableB, OUTPUT);
 pinMode(pinB1, OUTPUT);
 pinMode(pinB2, OUTPUT);
 irrecv.enableIRIn();
 Serial.begin(9600);
 
} // End setup

 
//command sequence
void loop() {

  if(irrecv.decode(&results)) {
    irrecv.resume();
    if(results.value == 0xFF9867) {
      Serial.println("Going forward!");
      enableMotors();
      forward(1000);
      disableMotors();
    } // End if results == FF9867 UP
    else if(results.value == 0xFF30CF) {
      Serial.println("Going LEFT");
      enableMotors();
      turnLeft(250);
      disableMotors();
    } // End if results == FF30CF LEFT
    else if(results.value == 0xFF18E7) {
      Serial.println("Going back!");
      enableMotors();
      backward(500);
      disableMotors();
    } // End if results == FF18E7 BACK
    else if(results.value == 0xFF7A85) {
      Serial.println("Going RIGHT!");
      enableMotors();
      turnRight(250);
      disableMotors();
    } // End if results == FF7A85 RIGHT
    
//    else disableMotors();
  } // end irrecv.decode
} // End loop
 
//Define Low Level H-Bridge Commands
 
//enable motors
void motorAOn()
{
 digitalWrite(enableA, HIGH);
 Serial.println("enableA=HIGH");
}
 
void motorBOn()
{
 digitalWrite(enableB, HIGH);
 Serial.println("enableB=HIGH");
}
 
 //disable motors
void motorAOff()
{
 digitalWrite(enableA, LOW);
 Serial.println("enableA=LOW");
}
 
void motorBOff()
{
 digitalWrite(enableB, LOW);
 Serial.println("enableB=LOW");
}
 
 //motor A controls
void motorAForward()
{
 digitalWrite(pinA1, HIGH);
 digitalWrite(pinA2, LOW);
 Serial.println("Motor A, HIGH-LOW");
}
 
void motorABackward()
{
 digitalWrite(pinA1, LOW);
 digitalWrite(pinA2, HIGH);
 Serial.println("Motor A, LOW-HIGH");
}
 
//motor B contorls
void motorBForward()
{
 digitalWrite(pinB1, HIGH);
 digitalWrite(pinB2, LOW);
 Serial.println("Motor B, HIGH-LOW");
}
 
void motorBBackward()
{
 digitalWrite(pinB1, LOW);
 digitalWrite(pinB2, HIGH);
 Serial.println("Motor B, LOW-HIGH");
}
 
//coasting and braking
void motorACoast()
{
 digitalWrite(pinA1, LOW);
 digitalWrite(pinA2, LOW);
 Serial.println("Motor A, both LOW");
}
 
void motorABrake()
{
 digitalWrite(pinA1, HIGH);
 digitalWrite(pinA2, HIGH);
 Serial.println("Motor A, both HIGH");
}
 
void motorBCoast()
{
 digitalWrite(pinB1, LOW);
 digitalWrite(pinB2, LOW);
 Serial.println("Motor B, both LOW");
}
 
void motorBBrake()
{
 digitalWrite(pinB1, HIGH);
 digitalWrite(pinB2, HIGH);
 Serial.println("Motor B, both HIGH");
}
 
//Define High Level Commands
 
void enableMotors()
{
 motorAOn();
 motorBOn();
}
 
void disableMotors()
{
 motorAOff();
 motorBOff();
}
 
void forward(int time)
{
 motorAForward();
 motorBForward();
 delay(time);
}
 
void backward(int time)
{
 motorABackward();
 motorBBackward();
 delay(time);
}
 
void turnLeft(int time)
{
 motorABackward();
 motorBForward();
 delay(time);
}
 
void turnRight(int time)
{
 motorAForward();
 motorBBackward();
 delay(time);
}
 
void coast(int time)
{
 motorACoast();
 motorBCoast();
 delay(time);
}
 
void brake(int time)
{
 motorABrake();
 motorBBrake();
 delay(time);
}
