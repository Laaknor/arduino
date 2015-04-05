int ledPins[] = {
  4,5,6,7,8,9,10,11,12};

short delayTime = 100;

void setup()
{
  int index;
  for (index = 0; index <= 8; index++)
  {
    pinMode(ledPins[index],OUTPUT);
  }

}

void loop()
{
  int index;
  for (index = 0; index <= 2; index++)
  {
    digitalWrite(ledPins[index], HIGH);
    delay(delayTime);

  }
  for (index = 0; index <= 2; index++)
  {
    digitalWrite(ledPins[index], LOW);
    delay(delayTime);

  }
  for (index = 3; index <= 5; index++)
  {
    digitalWrite(ledPins[index], HIGH);
    delay(delayTime);

  }
  for (index = 3; index <= 5; index++)
  {
    digitalWrite(ledPins[index], LOW);
    delay(delayTime);

  }
  
  for (index = 6; index <= 8; index++)
  {
    digitalWrite(ledPins[index], HIGH);
    delay(delayTime);

  }
  for (index = 6; index <= 8; index++)
  {
    digitalWrite(ledPins[index], LOW);
    delay(delayTime);

  }
}



