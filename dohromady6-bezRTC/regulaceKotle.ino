void regulaceKotle() {
  if(voda < dolni) {
    digitalWrite(kotel, HIGH);
    digitalWrite(ledkotel, LOW);
  }
  else if(voda > horni) {
    digitalWrite(kotel, LOW);
    digitalWrite(ledkotel, HIGH);
  }
}
