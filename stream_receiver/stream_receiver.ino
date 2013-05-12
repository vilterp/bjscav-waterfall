int numpins = 35;
int lowpin = 2;
int highpin = lowpin + numpins;

void setup() {
  Serial.begin(9600);    
  for (int i = lowpin; i <= highpin; i++) {
    pinMode(i, OUTPUT);
  }
  Serial.println("starting");
}

int ST_BETWEEN_LINES = 1;
int ST_IN_LINE = 2;
int state = ST_BETWEEN_LINES;

int cur_line[35];

void loop() {
  Serial.println("loop");
  // send data only when you receive data:
	int row_idx = 0;

	if (Serial.available() > 0) {
//                Serial.println("FUUUCKKKKK!!!!!!!!!!!!");
		int incomingByte = Serial.read();
		if(state == ST_BETWEEN_LINES && incomingByte == 10) {
			Serial.println("start line");
			state = ST_BETWEEN_LINES;
			row_idx = 0;
		}
		if(state == ST_IN_LINE) {
			if(incomingByte == 11) {
				row_idx = 0;
				state = ST_BETWEEN_LINES;
				Serial.println("line");
				set_pins(cur_line);
			} else {
				cur_line[row_idx] = incomingByte;
				row_idx++;
			}
		}
	}
}

int idx_offset(int idx) {
	return idx - 2;
}

void set_pins(int *pins) {
	for(int i=0; i < numpins; i++) {
		int level = pins[i] ? HIGH : LOW;
		digitalWrite(idx_offset(i), level);
	}
}

