const int switch1Pin = 4; // Pin pentru comutatorul 1
const int switch2Pin = 5; // Pin pentru comutatorul 2

void setup() {
  pinMode(switch1Pin, INPUT_PULLUP); // Comutatorul 1
  pinMode(switch2Pin, INPUT_PULLUP); // Comutatorul 2
  
  Serial.begin(9600); // Inițializare comunicare serială
}

void loop() {
  // Citire starea comutatoarelor
  int switch1State = digitalRead(switch1Pin);
  int switch2State = digitalRead(switch2Pin);

  // Trimite starea comutatoarelor la Arduino 2 prin conexiunea serială
  Serial.print("S1:");
  Serial.print(switch1State);
  Serial.print("S2:");
  Serial.println(switch2State);

  delay(100); // Mici pauze pentru a reduce traficul serial
}