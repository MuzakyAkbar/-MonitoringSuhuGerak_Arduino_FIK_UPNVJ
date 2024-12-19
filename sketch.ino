#include "DHT.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define DHTPIN  12
#define DHTTYPE DHT22

LiquidCrystal_I2C lcd(0x27, 16, 2); // Inisialisasi LCD dengan alamat I2C

DHT dht(DHTPIN, DHTTYPE); // Inisialisasi sensor DHT
const int trigPin = 9;
const int echoPin = 10;
int ledPin = 15; // LED yang sudah ada
int inputPin = 4;
int pirState = LOW;
int val = 0;

// Alarm
const int buzzerPin = 8; // Pin digital untuk buzzer
const float tempThreshold = 45.0; // Ambang batas suhu untuk alarm

void setup() {
  pinMode(ledPin, OUTPUT); // Set pin LED sebagai OUTPUT
  pinMode(inputPin, INPUT); // Set pin input PIR sebagai INPUT
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  pinMode(buzzerPin, OUTPUT); // Set pin buzzer sebagai OUTPUT

  Serial.begin(9600); // Mulai komunikasi serial
  Serial.println("Muhamad Akbar Muzakynur 2210511016");
  
  dht.begin(); // Mulai sensor DHT
  
  lcd.init(); // Inisialisasi LCD
  lcd.backlight(); // Nyalakan backlight LCD
  lcd.setCursor(0, 0); // Atur posisi kursor LCD
  lcd.print("        UPNVJ"); // Tampilkan pesan selamat datang
}

void loop() {
  val = digitalRead(inputPin); // Baca nilai dari sensor PIR
  float t = dht.readTemperature(); // Baca suhu dari sensor DHT

  lcd.setCursor(0, 0); // Atur posisi kursor untuk baris pertama
  lcd.print("C:");
  lcd.print(t); // Tampilkan suhu pada LCD
  lcd.setCursor(0, 1); // Set kursor untuk baris kedua

  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print(" *C\t");

  // Cek suhu dan aktifkan alarm jika melebihi ambang batas
  if (t > tempThreshold) {
    digitalWrite(ledPin, HIGH); // Aktifkan LED alarm
    lcd.setCursor(0, 1); // Atur posisi kursor untuk baris kedua
    lcd.print("KEBAKARAN!       "); // Tampilkan pesan alarm, tambahkan spasi untuk menghapus pesan sebelumnya
    
    // Bunyikan buzzer dengan pola tertentu
    tone(buzzerPin, 1000); // Bunyi buzzer dengan frekuensi 1000 Hz
    delay(500); // Tunggu selama 0.5 detik
    noTone(buzzerPin); // Matikan buzzer
    delay(500); // Tunggu selama 0.5 detik
  } else {
    digitalWrite(buzzerPin, LOW); // Matikan buzzer
    digitalWrite(ledPin, LOW); // Matikan LED alarm
    lcd.setCursor(0, 1); // Atur posisi kursor untuk baris kedua
    lcd.print("F. Ilmu Komputer"); // Tampilkan pesan default
  }

  // Sensor PIR dan DHT
  if (val == LOW) {
    digitalWrite(ledPin, LOW); // Matikan LED jika tidak ada gerakan
    if (pirState == LOW) {
      lcd.setCursor(0, 1); // Atur posisi kursor untuk baris kedua
      lcd.print("F. Ilmu Komputer");
      pirState = HIGH;
    }
  } else {
    digitalWrite(ledPin, HIGH); // Nyalakan LED jika ada gerakan
    if (pirState == HIGH) {
      lcd.setCursor(0, 1);
      runText("SELAMAT DATANG DI FAKULTAS ILMU KOMPUTER UPNVJ"); // Tampilkan teks berjalan
      pirState = LOW;
    }
  }

  delay(1000); // Tambahkan delay untuk mengurangi frekuensi pembacaan sensor
}

void runText(String text) {
  int len = text.length();
  String spaces = "                "; // 16 spasi untuk membersihkan layar
  for(int i = 0; i < len + 16; i++) {
    lcd.setCursor(0, 1); // Atur posisi kursor untuk baris kedua
    if(i < 16) {
      lcd.print(text.substring(0, i));
      lcd.print(spaces.substring(0, 16 - i)); // Tambahkan spasi untuk membersihkan sisa teks
    } else if (i < len) {
      lcd.print(text.substring(i - 16, i));
    } else {
      lcd.print(text.substring(i - 16));
      lcd.print(spaces.substring(0, i - len)); // Tambahkan spasi untuk membersihkan sisa teks
    }
    delay(300); // Kecepatan teks berjalan
  }
}
