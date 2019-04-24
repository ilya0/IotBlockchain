#include <Arduino.h>
#include <M5Stack.h>
#include <WiFi.h>
#include <ESPmDNS.h>
#include <WiFiClient.h>
#include "WebServer.h"
#include <Preferences.h>


const char* ssid = "You are being watched";
const char* password =  "password1";
 


// The setup() function runs once each time the micro-controller starts
void setup() {
  // init lcd, serial, not init sd card
  M5.begin(true, false, true);
  M5.Lcd.clear(BLACK);
  M5.Lcd.setTextColor(YELLOW);
  M5.Lcd.setTextSize(2);
  M5.Lcd.setCursor(65, 10);
  M5.Lcd.println("Button example");
  M5.Lcd.setCursor(3, 35);
  M5.Lcd.println("Press button B 700ms clear");
  M5.Lcd.setTextColor(RED);


 
  Serial.begin(115200);
 
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting to WiFi..");
    M5.Lcd.println("Connecting to WiFi..");
  }
 
  Serial.println("Connected to the WiFi network");
  M5.Lcd.println("Connected to the WiFi network");
 
}
 



// Add the main program code into the continuous loop() function
void loop() {
  M5.update();
 
  // if want use Releasefor; suggest use Release in press event
  if (M5.BtnA.wasReleased()) {
    M5.Lcd.print('A');
  } else if (M5.BtnB.wasReleased()) {
    M5.Lcd.print('B');
  } else if (M5.BtnC.wasReleased()) {
    M5.Lcd.print('C');
  } else if (M5.BtnB.wasReleasefor(700)) {
    M5.Lcd.clear(BLACK);
    M5.Lcd.setCursor(0, 0);
  }
}