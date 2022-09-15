/*M&V TECHNOLOGIE
 * 
Este ejemplo crea un puente entre Serial y Clasica Bluetooth (SPP)
y también demostrar que SerialBT tiene las mismas funcionalidades de un Serial normal


Pegar en Preferencias - Gestor de URLs adicionales de tarjetas 
https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json

*/


#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("M&V TECHNOLOGIE"); //Nombre de dispositivo Bluetooth 
  Serial.println("El dispositivo comenzó, ¡ahora puedes emparejarlo con bluetooth!");
}

void loop() {
  if (Serial.available()) {
    SerialBT.write(Serial.read());
  }
  if (SerialBT.available()) {
    Serial.write(SerialBT.read());
  }
  delay(20);
}
