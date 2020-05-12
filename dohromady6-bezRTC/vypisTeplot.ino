void vypisVzduchu() {
  digitalWrite(ledblik, HIGH);
  File soubor = SD.open("test1.txt", FILE_WRITE);         // otevře soubor na SD kartě pro zápis (případně ho vytvoří)
  soubor.print(vzduch);               // teplota vzduchu
  soubor.print(", ");
  soubor.println(voda);               // teplota vody
  soubor.close();                                         // uloží a zavře soubor na SD kartě
  Serial.print(vzduch);               // teplota vzduchu
  Serial.print(", ");
  Serial.println(voda);               // teplota vody*/
  digitalWrite(ledblik, LOW);
}
void vypisVody() {
  Serial.print("     ");
  Serial.print(", ");
  Serial.println(voda);
}
