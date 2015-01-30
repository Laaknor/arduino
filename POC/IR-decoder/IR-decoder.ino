/* Download from https://github.com/shirriff/Arduino-IRremote */
/* Newer Arduino-versions; have to remove/move ProgramFiles\Arduino\libraries\RobotIRremote out of folder */
#include <IRremote.h>



const int irPin = 3;

IRrecv irrecv (irPin);
decode_results results;


void setup()
{
  Serial.begin (9600);
  irrecv.enableIRIn();
}

void showIRProtocol (decode_results * results) {
  Serial.print("Protocol:");
  
  switch(results-> decode_type) {
     case NEC:
       Serial.print("NEC");
       break;
     case SONY:
       Serial.print("SONY");
       break;
     case RC5:
       Serial.print("RC5");
       break;
     case RC6:
       Serial.print("RC6");
       break;
     default:
       Serial.print("Unknown encoding");
  } // End switch
  Serial.print(", irCode: ");
  Serial.print(results->value, HEX); // Infrared code
  Serial.print(",    bits: ");
  Serial.println(results->bits); // Number of bits infrared
} // End function

void loop() {
  if(irrecv.decode(& results)) {
    showIRProtocol(& results);
    irrecv.resume();
  } // End if
} // end loop
  
