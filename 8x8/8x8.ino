#define NUM_ROWS 8
#define NUM_COLS 8

int rows[NUM_ROWS] = {2, 3, 4, 5, 6, 7, 8, 9}; // Conectar a los pines de las filas
int cols[NUM_COLS] = {10, 11, 12, 13, A0, A1, A2, A3}; // Conectar a los pines de las columnas

byte letters[][8] = {
  // H
  {B10000001,
   B10000001,
   B10000001,
   B11111111,
   B10000001,
   B10000001,
   B10000001,
   B10000001},
  // O
  {B01111110,
   B10000001,
   B10000001,
   B10000001,
   B10000001,
   B10000001,
   B10000001,
   B01111110},
  // L
  {B10000000,
   B10000000,
   B10000000,
   B10000000,
   B10000000,
   B10000000,
   B10000000,
   B11111111},
  // A
  {B01111110,
   B10000001,
   B10000001,
   B10000001,
   B11111111,
   B10000001,
   B10000001,
   B10000001}
};

byte buffer[32];

void setup() {
  for (int i = 0; i < NUM_ROWS; i++) {
    pinMode(rows[i], OUTPUT);
  }
  for (int i = 0; i < NUM_COLS; i++) {
    pinMode(cols[i], OUTPUT);
  }
  clearMatrix();
  initBuffer();
}

void loop() {
  for (int i = 0; i < sizeof(buffer) - 8; i++) {
    scrollLeft();
    displayBuffer();
    delay(150);
  }
}

void initBuffer() {
  for (int i = 0; i < 8; i++) {
    buffer[i] = letters[0][i]; // H
    buffer[i + 8] = 0;
    buffer[i + 16] = letters[1][i]; // O
    buffer[i + 24] = 0;
  }
}

void scrollLeft() {
  for (int i = 0; i < sizeof(buffer) - 1; i++) {
    buffer[i] = buffer[i + 1];
  }
  buffer[sizeof(buffer) - 1] = 0;
}

void displayBuffer() {
  for (int col = 0; col < NUM_COLS; col++) {
    digitalWrite(cols[col], HIGH); // Enciende la columna
    for (int row = 0; row < NUM_ROWS; row++) {
      // Invierte el estado ya que es ánodo común
      digitalWrite(rows[row], !(buffer[col] >> row) & 1);
    }
    delay(2);
    digitalWrite(cols[col], LOW); // Apaga la columna
  }
}

void clearMatrix() {
  for (int i = 0; i < NUM_ROWS; i++) {
    digitalWrite(rows[i], LOW);
  }
  for (int i = 0; i < NUM_COLS; i++) {
    digitalWrite(cols[i], HIGH);
  }
}
