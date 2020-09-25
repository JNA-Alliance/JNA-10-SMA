int in1 = 9;
int in2 = 8;
int in3 = 7;
int in4 = 6;
int ENA = 11;
int ENB = 10;
int speed = 30;

void setup(){
	// Setting mode pin
	pinMode(in1, OUTPUT);
	pinMode(in2, OUTPUT);
	pinMode(in3, OUTPUT);
	pinMode(in4, OUTPUT);
	pinMode(ENA, OUTPUT);
	pinMode(ENB, OUTPUT);

	// Program MAJU selama 5 detik
	digitalWrite(ENA, speed);
	digitalWrite(in1, HIGH);
	digitalWrite(in2, LOW);
	digitalWrite(ENB, speed);
	digitalWrite(in3, HIGH);
	digitalWrite(in4, LOW);
	delay(5000);

	// Program MUNDUR selama 5 detik
	digitalWrite(ENA, speed);
	digitalWrite(in1, LOW);
	digitalWrite(in2, HIGH);
	digitalWrite(ENB, speed);
	digitalWrite(in3, LOW);
	digitalWrite(in4, HIGH);
	delay(5000);

	// Selesai
}

void loop(){
  // ... code
}