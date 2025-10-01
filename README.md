![WhatsApp Image 2025-10-01 at 23 46 22_35140146](https://github.com/user-attachments/assets/bf129445-e274-47ac-bad4-326b18156565)# arduino-rotary-controler
Simple IR remote controlled relay switch for automotive/motorcycle rotary LED lamp (12V).

Implementasi IR receiver dengan relay sebagai saklar elektronik untuk lampu rotary pada aki 12V, terinspirasi dari :
https://github.com/RobotsDinosaurs/Arduino/blob/main/IRRemote/IRRemote.ino

**Tools yang digunakan :**
- Arduino Uno
- Aki (12 Volt - 12 AH/20HR) 
- IR Receveiver (VS1838B Infrared Receiver)
- Fuse Holder & Glass Fuse (250V - 8A)
- Relay 5 Volt
- Alligator Clip (Capit Buaya)
- Kabel Serabut
- Remote CR2025 (Car MP3)

**Wiring & Pin**
1. Arduino - IR Receiver
   - VCC : 5V
   - GND : GND (Arduino)
   - OUT : Pin D7
3. Arduino - Relay
   - IN : Pin D9
   - VCC Relay : VCC (Arduino)
   - GND Relay : Aki GND
4. Relay - Rotary Lamp
   - COM : (+) Aki "Lewat Fuse"
   - NO  : (+) Lampu Lotary
   - NC  : Tidak dipakai
5. Rotary Lamp
   - Positif (+) : **NO** Relay
   - Negatif (-) : GND ke Aki GND
6. Aki 12 Volt
   - Positif (+) : **Fuse** -> **COM** Relay
   - Negatif (-) : GND Rotary dan GND Arduino (GND Disatuin pada lampu rotary, relay, aki)

  Flow Pin Diagram : 
  <img width="1100" height="790" alt="Rotary-IR Receiver" src="https://github.com/user-attachments/assets/2855dae6-90a3-4707-be25-c31d84130c19" />

  Fuse Holder & Glass:
  <img width="906" height="481" alt="Fuse Holder   Glass Fuse" src="https://github.com/user-attachments/assets/e7cab5e5-e4dc-426c-b0d8-3f8bce978f2b" />

  Aki (12 Volt-12AH) :
  ![Aki 12V](https://github.com/user-attachments/assets/5f19495b-6260-4d4b-9521-e8723ba0422b)

Result : 
[![Tonton di YouTube](https://img.youtube.com/vi/h7_SBmNpQno/0.jpg)](https://www.youtube.com/watch?v=h7_SBmNpQno)


**Flow Alat :**
1. Saat Remote CR2025 (Car MP3) di tekan pada angka "5" maka Sensor IR di **Pin 7** akan memberikan kode ke Arduino
2. Jika kode sesuai misal pada program diset angka "5" -> Arduino aktifkan relay lewat **Pin 9**
3. Relay menyambungkan COM (aki+12 Volt) ke NO(Lampu Rotary) -> Lampu Rotary akan menyala
4. Tekan tombol lagi pada remot untuk memutus relay -> relay mati


