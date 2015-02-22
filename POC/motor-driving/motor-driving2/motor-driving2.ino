// ****** Infrared remote intelligent vehicle program ******* 
 #include <IRremote.h> 
 int RECV_PIN = 3; 
 
 int pinLB = 6 ;// define interfaces I1 
 int pinLF = 9 ;// define I2 interfaces 
 int pinRB = 3 ;// define I3 Interface 
 int pinRF = 5 ;// define I4 Interface 
 
 //Define Pins
int enableA = 2;
int pinA1 = 1;
int pinA2 = 0;
 
int enableB = 7;
int pinB1 = 6;
int pinB2 = 5;
 
 // ****** Infrared control section ******** 
 long advence = 0xFF02FD; 
 long back = 0xFFA857; 
 long stop = 0xFFE21D; 
 long left = 0xFFE01F; 
 long right = 0xFF906F; 

 IRrecv irrecv (RECV_PIN); 
 decode_results results; 
 
 void dump (decode_results * results) { 
   int count = results-> rawlen; 
   if (results-> decode_type == UNKNOWN) 
     { 
      Serial.println ("Could not decode message"); 
     } 
   else 
    { 
     if (results-> decode_type == NEC) 
       { 
        Serial.print ("Decoded NEC:"); 
       } 
     else if (results-> decode_type == SONY) 
       { 
        Serial.print ("Decoded SONY:"); 
       } 
     else if (results-> decode_type == RC5) 
       { 
        Serial.print ("Decoded RC5:"); 
       } 
     else if (results-> decode_type == RC6) 
       { 
        Serial.print ("Decoded RC6:"); 
       } 
      Serial.print (results-> value, HEX); 
      Serial.print ("("); 
      Serial.print (results-> bits, DEC); 
      Serial.println ("bits)"); 
    } 
      Serial.print ("Raw ("); 
      Serial.print (count, DEC); 
      Serial.print ("):"); 

   for (int i = 0; i <count; i++) 
      { 
       if ((i% 2) == 1) { 
       Serial.print (results-> rawbuf [i] * USECPERTICK, DEC); 
      } 
     else   
      { 
       Serial.print (- (int) results-> rawbuf [i] * USECPERTICK, DEC); 
      } 
     Serial.print (""); 
      } 
       Serial.println (""); 
      } 

 void setup () 
   { 
     pinMode(RECV_PIN, INPUT);
pinMode(enableA, OUTPUT);
 pinMode(pinA1, OUTPUT);
 pinMode(pinA2, OUTPUT);
 
 pinMode(enableB, OUTPUT);
 pinMode(pinB1, OUTPUT);
 pinMode(pinB2, OUTPUT);
  
 Serial.begin (9600); 
   irrecv.enableIRIn (); // Start the receiver 
   } 

 int on = 0; 
 unsigned long last = millis (); 

 void loop () 
 { 
    if (irrecv.decode (& results)) 
    { 
     // If it's been at least 1/4 second since the last 
     // IR received, toggle the relay 
//     if (millis () - last> 250) 
//       { 
//        on = on!; 
 //         digitalWrite (8, on HIGH:? LOW); 
//        digitalWrite (13, on HIGH:? LOW); 
//        dump (& results); 
//       } 
     if (results.value == advence) {
       forward(500);
     }
     if (results.value == back) 
    {backward(500);} 

     if (results.value == left) 
     {turnLeft(500);} 


     if (results.value == right) 
     {turnRight(500); }

     if (results.value == stop) 
     { 
      brake(500);
      } 
          
     last = millis ();       
     irrecv.resume (); // Receive the next value 
   } // End if decode
 } // End loop


//enable motors
void motorAOn()
{
 digitalWrite(enableA, HIGH);
}
 
void motorBOn()
{
 digitalWrite(enableB, HIGH);
}
 
 //disable motors
void motorAOff()
{
 digitalWrite(enableB, LOW);
}
 
void motorBOff()
{
 digitalWrite(enableA, LOW);
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
