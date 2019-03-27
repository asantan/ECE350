#include <SPI.h>
#include <WiFi101.h>
#include "secrets.h"

char ssid[] = SECRET_SSID; 
char PASS[] = SECRET_PASS; 
int led = LED_BUILTIN; 
int status = WL_IDLE_STATUS;
WiFiServer server(80);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while(!Serial){
    
  }

  WiFi.setPins(8, 7, 4, 2);
  Serial.println("Access Point Mode");
  pinMode(led, OUTPUT);

  if(WiFi.status() == WL_NO_SHIELD){
    Serial.println("WiFi Shield not present");
    while(true){} //stop program
  }

  Serial.print("Creating Access point named:");
  Serial.println(ssid);

  status = WiFi.beginAP(ssid);
 if(status != WL_AP_LISTENING){
  Serial.println("Creating AP failed");
  while(true){} //stop
 }
 delay(10000);
 server.begin();
 printWiFiStatus();
 
  Serial.println();
}


void loop() {
  // put your main code here, to run repeatedly:

}

void printWiFiStatus() {
  // print the SSID of the network you're attached to:
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // print your WiFi shield's IP address:
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);

  // print the received signal strength:
  long rssi = WiFi.RSSI();
  Serial.print("signal strength (RSSI):");
  Serial.print(rssi);
  Serial.println(" dBm");
  Serial.println(ip);

}
