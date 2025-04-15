const int numLeds = 9;
int pinesLeds[numLeds] = {2, 3, 4, 5, 6, 7, 8, 9, 10};

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < numLeds; i++) {
    pinMode(pinesLeds[i], OUTPUT);
    digitalWrite(pinesLeds[i], LOW); // Apaga todos los LEDs al inicio
  }
}

void loop() {
  if (Serial.available() > 0) {
    char dato = Serial.read();

    // Ignora saltos de línea y retorno de carro
    if (dato == '\n' || dato == '\r') return;

    Serial.print("Recibido: ");
    Serial.println(dato);

    int numero = dato - '1'; // '1' → 0, ..., '9' → 8

    if (numero >= 0 && numero < numLeds) {
      // Apaga todos los LEDs
      for (int i = 0; i < numLeds; i++) {
        digitalWrite(pinesLeds[i], LOW);
      }
      // Enciende el correspondiente
      digitalWrite(pinesLeds[numero], HIGH);
    } else {
      Serial.println("Dato fuera de rango.");
    }
  }
}
