#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include "robotik.h"
#define led1 D0

 
//ACCES POINT
const char* ssid = "ROBOTIK-EVENT-11";    // Nama AP/Hotspot
const char* password = "12345678";    // Password AP/Hotspot

// Mengatur IP Address ----------------------------------------------------
IPAddress IP(192,168,5,20);
IPAddress NETMASK(255,255,255,0);
IPAddress NETWORK(192,168,5,28);
IPAddress DNS(192,168,5,28);

// Server on port 80 ------------------------------------------------------
ESP8266WebServer server(80);
String LEDstate1 = "OFF";

void handleRoot() {
  String s = MAIN_page; //Read HTML contents
  server.send(200, "text/html", s); //Send web page
}

void kondisiLED() {
String t_state = server.arg("LEDstate1"); //Refer  xhttp.open("GET", "setLED?LEDstate=" + Statusled1, true);
  Serial.println(t_state);
  if (t_state == "1"){
    LEDstate1 = "ON";
    digitalWrite(led1, HIGH);
  }
  else{
    LEDstate1 = "OFF";
    digitalWrite(led1, LOW);
  }
  server.send(200, "text/plane", LEDstate1);
}


void statusLED() {
  server.send(200, "text/plane", LEDstate1);
}
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  delay(10);
  
 // Mengatur WiFi ----------------------------------------------------------
  Serial.println();
  Serial.println("WELCOME TO ROBOTIK EVENT");
  Serial.println("Please patienc brad...");
  Serial.println("Configuring access point agv...");
  
  WiFi.mode(WIFI_AP);             // Mode AP/Hotspot
  WiFi.softAP(ssid, password);
  WiFi.config(IP, NETWORK, NETMASK, DNS);
  
 // Start the server -------------------------------------------------------
  server.begin();
  Serial.println("Server begin");
  
 // Print the IP address ---------------------------------------------------
  Serial.println(WiFi.localIP());
  
 // Membuat tampilan webpage -----------------------------------------------
  server.on("/", handleRoot);
  server.on("/setLED1", kondisiLED);
  server.on("/readLED1", statusLED);
  server.begin(); //Start server

  //SET PIN
  pinMode(D0,OUTPUT);
}

void loop() {
  //handle web server
  server.handleClient();
}
