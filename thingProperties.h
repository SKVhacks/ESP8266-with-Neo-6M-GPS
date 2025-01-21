/*****************************************************************************************
 * ****** Strictly Recomended use Directly download File from Arduino IOT Cloud **********
 * ***************************************************************************************
 */

#include <ArduinoIoTCloud.h>
#include <Arduino_ConnectionHandler.h>
#include "arduino_secrets.h"

const char DEVICE_LOGIN_NAME[] = "####-####-#####-#####"; // Replace with your id or Directly download from Arduino IOT Cloud

const char SSID[] = SECRET_SSID;          // Network SSID (name)
const char PASS[] = SECRET_OPTIONAL_PASS; // Network password (use for WPA, or use as key for WEP)
const char DEVICE_KEY[] = SECRET_DEVICE_KEY; // Secret device password
String gPS_Time;
float speed;
int satellite;
CloudLocation locationdetail;

void onGPSTimeChange(){
  
}
void onSpeedChange(){
  
}
void onSatelliteChange(){
  
}
void onLocationdetailChange(){
  
}

void initProperties(){

  ArduinoCloud.setBoardId(DEVICE_LOGIN_NAME);
  ArduinoCloud.setSecretDeviceKey(DEVICE_KEY);
  ArduinoCloud.addProperty(gPS_Time, READWRITE, ON_CHANGE, onGPSTimeChange);
  ArduinoCloud.addProperty(speed, READWRITE, ON_CHANGE, onSpeedChange);
  ArduinoCloud.addProperty(satellite, READWRITE, ON_CHANGE, onSatelliteChange);
  ArduinoCloud.addProperty(locationdetail, READWRITE, ON_CHANGE, onLocationdetailChange);

}

WiFiConnectionHandler ArduinoIoTPreferredConnection(SSID, PASS);
