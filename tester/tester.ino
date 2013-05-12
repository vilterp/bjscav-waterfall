
int lowpin = 2;
int highpin = 45;

void setup() {                
  for (int i = lowpin; i <= highpin; i++) {
    pinMode(i, OUTPUT);
  }   
  for(int i=0; i < 35; i++) {
    digitalWrite(i, LOW);
  }
}

void loop() {
//  for (int i = lowpin; i <= highpin; i++) {
//    if (i % 2 == 0) {
//          digitalWrite(i, HIGH);
//
//    } else {
//
//    }
//  }
//  delay(250);
//    for (int i = lowpin; i <= highpin; i++) {
//    if (i % 2 == 0) {
//
//    } else {
//         digitalWrite(i, HIGH);
//
//    }
//    }
//  delay(250);
//    for (int i = lowpin; i <= highpin; i++) {
//    if (i % 2 == 0) {
//          digitalWrite(i, LOW);
//
//    } else {
//
//    }
//  }
//  delay(250);
//    for (int i = lowpin; i <= highpin; i++) {
//    if (i % 2 == 0) {
//
//    } else {
//         digitalWrite(i, LOW);
//
//    }
//    }
//  delay(250);
}

