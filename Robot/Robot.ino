// Copyleft: Lars Age Kamfjord github.com/laaknor
// Date 2015-02-23

#include <IRremote.h> 

const int irPin = 3; 

IRrecv irrecv (irPin);
decode_results results;

//Define Pins
int enableA = 11; // ENA
int pinA1 = 10; // IN2
int pinA2 = 9; // IN1
 
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
      //enableMotors();
      forward(1000);
      //disableMotors();
    } // End if results == FF9867 UP
    else if(results.value == 0xFF30CF) {
      Serial.println("Going LEFT");
      //enableMotors();
      turnLeft(250);
      //disableMotors();
    } // End if results == FF30CF LEFT
    else if(results.value == 0xFF18E7) {
      Serial.println("Going back!");
      //enableMotors();
      backward(500);
      //disableMotors();
    } // End if results == FF18E7 BACK
    else if(results.value == 0xFF7A85) {
      Serial.println("Going RIGHT!");
      //enableMotors();
      turnRight(250);
      //disableMotors();
    } // End if results == FF7A85 RIGHT
    else if(results.value == 0xFFFFFFFF) {
      Serial.println("Holding down - going forward!");
      enableMotors();
      delay(250);
    } // End else if results == FFFFFF
    
//    else disableMotors();
  } // end irrecv.decode
  else {
    disableMotors();
  } // End else irrecv.decode
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

}
 
void motorABackward()
{
 digitalWrite(pinA1, LOW);
 digitalWrite(pinA2, HIGH);
}
 
//motor B contorls
void motorBForward()
{
 digitalWrite(pinB1, HIGH);
 digitalWrite(pinB2, LOW);
}
 
void motorBBackward()
{
 digitalWrite(pinB1, LOW);
 digitalWrite(pinB2, HIGH);
}
 
//coasting and braking
void motorACoast()
{
 digitalWrite(pinA1, LOW);
 digitalWrite(pinA2, LOW);
}
 
void motorABrake()
{
 digitalWrite(pinA1, HIGH);
 digitalWrite(pinA2, HIGH);
}
 
void motorBCoast()
{
 digitalWrite(pinB1, LOW);
 digitalWrite(pinB2, LOW);
}
 
void motorBBrake()
{
 digitalWrite(pinB1, HIGH);
 digitalWrite(pinB2, HIGH);
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
 //delay(time);
}
 
void backward(int time)
{
 motorABackward();
 motorBBackward();
 //delay(time);
}
 
void turnLeft(int time)
{
 motorAForward();
 motorBBackward();
 delay(time);
}
 
void turnRight(int time)
{
 motorABackward();
 motorBForward();
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
