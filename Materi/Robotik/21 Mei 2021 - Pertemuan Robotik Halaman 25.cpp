/**
 * Nomor 1
 */
int sensor_api;

void setup() 
{
    Serial.begin(9600);
}

void loop()
{
    sensor_api = analogRead(A0);
    Serial.println(sensor_api);

    if (sensor_api > 300) {
        motor_henti();
        Serial.println("ADA API");
    } else {
        motor_maju();
        Serial.println("AMAN");
    }
}

/**
 * Nomor 2
 */
int trigger = 11;
int echo = 12;
long durasi, jarak;

void setup() 
{
    pinMode(trigger, OUTPUT);
    pinMode(echo, INPUT);
    Serial.begin(9600);
}

void loop()
{
    digitalWrite(trigger, LOW);
    delayMicroseconds(8);
    digitalWrite(trigger, HIGH);
    delayMicroseconds(8);
    digitalWrite(trigger, LOW);
    delayMicroseconds(8);

    durasi = pulseIn(echo, HIGH);
    jarak = (durasi / 2) / 29.1;
    Serial.println(jarak);

    if (jarak <= 10) {
        motor_mundur();
        delay(2000);
    } else {
        motor_maju();
        Serial.println("AMAN");
    }
}