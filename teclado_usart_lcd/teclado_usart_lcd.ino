#include <LiquidCrystal.h>
#include <Keypad.h>

// Definición de pines para la pantalla LCD
const int rs = 7, en = 6, d4 = 8, d5 = 9, d6 = 10, d7 = 11;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// Configuración del teclado matricial
const byte ROWS = 4; // Cuatro filas
const byte COLS = 4; // Cuatro columnas
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {2, 3, 4, 5}; // Conectar a los pines D2, D3, D4, D5
byte colPins[COLS] = {A0, A2, A3, A4}; // Conectar a los pines A0, A2, A3, A4
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

String texto = ""; // Cadena para almacenar los caracteres ingresados
char lastKey = '\0'; // Último botón presionado
unsigned long lastPressTime = 0; // Tiempo de la última presión
const unsigned long doublePressInterval = 250; // Intervalo para doble presión en milisegundos

void setup() {
  lcd.begin(16, 2); // Inicializar la pantalla LCD
  Serial.begin(9600); // Inicializar comunicación serial a 9600 bps
}

void loop() {
  char key = keypad.getKey();
  unsigned long currentTime = millis();
 if (Serial.available() > 0) {
    // Lee la cadena del puerto serial hasta que encuentre un salto de línea.
    texto = Serial.readStringUntil('\n');
    // Limpia la pantalla LCD.
    // Imprime la cadena leída en la pantalla LCD.
    lcd.print(texto);
  }
  if (key) {
    if (key == lastKey && (currentTime - lastPressTime) < doublePressInterval) {
      // Reemplazar el último número por una letra específica
      switch (key) {
        case '1': key = 'E'; break;
        case '2': key = 'F'; break;
        case '3': key = 'G'; break;
        case '4': key = 'H'; break;
        case '5': key = 'I'; break;
        case '6': key = 'J'; break;
        case '7': key = 'K'; break;
        case '8': key = 'L'; break;
        case '9': key = 'M'; break;
        case '0': key = 'N'; break;
        default: break; // No cambiar si no es un número
      }
      if (texto.length() > 0) {
        texto.remove(texto.length() - 1); // Eliminar el último carácter (el número)
      }
      lastKey = '\0'; // Resetear el último botón
    } else {
      if (lastKey != '\0' && key != lastKey) {
        texto += lastKey; // Agregar el último botón presionado a la cadena
      }
      lastKey = key;
      lastPressTime = currentTime;
    }

    // Agregar el nuevo carácter (letra o número) al final del texto
    texto += key;

    // Si el texto es más largo que 16 caracteres, mantener solo los últimos 16
    if (texto.length() > 16) {
      texto = texto.substring(1);
    }
    lcd.clear();
    lcd.print(texto); // Mostrar el texto en la LCD
    Serial.print(key); // Enviar solo el nuevo carácter al monitor serial
   // Comprobar si hay datos disponibles en el puerto serial
 
  }
}