int red = 5;
int green = 6;
int blue = 7;


void setup() {
	pinMode(red, OUTPUT);
	pinMode(blue, OUTPUT);
	pinMode(green, OUTPUT);


	digitalWrite(red, LOW);
	digitalWrite(blue, LOW);
	digitalWrite(green, LOW);
}


void loop() {
	digitalWrite(red, HIGH); // RED
	delay(1000);
	digitalWrite(blue, HIGH); // PURPLE
	delay(1000);
	digitalWrite(green, HIGH); // WHITE
	delay(1000);
	digitalWrite(red, LOW); // YELLOW
	delay(1000);
	digitalWrite(green, LOW); // BLUE
	delay(1000);
	digitalWrite(blue, LOW); // blank
} // End loop
