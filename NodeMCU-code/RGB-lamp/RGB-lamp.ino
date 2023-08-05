#define BLYNK_TEMPLATE_ID "TMPL3LuHCthUu"
#define BLYNK_TEMPLATE_NAME "Lamp"
#define BLYNK_AUTH_TOKEN "a_CSZy5Ab3t7XhfExFJKk_939rZVldoP"

// #define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = BLYNK_AUTH_TOKEN;

char ssid[] = "IoT";
char pass[] = "12345678";

BLYNK_WRITE(V0)
{
  int value = param.asInt();
  Serial.println(value);
  if(value == 1)
  {
    digitalWrite(D5, HIGH);
    Serial.println("SWITCH_1 ON");
  }
  if(value == 0)
  {
     digitalWrite(D5, LOW);
     Serial.println("SWITCH_1 OFF");
  }
}

BLYNK_WRITE(V1)
{
  int value = param.asInt();
  Serial.println(value);
  if(value == 1)
  {
    digitalWrite(D6, HIGH);
    Serial.println("SWITCH_2 ON");
  }
  if(value == 0)
  {
     digitalWrite(D6, LOW);
     Serial.println("SWITCH_2 OFF");
  }
}

BLYNK_WRITE(V2)
{
  int value = param.asInt();
  Serial.println(value);
  if(value == 1)
  {
    digitalWrite(D7, HIGH);
    Serial.println("SWITCH_3 ON");
  }
  if(value == 0)
  {
     digitalWrite(D7, LOW);
     Serial.println("SWITCH_3 OFF");
  }
}




void setup()
{
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  pinMode(D5,OUTPUT);
  pinMode(D6,OUTPUT);
  pinMode(D7,OUTPUT);
}

void loop()
{
  Blynk.run();
}