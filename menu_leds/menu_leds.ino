// Definiciones de los pines
const int buttonPin1 = A1; // Botón 1 conectado al pin A1
const int buttonPin2 = A2; // Botón 2 conectado al pin A2
const int ledPins[] = {2, 3, 4, 5, 6, 7, 8}; // Pines de los LEDs

// Variables para almacenar el estado de los botones
int buttonState1 = 0;
int buttonState2 = 0;

// Variables para controlar el estado actual
bool isFast = false;
bool alternatePattern = false;

int button2PressCount = 0;  // Variable para contar las presiones del botón 2

void setup() {
  // Inicializar los pines de los LEDs como salida
  for (int i = 0; i < 7; i++) {
    pinMode(ledPins[i], OUTPUT);
  }

  // Inicializar los pines de los botones como entrada
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
}

void loop() {
  // Leer el estado actual de los botones
  int currentButtonState1 = digitalRead(buttonPin1);
  int currentButtonState2 = digitalRead(buttonPin2);

  if (currentButtonState1 == HIGH && currentButtonState2 == HIGH) {
    // Estado 11
    alternatePattern = true;
    isFast = false;
    button2PressCount = 0;  // Restablecer el contador del botón 2
    patternState11();
  } else if (currentButtonState1 == HIGH) {
    // Estado 10
    alternatePattern = true;
    isFast = false;
    button2PressCount = 0;  // Restablecer el contador del botón 2
    patternState10();
  } else if (currentButtonState2 == HIGH) {
    if (isFast) {
      button2PressCount++;
      if (button2PressCount >= 2) {
        // Regresar al estado 00
        isFast = false;
        alternatePattern = false;
        button2PressCount = 0; // Restablecer el contador
      }
    } else {
      isFast = true;
      button2PressCount = 1;
    }
    delay(50); // Retraso para evitar rebotes
  }

  // Ejecutar el patrón de LEDs correspondiente
  if (isFast) {
    fastPattern();
  } else if (!alternatePattern) {
    normalPattern();
  }
}

void normalPattern() {
  for (int i = 0; i < 7; i++) {
    digitalWrite(ledPins[i], HIGH);
    delay(150);  // Ajusta este valor para controlar la velocidad
    digitalWrite(ledPins[i], LOW);
  }
  for (int i = 5; i >= 0; i--) {
    digitalWrite(ledPins[i], HIGH);
    delay(150);  // Ajusta este valor para controlar la velocidad
    digitalWrite(ledPins[i], LOW);
  }
}

void fastPattern() {
  for (int i = 0; i < 7; i++) {
    digitalWrite(ledPins[i], HIGH);
    delay(50);  // Velocidad más rápida
    digitalWrite(ledPins[i], LOW);
  }
  for (int i = 5; i >= 0; i--) {
    digitalWrite(ledPins[i], HIGH);
    delay(50);  // Velocidad más rápida
    digitalWrite(ledPins[i], LOW);
  }
}
void patternState10() {
  while (digitalRead(buttonPin1) == LOW && digitalRead(buttonPin2) == LOW) {
    for (int i = 0; i < 4; i++) {
      setAllLedsLow();
      digitalWrite(ledPins[i], HIGH);
      digitalWrite(ledPins[6 - i], HIGH);
      delay(200);
    }
    for (int i = 2; i > 0; i--) {
      setAllLedsLow();
      digitalWrite(ledPins[i], HIGH);
      digitalWrite(ledPins[6 - i], HIGH);
      delay(200);
    }
  }
}

void setAllLedsLow() {
  for (int i = 0; i < 7; i++) {
    digitalWrite(ledPins[i], LOW);
  }
}

void patternState11() {
  while (digitalRead(buttonPin1) == LOW && digitalRead(buttonPin2) == LOW) {
    // Secuencia de izquierda a derecha
    for (int i = 6; i >= 0; i--) {
      setAllLedsLow();
      digitalWrite(ledPins[i], HIGH);
      delay(200);
    }
    // Secuencia de derecha a izquierda
    for (int i = 1; i < 7; i++) {
      setAllLedsLow();
      digitalWrite(ledPins[i], HIGH);
      delay(200);
    }
  }
}

