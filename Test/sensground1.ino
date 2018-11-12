//relay signal for valve
int valvula = 8;

void setup() {
  Serial.begin(9600);
  
  //declares valve as output
  pinMode(valvula, OUTPUT);
}

// ===== FUNCTION PROTOTYPE =====
void humidity_reading(int level1);

void loop() {
  //sensor reading on pin A0 and storage in SensorValue
  int sensorValue = analogRead(A0);
  
  //checks if read value is above 600 (humid under 600 and dry up to 1023)
  
  if(sensorValue > 600) {
    //if TRUE, release water.
    Serial.println(" VALVULA LIGADA");
    digitalWrite(valvula,LOW);
    delay(1000);
  }
  else {
    //if FALSE, stop the water flow
    Serial.println(" VALVULA DESLIGADA!");
    digitalWrite(valvula,HIGH);
    delay(1000);
  }
  delay(800);
}