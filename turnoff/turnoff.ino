
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

int iter = 0;
void loop() {
  for(int i=0; i < 35; i++) {
    digitalWrite(i, iter % 2 == 0 ? HIGH : LOW);
  }  
  iter++;
  delay(500);
}
