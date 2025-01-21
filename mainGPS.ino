#include <TinyGPS++.h>
#include <SoftwareSerial.h>  // Include SoftwareSerial library
#include "thingProperties.h"

// Define the RX and TX pins for Software Serial 2
#define RX D2 
#define TX D3
#define GPS_BAUD 9600

TinyGPSPlus gps;
SoftwareSerial gpsSerial(RX, TX);

void setup() {
  Serial.begin(115200);
  gpsSerial.begin(GPS_BAUD);
  Serial.println("Software Serial started at 9600 baud rate");
  delay(1500); 
  initProperties();          // Initialize properties for Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);  // Start cloud connection
  setDebugMessageLevel(2);   // Set debug message level for cloud info
  ArduinoCloud.printDebugInfo(); // Print debug information
}


void loop() {
  ArduinoCloud.update();
  while (gpsSerial.available() > 0) {
      gps.encode(gpsSerial.read());
  }
    
  if (gps.location.isUpdated()) {
      Serial.print("LAT: ");
      Serial.println(gps.location.lat(), 6);
      Serial.print("LONG: "); 
      Serial.println(gps.location.lng(), 6);
      locationdetail = {gps.location.lat(), gps.location.lng()};
      Serial.print("SPEED (km/h) = "); 
      Serial.println(gps.speed.kmph()); 
      speed = gps.speed.kmph(); 
      Serial.print("Satellites = "); 
      Serial.println(gps.satellites.value()); 
      satellite=gps.satellites.value();
      Serial.print("Time in UTC: ");
      Serial.println(String(gps.date.year()) + "/" + String(gps.date.month()) + "/" + String(gps.date.day()) + "," + String(gps.time.hour()) + ":" + String(gps.time.minute()) + ":" + String(gps.time.second()));
      Serial.println("");
      gPS_Time = String(gps.date.year()) + "/" + 
                  String(gps.date.month()) + "/" + 
                  String(gps.date.day()) + "," + 
                  String(gps.time.hour()) + ":" + 
                  String(gps.time.minute()) + ":" + 
                  String(gps.time.second());

  }
}
























//void loop() {
//  ArduinoCloud.update();  // Keep Arduino Cloud updated
//
//  // Check if GPS data is available from the GPS module via SoftwareSerial
//  if (ss.available() > 0) {
//    if (gps.encode(ss.read())) {
//      if (gps.location.isValid()) {
//        Serial.print(F("- latitude: "));
//        Serial.println(gps.location.lat());
//
//        Serial.print(F("- longitude: "));
//        Serial.println(gps.location.lng());
//        
//        // Store location details
//        locationdetail = {gps.location.lat(), gps.location.lng()};
//      } else {
//        Serial.println(F("- location: INVALID"));
//      }
//      
//      // Print speed if available
//      Serial.print(F("- speed: "));
//      if (gps.speed.isValid()) { 
//        Serial.print(gps.speed.kmph());
//        Serial.println(F(" km/h"));
//        speed = gps.speed.kmph(); 
//      } else {
//        Serial.println(F("INVALID"));
//      }
//    }
//  }
//}
