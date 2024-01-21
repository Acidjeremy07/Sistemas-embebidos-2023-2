const int analogInput = A0; // Pin para medir el voltaje
float vout = 0.0;
float vin = 0.0;
int value = 0;

// Define los pines para los segmentos de los displays
int segmentPins[] = {2, 3, 4, 5, 6, 7, 8, 9}; // Cambiar según tu configuración
int displayPins[] = {A4, A5}; // Pines para los displays

void setup(){
  pinMode(analogInput, INPUT);
  for (int i = 0; i < 8; i++) {
    pinMode(segmentPins[i], OUTPUT);
  }
  for (int i = 0; i < 2; i++) {
    pinMode(displayPins[i], OUTPUT);
  }
  Serial.begin(9600);
}

void loop(){
  value = analogRead(analogInput);
  vout = (value * 5.0) / 1024.0; // Convierte el valor a voltaje
  vin = vout; // Asume que estás midiendo directamente en el rango de 0-5V
  if (vin < 0.09) {
    vin = 0.0; // Evita valores negativos
  }

  // Muestra el voltaje en los displays
  int decimal = int(vin * 10) % 10;
  int unit = int(vin) % 10;

  // Actualiza los displays
  for (int i = 0; i < 2; i++) {
    digitalWrite(displayPins[i], HIGH);
    if (i == 0) {
      displayNumber(unit);
    } else {
      displayNumber(decimal);
    }
    delay(5); // Tiempo suficiente para que el cambio sea imperceptible
    digitalWrite(displayPins[i], LOW);
  }
}

void displayNumber(int number) {
  // Define los segmentos para cada número (0-9)
  byte numbers[10] = {
    0b00111111, // 0
    0b00000110, // 1
    0b01011011, // 2
    0b01001111, // 3
    0b01100110, // 4
    0b01101101, // 5
    0b01111101, // 6
    0b00000111, // 7
    0b01111111, // 8
    0b01101111  // 9
  };

  for (int i = 0; i < 8; i++) {
    digitalWrite(segmentPins[i], (numbers[number] >> i) & 0x01);
  }
}
