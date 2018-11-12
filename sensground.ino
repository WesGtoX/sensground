// ===== SOIL MOISTURE RANGE =====
// ===============================
#define L1 169
#define L2 340
#define L3 511
#define L4 682
#define L5 853

// ===== HARDWARE MAPPING =====
// ============================
//relay signal for valve
int valvula = 8;

// ===== INITIAL SETTINGS =====
// ============================
void setup() {
  Serial.begin(9600);
  
  //declares valve as output
  pinMode(valve, OUTPUT);
}

// ===== LOOP INFINITO =====
// =========================
void loop() {
  //sensor reading on pin A0 and storage in SensorValue
  int sensorValue = analogRead(A0);
  
    //identifies humidity level 0
    if(sensorValue > 0 && sensorValue < level1) {
        Serial.println(" Status: Solo TOTALMENTE UMIDO!");

        //turn off valve
        digitalWrite(valve,HIGH);
    }
    //identifies humidity level 1
    else if(sensorValue > level1 && sensorValue < level2) {
        Serial.println(" Status: Umidade MEDIA!");

        //turn off valve
        digitalWrite(valve,HIGH);
        delay(1000);
    }
    //identifies humidity level 2
    else if(sensorValue > level2 && sensorValue < level3) {
        Serial.println(" Status: Umidade MINIMA!");

        //turn off valve
        digitalWrite(valve,HIGH);
        delay(1000);
    }
    //identifies humidity level 3
    else if(sensorValue > level3 && sensorValue < level4) {
        Serial.println(" Status: Solo SECANDO!\nPRONTO PARA INICIAR IRRIGACAO!");

        //turn off valve
        digitalWrite(valve,HIGH);
        delay(1000);
    }
    //identifies humidity level 4
    else if(sensorValue > level4 && sensorValue < level5) {
        Serial.println(" Status: Solo QUASE SECO!\nIRRIGANDO!!!");

        //turn on valve
        digitalWrite(valve,LOW);
        delay(1000);
    }
    //identifies humidity level 5
    else if(sensorValue > level5 && sensorValue < 1024) {
        Serial.println(" Status: ATENCAO!!! Solo SECO!\nIRRIGANDO!!!");

        //turn on valve
        digitalWrite(valve,LOW);
        delay(1000);
    }
  delay(800);
}