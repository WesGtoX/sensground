// ===== SOIL MOISTURE RANGE =====
#define L1 169
#define L2 340
#define L3 511
#define L4 682
#define L5 853

// ===== HARDWARE MAPPING =====
#define analogi A0
#define digital 15
#define gnd_pin 16
#define vcc_pin 17

#define valve 8                                                       //relay signal for valve

// ===== FUNCTION PROTOTYPE =====
void humidity_reading(int level1, int level2, int level3, int level4, int level5);

// ===== GLOBAL VARIABLES =====
int value_add = 0x00;

// ===== INITIAL SETTINGS =====
void setup() {
    Serial.begin(9600);                                               //starts the serial port, sets the data rate to 9600 bps

    pinMode(analogi, INPUT);
    pinMode(digital, INPUT);
    pinMode(gnd_pin, OUTPUT);
    pinMode(vcc_pin, OUTPUT);

    digitalWrite(gnd_pin, LOW);
    digitalWrite(vcc_pin, HIGH);

    pinMode(valve, OUTPUT);                                           // declares valve as output
}

// ===== LOOP INFINITO =====
void loop() {
    humidity_reading(L1, L2, L3, L4, L5);                             //call function that reads moisture sensor
    delay(741);                                                       //refresh rate
}

// ===== DEVELOPMENT OF FUNCTIONS =====
void humidity_reading(int level1, int level2, int level3, int level4, int level5) {
    value_add = analogRead(analogi);                                  //reads analog and saved signal value in 'value_add'

    Serial.print("Lendo Sensor: ");                                   //print on Serial Monitor
    Serial.print(value_add);                                          //print on Serial Monitor

    if(value_add > 0 && value_add < level1) {                         //identifies humidity level 0
        Serial.println(" Status: solo TOTALMENTE UMIDO!");
        digitalWrite(valve,HIGH);                                     //turn off valve
        delay(1000);
    }

    else if(value_add > level1 && value_add < level2) {               //identifies humidity level 1
        Serial.println(" Status: Umidade MEDIA!");
        digitalWrite(valve,HIGH);                                     //turn off valve
        delay(1000);
    }

    else if(value_add > level2 && value_add < level3) {               //identifies humidity level 2
        Serial.println(" Status: Umidade MINIMA!");
        digitalWrite(valve,HIGH);                                     //turn off valve
        delay(1000);
    }

    else if(value_add > level3 && value_add < level4) {               //identifies humidity level 3
        Serial.println(" Status: Solo SECANDO!\nPRONTO PARA INICIAR IRRIGACAO!");
        digitalWrite(valve,HIGH);                                     //turn off valve
        delay(1000);
    }

    else if(value_add > level4 && value_add < level5) {               //identifies humidity level 4
        Serial.println(" Status: Solo QUASE SECO!\nIRRIGANDO!!!");
        digitalWrite(valve,LOW);                                      //turn on valve
        delay(1000);
    }

    else if(value_add > level5 && value_add < 1024) {                 //identifies humidity level 5
        Serial.println(" Status: ATENCAO!!! Solo SECO!\nIRRIGANDO!!!");
        digitalWrite(valve,LOW);                                      //turn on valve
        delay(1000);
    }
}
