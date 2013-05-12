
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

