// ===== SOIL LEVEL MOISTURE RANGE =====
// =====================================
#define L1 169
#define L2 340
#define L3 511
#define L4 682
#define L5 853

// ===== HARDWARE MAPPING =====
// ============================
//relay signalevel for valve
int valve = 8;

// ===== INITIAL LEVEL SETTINGS =====
// ==================================
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

  //print sensor level
  Serial.print(" Nivel de umidade: ");
  Serial.println(sensorValue);

  //identifies humidity level 0
  if(sensorValue > 0 && sensorValue < L1) {
    Serial.println(" Status: Solo TOTALMENTE UMIDO!\n");

    //turn off valve
    digitalWrite(valve,HIGH);
  }
  //identifies humidity level 1
  else if(sensorValue > L1 && sensorValue < L2) {
    Serial.println(" Status: Umidade MEDIA!\n");

    //turn off valve
    digitalWrite(valve,HIGH);
    delay(1000);
  }
  //identifies humidity level 2
  else if(sensorValue > L2 && sensorValue < L3) {
    Serial.println(" Status: Umidade MINIMA!\n");

    //turn off valve
    digitalWrite(valve,HIGH);
    delay(1000);
  }
  //identifies humidity level 3
  else if(sensorValue > L3 && sensorValue < L4) {
    Serial.println(" Status: Solo SECANDO!\n PRONTO PARA INICIAR IRRIGACAO!\n");

    //turn off valve
    digitalWrite(valve,HIGH);
    delay(1000);
  }
  //identifies humidity level 4
  else if(sensorValue > L4 && sensorValue < L5) {
    Serial.println(" Status: Solo QUASE SECO!\n IRRIGANDO!!!\n");

    //turn on valve
    digitalWrite(valve,LOW);
    delay(1000);
  }
  //identifies humidity level 5
  else if(sensorValue > L5 && sensorValue < 1024) {
    Serial.println(" Status: ATENCAO!!! Solo SECO!\n IRRIGANDO!!!\n");

    //turn on valve
    digitalWrite(valve,LOW);
    delay(1000);
  }
  delay(800);
}
