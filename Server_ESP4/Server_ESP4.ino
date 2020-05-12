#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
     
const char* ssid = "RedmiBohousek";
const char* password = "12345678";

ESP8266WebServer server(80);
     
String webPage = "";
     
int ledA = 29;
int ledB = 27;
int ledC = 25;
int ledD = 23;
int pauza = 500;
     
void setup(void){
  pinMode(ledA, OUTPUT);
  pinMode(ledB, OUTPUT);
  pinMode(ledC, OUTPUT);
  pinMode(ledD, OUTPUT);
  digitalWrite(ledA, LOW);
  digitalWrite(ledB, LOW);
  digitalWrite(ledC, LOW);
  digitalWrite(ledD, LOW);
  Serial.begin(74880);
  while (!Serial) {
    ; // čekání na připojení Serial (USB nebo Atmega)
  }
  
  // informace o desce
  Serial.println("");
  Serial.println("ESP8266 board info:");
  Serial.print("\tChip ID: ");
  Serial.println(ESP.getFlashChipId());
  Serial.print("\tCore Version: ");
  Serial.println(ESP.getCoreVersion());
  Serial.print("\tChip Real Size: ");
  Serial.println(ESP.getFlashChipRealSize());
  Serial.print("\tChip Flash Size: ");
  Serial.println(ESP.getFlashChipSize());
  Serial.print("\tChip Flash Speed: ");
  Serial.println(ESP.getFlashChipSpeed());
  Serial.print("\tChip Speed: ");
  Serial.println(ESP.getCpuFreqMHz());
  Serial.print("\tChip Mode: ");
  Serial.println(ESP.getFlashChipMode());
  Serial.print("\tSketch Size: ");
  Serial.println(ESP.getSketchSize());
  Serial.print("\tSketch Free Space: ");
  Serial.println(ESP.getFreeSketchSpace());

  // webová stránka v HTML
  webPage += "<title>ESP8266 server</title>";
  webPage += "<h1>Wemos MEGA</h1>";
  webPage += "<p>elektrokotel:  ";
  webPage += "<a href=\"modA\"><button>&nbsp&nbsp A &nbsp&nbsp</button></a>&nbsp&nbsp";
  webPage += "<a href=\"modB\"><button>&nbsp&nbsp B &nbsp&nbsp</button></a>&nbsp&nbsp";
  webPage += "<a href=\"modC\"><button>&nbsp&nbsp C &nbsp&nbsp</button></a>&nbsp&nbsp";
  webPage += "<a href=\"modD\"><button>&nbsp&nbsp D &nbsp&nbsp</button></a>&nbsp&nbsp</p>";

  // připojení k WiFi
  WiFi.begin(ssid, password);
  Serial.println("");
     
  // čekání na připojení
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Připojeno k síti ");
  Serial.println(ssid);
  Serial.print("IP addresa: ");
  Serial.println(WiFi.localIP());
     
  server.on("/", [](){
    server.send(200, "text/html", webPage);
    digitalWrite(ledA, HIGH);
    digitalWrite(ledB, LOW);
    digitalWrite(ledC, LOW);
    digitalWrite(ledD, LOW);
    delay(pauza/5);
    digitalWrite(ledA, LOW);
    digitalWrite(ledB, HIGH);
    digitalWrite(ledC, LOW);
    digitalWrite(ledD, LOW);
    delay(pauza/5);
    digitalWrite(ledA, LOW);
    digitalWrite(ledB, LOW);
    digitalWrite(ledC, HIGH);
    digitalWrite(ledD, LOW);
    delay(pauza/5);
    digitalWrite(ledA, LOW);
    digitalWrite(ledB, LOW);
    digitalWrite(ledC, LOW);
    digitalWrite(ledD, HIGH);
    delay(pauza/5);
    digitalWrite(ledA, LOW);
    digitalWrite(ledB, LOW);
    digitalWrite(ledC, LOW);
    digitalWrite(ledD, LOW);
  });
  
  server.on("/modA", [](){
    server.send(200, "text/html", webPage);
    digitalWrite(ledA, HIGH);
    digitalWrite(ledB, LOW);
    digitalWrite(ledC, LOW);
    digitalWrite(ledD, LOW);
    Serial.println("[A]");
    delay(pauza);
  });
  
  server.on("/modB", [](){
    server.send(200, "text/html", webPage);
    digitalWrite(ledB, HIGH);
    digitalWrite(ledC, LOW);
    digitalWrite(ledD, LOW);
    digitalWrite(ledA, LOW);
    Serial.println("[B]");
    delay(pauza);
  });

  server.on("/modC", [](){
    server.send(200, "text/html", webPage);
    digitalWrite(ledC, HIGH);
    digitalWrite(ledD, LOW);
    digitalWrite(ledA, LOW);
    digitalWrite(ledB, LOW);
    Serial.println("[C]");
    delay(pauza);
  });

  server.on("/modD", [](){
    server.send(200, "text/html", webPage);
    digitalWrite(ledD, HIGH);
    digitalWrite(ledA, LOW);
    digitalWrite(ledB, LOW);
    digitalWrite(ledC, LOW);
    Serial.println("[D]");
    delay(pauza);
  });
  
  server.begin();
  Serial.println("HTTP server spuštěn");
  Serial.println("");
  Serial.flush();
}
     
void loop(void){
  server.handleClient();
  delay(10);
}
