// Motor
int in1 = 9;
int in2 = 8;
int in3 = 7;
int in4 = 6;
int ENA = 11;
int ENB = 10;

// Kipas
int kipas = 3;

// Sensor Api
int sensor_api;

// Sensor Ultrasonik
int echo = 5;
int trigger = 4;
long durasi, jarak;

// Flags
bool flag_barusan_ada_api = false;
bool flag_barusan_belok_kanan = false;

void setup() 
{
    // Motor
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
    pinMode(in3, OUTPUT);
    pinMode(in4, OUTPUT);
    pinMode(ENA, OUTPUT);
    pinMode(ENB, OUTPUT);

    // Kipas
    pinMode(kipas, OUTPUT);

    // Sensor Ultrasonik
    pinMode(echo, INPUT);
    pinMode(trigger, OUTPUT);

    // Serial
    Serial.begin(9600);
}

void loop()
{
    // Kumpulkan data
    sensor_api = analogRead(A0);
    Serial.println(sensor_api);

    if (sensor_api > 300) {
        motor_henti();
        digitalWrite(kipas, HIGH);
        flag_barusan_ada_api = true;
    } else if (flag_barusan_ada_api) {
        motor_mundur();
        delay(2000);
        motor_belok_kanan();
        delay(500);
        flag_barusan_ada_api = false;
        flag_barusan_belok_kanan = true;
    } else if (flag_barusan_belok_kanan) {
        digitalWrite(trigger, LOW);
        delayMicroseconds(8);
        digitalWrite(trigger, HIGH);
        delayMicroseconds(8);
        digitalWrite(trigger, LOW);
        delayMicroseconds(8);

        durasi = pulseIn(echo, HIGH);
        jarak = (durasi / 2) / 29.1;
        Serial.println(jarak);

        if (jarak <= 5) {
            motor_mundur();
            delay(1000);
            motor_belok_kanan();
            delay(500);
        }

        flag_barusan_belok_kanan = false;
    } else {
        motor_maju();
    }
}

void motor_nyala()
{
    digitalWrite(ENA, 10);
    digitalWrite(ENB, 10);
}

void motor_maju()
{
    motor_nyala();
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
}

void motor_mundur()
{
    motor_nyala();
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
}

void motor_belok_kanan()
{
    motor_nyala();
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
}

void motor_henti()
{
    digitalWrite(ENA, 0);
    digitalWrite(ENB, 0);
}