#include <Arduino.h>
#include <IRremote.hpp>

const int IR_RECEIVE_PIN = 7;  
const int relayPin = 9;        // Relay IN dihubungkan ke pin 9
const unsigned long kodeTombol5 = 0xE31CFF00; // Ganti sesuai kode remote-mu

bool lampuStatus = false; // Menyimpan status lampu (OFF awalnya)

void setup() {
  Serial.begin(9600);
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK); 
  pinMode(relayPin, OUTPUT);

  // Inisialisasi relay: HIGH = OFF (asumsi relay aktif LOW)
  digitalWrite(relayPin, HIGH);
}

void loop() {
  if (IrReceiver.decode()) {
    unsigned long kode = IrReceiver.decodedIRData.decodedRawData;
    Serial.print("Kode: ");
    Serial.println(kode, HEX);

    if (kode == kodeTombol5) {
      lampuStatus = !lampuStatus;  // Toggle status lampu

      if (lampuStatus) {
        Serial.println("Lampu Rotary ON");
        digitalWrite(relayPin, LOW);   // Aktifkan relay (active LOW)
      } else {
        Serial.println("Lampu Rotary OFF");
        digitalWrite(relayPin, HIGH);  // Matikan relay
      }

      delay(500); // Debounce sederhana agar tidak double trigger
    }

    IrReceiver.resume(); // Siap baca kode berikutnya
  }
}
