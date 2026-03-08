#include <WiFi.h>
#include "ThingSpeak.h"

//////////////////// WIFI ////////////////////
const char* ssid = "Potato";
const char* password = "Tinkerbell2005";

//////////////////// THINGSPEAK ////////////////////
unsigned long channelID = 3278910;
const char* writeAPIKey = "X02IBK11M7PZZBGZ";

WiFiClient client;

//////////////////// GAS SENSOR ////////////////////
#define GAS_SENSOR_PIN 34   // GPIO34 (ADC1)
#define SAMPLE_COUNT 10

////////////////////////////////////////////////////

void connectWiFi() {
  Serial.print("Connecting to WiFi");

  WiFi.begin(ssid, password);

  int timeout = 0;
  while (WiFi.status() != WL_CONNECTED && timeout < 20) {
    delay(500);
    Serial.print(".");
    timeout++;
  }

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("\nWiFi Connected!");
  } else {
    Serial.println("\nWiFi Failed!");
  }
}

////////////////////////////////////////////////////

int readGasSensor() {

  long total = 0;

  for(int i = 0; i < SAMPLE_COUNT; i++) {
    total += analogRead(GAS_SENSOR_PIN);
    delay(50);
  }

  return total / SAMPLE_COUNT;
}

////////////////////////////////////////////////////

int classifyAirQuality(int gasValue) {

  if (gasValue <= 1200) {
    return 1;   // LOW
  }
  else if (gasValue <= 2500) {
    return 2;   // MEDIUM
  }
  else {
    return 3;   // HIGH
  }
}

////////////////////////////////////////////////////

void setup() {

  Serial.begin(115200);

  analogReadResolution(12);          // 0-4095
  analogSetAttenuation(ADC_11db);    // Full 3.3V range

  connectWiFi();
  ThingSpeak.begin(client);
}

////////////////////////////////////////////////////

void loop() {

  if (WiFi.status() != WL_CONNECTED) {
    connectWiFi();
  }

  int gasValue = readGasSensor();
  int airQuality = classifyAirQuality(gasValue);

  Serial.println("=================================");
  Serial.print("Gas Value: ");
  Serial.println(gasValue);

  Serial.print("Air Quality Level (1=Low,2=Med,3=High): ");
  Serial.println(airQuality);

  //////////////////// Send to ThingSpeak ////////////////////

  ThingSpeak.setField(1, gasValue);
  ThingSpeak.setField(2, airQuality);

  int status = ThingSpeak.writeFields(channelID, writeAPIKey);

  if(status == 200){
    Serial.println("Data Sent Successfully");
  } else {
    Serial.print("ThingSpeak Error: ");
    Serial.println(status);
  }

  Serial.println("=================================\n");

  delay(20000);   // Minimum 15 seconds for ThingSpeak
}