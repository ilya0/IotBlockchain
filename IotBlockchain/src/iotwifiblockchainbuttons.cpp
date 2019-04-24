#include <Arduino.h>
#include <M5Stack.h>
#include <WiFi.h>




// The setup() function runs once each time the micro-controller starts
void setup() {
  
  Serial.begin(115200);
  M5.begin(true, false, true); // init lcd, serial, not init sd card
  delay(500);

  WiFi.begin("You are being watched", "password1");
  delay(500);

  while (WiFi.status() != WL_CONNECTED) {
    M5.update();
    delay(500);
    Serial.println("Connecting to WiFi..");
    M5.Lcd.println("Connecting to WiFi..");
    M5.Lcd.clear(BLACK);
  }


  M5.Lcd.setTextColor(YELLOW);
  M5.Lcd.setTextSize(2);
  M5.Lcd.setCursor(65, 10);
  M5.Lcd.println("Button example");
  M5.Lcd.setCursor(3, 35);
  M5.Lcd.println("Press button B 700ms clear");
  M5.Lcd.setTextColor(RED);
  M5.Lcd.setTextColor(WHITE);
  M5.Lcd.println("************************************");
   Serial.println("Connected to the WiFi network");
   M5.Lcd.println("Connected to the WiFi network");
M5.Lcd.setTextColor(RED);


}
 



// Add the main program code into the continuous loop() function
void loop() {

  M5.update();
  // if want use Releasefor; suggest use Release in press event
  if (M5.BtnA.wasReleased()) {
    M5.Lcd.print("Button A was pressed");
   
  } else if (M5.BtnB.wasReleased()) {
    M5.Lcd.print("Button B was pressed");
  } else if (M5.BtnC.wasReleased()) {
    M5.Lcd.print("Button C was pressed");
  } else if (M5.BtnB.wasReleasefor(700)) {

    M5.Lcd.clear(BLACK);
    M5.Lcd.setCursor(0, 0);
  }
}




//////


 
void sendpost() {
 
 if(WiFi.status()== WL_CONNECTED){   //Check WiFi connection status
 
   HTTPClient http;   
   http.begin("http://jsonplaceholder.typicode.com/posts");  //Specify destination for HTTP request
   http.addHeader("Content-Type", "text/plain");             //Specify content-type header
 
   int httpResponseCode = http.POST("POSTING from ESP32");   //Send the actual POST request
 
   if(httpResponseCode>0){
 
    String response = http.getString();                       //Get the response to the request
    Serial.println(httpResponseCode);   //Print return code
    Serial.println(response);           //Print request answer
 
   }else{
 
    Serial.print("Error on sending POST: ");
    Serial.println(httpResponseCode);
 
   }
 
   http.end();  //Free resources
 
 }else{
 
    Serial.println("Error in WiFi connection");   
 
 }
 
  delay(10000);  //Send a request every 10 seconds
 
}
