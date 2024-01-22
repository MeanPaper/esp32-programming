#include <Arduino.h>
#include <WiFi.h>

// put function declarations here:
#define LED 2

const char * ssid = "something"; // some random wifi name
const char * password = "some_password"; 

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  // connect to Wifi
  WiFi.begin(ssid, password);
  
  // if the network has no password, you can do the following:
  // WiFi.begin(ssid, NULL);
  
  Serial.println("Start Connection");
  
  while (WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nSuccess");
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());

  pinMode(LED, OUTPUT);
  
  digitalWrite(LED, HIGH);
  delay(100);
  digitalWrite(LED, LOW);
  delay(100);
    
  digitalWrite(LED, HIGH);
  delay(100);
  digitalWrite(LED, LOW);
  delay(100);

    
  digitalWrite(LED, HIGH);
  delay(1500);
  digitalWrite(LED, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:  
  
}

// put function definitions here:
