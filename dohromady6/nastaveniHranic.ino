void nastaveniHranic() {
  if(mod == 1) {
    pauza = 5001;
    op = 10;
    digitalWrite(ledA, HIGH);
    digitalWrite(ledB, LOW);
    digitalWrite(ledC, LOW);
    digitalWrite(ledD, LOW);
    if(vzduch < -5) {
      horni = 27;
      dolni = 28;
    }
    else if(-5 <= vzduch < 5) {
      dolni = 26;
      horni = 27;
    }
    else if(5 <= vzduch < 15) {
      dolni = 25;
      horni = 26;
    }
    else if(15 <= vzduch < 25) {
      dolni = 24;
      horni = 25;
    }
    else if(25 <= vzduch < 30){
      dolni = 23;
      horni = 24;
    }
  }
  else if(mod == 2) {
    pauza = 5002;
    op = 20;
    digitalWrite(ledB, HIGH);
    digitalWrite(ledC, LOW);
    digitalWrite(ledD, LOW);
    digitalWrite(ledA, LOW);
    if(vzduch < 10) {
      dolni = 27;
      horni = 28;
    }
    else if(10 <= vzduch < 20) {
      dolni = 26;
      horni = 27;
    }
    else if(20 <= vzduch < 25) {
      dolni = 25;
      horni = 26;
    }
    else if(25 <= vzduch < 30) {
      dolni = 24;
      horni = 25;
    }
    else {
      dolni = 23;
      horni = 24;
    }
  }
  else if(mod == 3) {
    pauza = 5003;
    op = 30;
    digitalWrite(ledC, HIGH);
    digitalWrite(ledD, LOW);
    digitalWrite(ledA, LOW);
    digitalWrite(ledB, LOW);
    if(vzduch < 10) {
      dolni = 27;
      horni = 28;
    }
    else if(10 <= vzduch < 20) {
      dolni = 26;
      horni = 27;
    }
    else if(20 <= vzduch < 25) {
      dolni = 25;
      horni = 26;
    }
    else if(25 <= vzduch < 30) {
      dolni = 24;
      horni = 25;
    }
    else {
      dolni = 23;
      horni = 24;
    }
  }
  else if(mod == 4) {
    pauza = 5004;
    op = 40;
    digitalWrite(ledD, HIGH);
    digitalWrite(ledA, LOW);
    digitalWrite(ledB, LOW);
    digitalWrite(ledC, LOW);
    if(vzduch < 10) {
      dolni = 27;
      horni = 28;
    }
    else if(10 <= vzduch < 20) {
      dolni = 26;
      horni = 27;
    }
    else if(20 <= vzduch < 25) {
      dolni = 25;
      horni = 26;
    }
    else if(25 <= vzduch < 30) {
      dolni = 24;
      horni = 25;
    }
    else {
      dolni = 23;
      horni = 24;
    }
  }
}
