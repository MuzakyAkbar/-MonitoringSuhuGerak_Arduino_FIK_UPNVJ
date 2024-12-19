# -MonitoringSuhuGerak_Arduino_FIK_UPNVJ
Proyek ini merupakan simulasi sistem monitoring suhu dan deteksi gerak berbasis Arduino yang diimplementasikan pada pintu masuk Fakultas Ilmu Komputer UPN Veteran Jakarta. Sistem ini bertujuan untuk meningkatkan keamanan dan kenyamanan dengan teknologi yang mudah digunakan dan terintegrasi.

## Fitur Utama
- **Monitoring Suhu**: Menggunakan sensor DHT22 untuk memantau suhu lingkungan secara real-time dan memberikan peringatan jika suhu melebihi ambang batas tertentu.
- **Deteksi Gerak**: Menggunakan sensor PIR untuk mendeteksi keberadaan manusia dan menampilkan pesan sambutan dengan teks berjalan.
- **Alarm**: Sistem akan mengaktifkan buzzer dan LED jika suhu melebihi ambang batas atau jika gerakan terdeteksi.
- **Display Real-Time**: Informasi suhu dan status sistem ditampilkan pada LCD 16x2.

## Teknologi yang Digunakan
- **Platform Mikrokontroler**: Arduino Uno
- **Sensor**:
  - Sensor Suhu DHT22
  - Sensor Gerak PIR
- **Komponen Lainnya**:
  - Buzzer
  - LCD 16x2 (I2C)
  - LED

## Cara Kerja
1. Sensor DHT22 memantau suhu lingkungan secara kontinu.
2. Jika suhu melebihi 45°C, sistem mengaktifkan buzzer dan menampilkan pesan "KEBAKARAN!" pada LCD.
3. Sensor PIR mendeteksi gerakan di area pintu masuk dan menampilkan pesan "SELAMAT DATANG DI FAKULTAS ILMU KOMPUTER UPNVJ" sebagai teks berjalan.
4. Semua data ditampilkan secara real-time pada LCD 16x2.

## Struktur Sistem
### Komponen dan Koneksi:
- **Sensor Suhu DHT22**:
  - VCC ke 5V pada Arduino
  - GND ke GND Arduino
  - Data ke pin digital 2 Arduino
- **Sensor PIR**:
  - VCC ke 5V pada Arduino
  - GND ke GND Arduino
  - Out ke pin digital 3 Arduino
- **Buzzer**:
  - Positif ke pin digital 8 Arduino
  - Negatif ke GND Arduino
- **LCD 16x2 (I2C)**:
  - VCC ke 5V pada Arduino
  - GND ke GND Arduino
  - SDA ke A4 Arduino
  - SCL ke A5 Arduino

### Diagram Alur Program:
1. Inisialisasi komponen
2. Loop utama:
   - Membaca suhu dari DHT22
   - Membaca sinyal dari PIR
   - Menampilkan data pada LCD
   - Mengaktifkan buzzer dan LED jika ada kondisi abnormal

## Instalasi dan Penggunaan
1. Clone repositori ini:
   ```bash
   git clone https://github.com/username/MonitoringSuhuGerak_Arduino_FIK_UPNVJ.git
   ```
2. Pastikan Arduino IDE sudah terinstal di komputer Anda.
3. Hubungkan komponen sesuai dengan diagram koneksi.
4. Upload kode ke Arduino Uno melalui Arduino IDE.
5. Jalankan sistem dan pantau hasilnya pada LCD.

## Hasil Implementasi
- Sistem dapat mendeteksi suhu lingkungan dan memberikan peringatan jika suhu tinggi.
- Sistem mampu mendeteksi gerakan dan menampilkan pesan sambutan dengan teks berjalan.
- Semua data ditampilkan secara real-time pada LCD.

## Kontributor
- **Muhamad Akbar Muzakynur**
  - NIM: 2210511016
  - Program Studi Informatika, Fakultas Ilmu Komputer, UPN Veteran Jakarta

## Lisensi
Proyek ini dibuat untuk keperluan akademik dan tidak diperuntukkan untuk tujuan komersial.

## Referensi
1. Abdulhamid, M., & Njoroge, K. (2020). Irrigation system based on Arduino UNO microcontroller. Poljoprivredna tehnika, 45(2), 67-78.
2. Pembahasan sensor PIR Lengkap. (2020, August 12). Retrieved from https://www.teknikelektro.com/2020/08/pembahasan-sensor-pir-lengkap.html
