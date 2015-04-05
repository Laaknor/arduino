int ledPins[] = {4,5,6,7,8,9,10,11,12}; //Array with output pins

short delayTime = 100;

void setup()
{
  //Set up pins to output, the easy way.
  int index;
  for (index = 0; index <= 8; index++)
  {
    pinMode(ledPins[index],OUTPUT);
  }

}

void loop()
{
  int index;
  
  //Light the rows red
  for (index = 0; index <= 2; index++)
  {
    digitalWrite(ledPins[index], HIGH);
    delay(delayTime);

  }
  //Turn them off again
  for (index = 0; index <= 2; index++)
  {
    digitalWrite(ledPins[index], LOW);
    delay(delayTime);

  }
  //Light the rows green
  for (index = 3; index <= 5; index++)
  {
    digitalWrite(ledPins[index], HIGH);
    delay(delayTime);

  }
  //Turn them off again
  for (index = 3; index <= 5; index++)
  {
    digitalWrite(ledPins[index], LOW);
    delay(delayTime);

  }
  //Light the rows blue
  for (index = 6; index <= 8; index++)
  {
    digitalWrite(ledPins[index], HIGH);
    delay(delayTime);

  }
  //Turn them off again
  for (index = 6; index <= 8; index++)
  {
    digitalWrite(ledPins[index], LOW);
    delay(delayTime);

  }
}



