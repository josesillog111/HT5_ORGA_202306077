# 🔌 Proyecto Arduino: Control de Matriz de LEDs vía Comunicación Serial

Este proyecto permite controlar una **matriz de 9 LEDs (3x3)** conectada a un Arduino utilizando comunicación serial desde un programa en **Python**. El usuario puede seleccionar cuál LED encender desde un menú en consola, enviando el número correspondiente del 1 al 9.

## 🛠 Materiales utilizados

- 1 Arduino UNO (o compatible)
- 9 LEDs
- 9 resistencias de 220Ω
- Cables de conexión
- Protoboard
- Conexión por puerto serial (también puede usarse con puertos virtuales como COMx)

## ⚙️ Funcionamiento

- El programa en Python muestra un menú donde se puede seleccionar un LED.
- Al seleccionar una opción (del 1 al 9), se envía un carácter al Arduino por el puerto serial.
- El Arduino interpreta este carácter, apaga todos los LEDs y enciende el seleccionado.

## 🔌 Conexión de pines

| LED  | Pin Arduino |
|------|-------------|
| 1    | 2           |
| 2    | 3           |
| 3    | 4           |
| 4    | 5           |
| 5    | 6           |
| 6    | 7           |
| 7    | 8           |
| 8    | 9           |
| 9    | 10          |

## 🧠 Lógica en Arduino

```cpp
const int numLeds = 9;
int pinesLeds[numLeds] = {2, 3, 4, 5, 6, 7, 8, 9, 10};

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < numLeds; i++) {
    pinMode(pinesLeds[i], OUTPUT);
    digitalWrite(pinesLeds[i], LOW);
  }
}

void loop() {
  if (Serial.available() > 0) {
    char dato = Serial.read();
    if (dato == '\n' || dato == '\r') return;

    int numero = dato - '1';

    if (numero >= 0 && numero < numLeds) {
      for (int i = 0; i < numLeds; i++) {
        digitalWrite(pinesLeds[i], LOW);
      }
      digitalWrite(pinesLeds[numero], HIGH);
    }
  }
}
