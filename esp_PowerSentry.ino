#define BLYNK_TEMPLATE_ID "TMPL3Ho8aMkWD"
#define BLYNK_TEMPLATE_NAME "POWERSENTRY12"
#define BLYNK_AUTH_TOKEN "7-oKoYtuc0vbBE3Dula1sE28oGIpVh7K"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "VIJAYA PRADHAP 2.4G";
char pass[] = "8056476348";


int manualControl = 0;
bool charging = false;
int chargeLevel = 0;

BlynkTimer timer;

BLYNK_WRITE(V0) {
  manualControl = param.asInt();
  if (manualControl == 1) {
    charging = true;
    chargeLevel = 0;
    Serial.println("Manual Charging Started");
  } else {
    charging = false;
    chargeLevel = 0;
    Serial.println("Manual Charging Stopped");
    Serial.println("OFF");  // Relay OFF
  }
  updateStatus();
}

void updateStatus() {
  if (charging) {
    Blynk.virtualWrite(V1, 255);  // Green LED ON
    Blynk.virtualWrite(V2, 0);    // Red LED OFF
  } else {
    Blynk.virtualWrite(V1, 0);
    Blynk.virtualWrite(V2, 255);
  }
}

void simulateCharging() {
  if (charging) {
    if (chargeLevel < 100) {
      chargeLevel += 10;
      Serial.print("Charging... ");
      Serial.print(chargeLevel);
      Serial.println("%");

      String chargeText = "Charging... " + String(chargeLevel) + "%";
      Blynk.virtualWrite(V3, chargeText);
      Blynk.virtualWrite(V4, chargeLevel);

      Serial.println("ON");  // Keep relay ON
    } else {
      charging = false;
      Serial.println("Charging Complete.");
      Blynk.virtualWrite(V3, "Charging Complete (100%)");
      Blynk.virtualWrite(V4, 100);
      Serial.println("OFF"); // Turn OFF relay
    }
    updateStatus();
  }
}

void setup() {
  Serial.begin(9600);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);

  timer.setInterval(3000L, simulateCharging); // every 3 seconds
}

void loop() {
  Blynk.run();
  timer.run();
}
