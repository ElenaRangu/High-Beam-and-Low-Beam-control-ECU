const int led1Pin = 9; // Pin pentru LED-ul 1
const int led2Pin = 10; // Pin pentru LED-ul 2
const int led3Pin = 11; // Pin pentru LED-ul 3

int switch1State = 0;
int switch2State = 0;

void setup() {
  pinMode(led1Pin, OUTPUT); // LED 1
  pinMode(led2Pin, OUTPUT); // LED 2
  pinMode(led3Pin, OUTPUT); // LED 3

  Serial.begin(9600); // Inițializare comunicare serială
}

void loop() {
  if (Serial.available() > 0) {
    // Citire date primite prin conexiunea serială
    String message = Serial.readStringUntil('\n');

    // Analizare date și controlare LED-urile în funcție de starea comutatoarelor
    if (message.startsWith("S1:")) {
      int switch1State = message.substring(3, 4).toInt();
      int switch2State = message.substring(7, 8).toInt();

      // Controlul LED-urilor în funcție de starea comutatoarelor
      if (switch1State == 1) {
        analogWrite(led1Pin, 128); // PWM 50%
        analogWrite(led2Pin, 128); // PWM 50%
      } else {
        analogWrite(led1Pin, 0); // LED 1 OFF
        analogWrite(led2Pin, 0); // LED 2 OFF
      }

      if (switch2State == 1) {
        analogWrite(led2Pin, 255); // PWM 100%
        analogWrite(led3Pin, 255); // PWM 100%
      } else {
        analogWrite(led3Pin, 0); // LED 3 OFF
      }
    }
  }
}
