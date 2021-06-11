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

// Flag api
bool flag_barusan_ada_api = false;

// Begin logic
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

    // Serial
    Serial.begin(9600);
}

void loop()
{
    // Kumpulkan data
    sensor_api = analogRead(A0);
    Serial.println(sensor_api);

    // Ketika motor dalam keadaan maju dan ada api maka motor akan berhenti dan kipas hidup
    if (sensor_api > 300) {
        // Ada api
        motor_henti();
        digitalWrite(kipas, HIGH);
        flag_barusan_ada_api = true;
    } else if (flag_barusan_ada_api) {
        // Tidak ada api lagi namun barusan ada api
        flag_barusan_ada_api = false;
        motor_mundur();
        delay(2000);
        motor_belok_kanan();
        delay(500); // 90 derajat*
    } else {
        // Tidak ada api, barusan tidak ada api atau sudah belok kanan
        motor_maju();
    }
}