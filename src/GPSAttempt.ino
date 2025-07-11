#include <TinyGPS++.h>
TinyGPSPlus gps;

#define RXD2 25
#define TXD2 26

void setup() {
  Serial.begin(115200); // For serial monitor
  Serial.printf("Hello, World!\n");
  Serial2.begin(9600, SERIAL_8N1, RXD2, TXD2); // Connect GPS
}

void loop() {
  while (Serial2.available()) {
    char c = Serial2.read();
    Serial.println(c);
    Serial.printf("Cereal 2 available\n");
    if (gps.encode(c)) {
      Serial.printf("gps encode serial 2 read\n");
      float latitude = gps.location.lat();
      float longitude = gps.location.lng();
      Serial.print("latitude: ");
      Serial.println(latitude, 6);
      Serial.print("longitude: ");
      Serial.println(longitude, 6);
    }
  }
}
