#include <OneWire.h>
#include <DallasTemperature.h>
#include <SD.h>
#include <DS1307.h>
#include <MemoryFree.h>                         // WiFi vvv
#include <EEPROM.h>

#define ledA 23
#define ledB 25
#define ledC 27
#define ledD 29
String inString;                                // WiFi ^^^

DS1307 rtc(SDA, SCL);
OneWire jedenDrat(40);
DallasTemperature teplomer(&jedenDrat);
DeviceAddress adresaCidla;    // sem si budu ukládat adresy čidel
const int sdkarta = 53;       // SS pin pro modul micro SD karty (na modulu jako CS)
const int kotel = 41;         // relé na ovládání kotle (relé svítí = kotel NETOPÍ)
const int kotled = 39;        // indikační ledka kotle (ledka svítí = kotel TOPÍ)
int i;                        // index (pořadí) čidla na drátě
int mod = 1;                 // mód pro nastavení ekvitermní tabulky, pauzy a opakování
float vzduch;                 // teplota vzduchu (venkovní čidlo)
float voda;                   // teplota vody (čidlo v kotli)
int dolni;                    // dolní hranice teploty vody
int horni;                    // horní hranice teploty vody
int pauza = 0;              // prodleva mezi regulacemi kotle (nebo měřeními teploty vody)
int op;                       // počet opakování cyklu měření vody a regulace kotle

void setup() {
  Serial.begin(74880);                         // WiFi vvv
  Serial3.begin(74880);
  while (!Serial3) {
    ; // čekání na připojení Serial3 (ESP8266)
  }
  pinMode(ledA, OUTPUT);
  pinMode(ledB, OUTPUT);
  pinMode(ledC, OUTPUT);
  pinMode(ledD, OUTPUT);
  digitalWrite(ledA, LOW);
  digitalWrite(ledB, LOW);
  digitalWrite(ledC, LOW);
  digitalWrite(ledD, LOW);                      // WiFi ^^^
  
  rtc.begin();
  rtc.halt(false);
                                // odkomentovat jen pro nastavení času, před dalším nahráváním zakomentovat
  //rtc.setDOW(MONDAY);           // den v týdnu (ANGLICKY) - nevyužívám, ale měl by se nastavovat
  //rtc.setTime(01, 29, 45);      // čas ve 24h formátu (hh, mm, ss)
  //rtc.setDate(23, 3, 2020);     // datum (dd, mm, rrrr)
  
  teplomer.begin();             // spustí knihovny pro měření teploty (DallasTemperature a OneWire)
  pinMode(kotel, OUTPUT);
  pinMode(kotled, OUTPUT);
  SD.begin(sdkarta);
  Serial.println("datum a čas, vzduch[°C], voda[°C]");
  
  voda = mereniVody();
  delay(pauza);
  vypisVody();              // pouze pro kalibraci čidla a první výpis vzduchu
}

void loop() {
  vzduch = mereniVzduchu();
  delay(pauza);
  vypisVzduchu();           // na Serial vypíše čas, teplotu vzduchu i vody, uloží je na SD kartu
  mod = server();
  nastaveniHranic();
  vypisModu();
  delay(pauza);
  for(int j=0; j<op; j++) {
    voda = mereniVody();
    delay(pauza);
    vypisVody();            // na Serial vypíše jen čas a teplotu vody, na SD kartu nic neukládá
    mod = server();
    nastaveniHranic();
    vypisModu();
    regulaceKotle();
  }
}

int server() {                               // WiFi vvv
  while (Serial3.available()) {
    char inChar = Serial3.read();
    Serial.write(inChar);
    inString += inChar;
    if (inChar == ']') {
      if (inString.indexOf("[A]")>0) {
        inString = "";
        return 1;
      }
      else if (inString.indexOf("[B]")>0) {
        inString = "";
        return 2;
      }
      else if (inString.indexOf("[C]")>0) {
        inString = "";
        return 3;
      }
      else if (inString.indexOf("[D]")>0) {
        inString = "";
        return 4;
      }
      else {
        Serial.println("Chyba komunikace mezi Atmega a ESP - zkontroluj přepínače na desce nebo program v ESP.");
        inString = "";
      }
    }
  }
}                                               // WiFi ^^^
