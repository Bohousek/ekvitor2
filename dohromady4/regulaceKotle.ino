void regulaceKotle() {
  if(voda < dolni) {
    digitalWrite(kotel, HIGH);
    digitalWrite(kotled, HIGH);
  }
  else if(voda > horni) {
    digitalWrite(kotel, LOW);
    digitalWrite(kotled, LOW);
  }
}
