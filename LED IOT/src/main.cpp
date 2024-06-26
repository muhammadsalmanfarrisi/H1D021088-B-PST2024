#include <Arduino.h>
#include <ESPAsyncWebServer.h>
#include <ESP8266WiFi.h>

// put function declarations here:
const char *ssid = "TEKNIK UNSOED D3";
const char *password = "";

String website;
AsyncWebServer server(80);

int LEDmerah = D0;
int LEDkuning = D1;
int LEDhijau = D2;

void setup()
{
  // put your setup code here, to run once:
  pinMode(LEDmerah, OUTPUT);
  pinMode(LEDkuning, OUTPUT);
  pinMode(LEDhijau, OUTPUT);
  Serial.begin(9600);
  delay(10);

  // setting mode station
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(300);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  website += "<h1> Web Control ESP8266</h1>";
  website += "<p>LED 1: ";
  website += "<a href=\"LED1ON\"\"><button>ON</button></a><a     href=\"LED1OFF\"\"><button>OFF</button></a></p><br>";
  website += "<p>LED 2: ";
  website += "<a href=\"LED2ON\"\"><button>ON</button></a><a href=\"LED2OFF\"\"><button>OFF</button></a></p><br>";
  website += "<p>LED 3: ";
  website += "<a href=\"LED3ON\"\"><button>ON</button></a><a href=\"LED3OFF\"\"><button>OFF</button></a></p>";

  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(200, "text/html", website); });

  server.on("/LED1ON", HTTP_GET, [](AsyncWebServerRequest *request)
            {
    digitalWrite(LEDmerah, HIGH);
    request->send(200, "text/html", website); });

  server.on("/LED2ON", HTTP_GET, [](AsyncWebServerRequest *request)
            {
    digitalWrite(LEDkuning, HIGH);
    request->send(200, "text/html", website); });

  server.on("/LED3ON", HTTP_GET, [](AsyncWebServerRequest *request)
            {
    digitalWrite(LEDhijau, HIGH);
    request->send(200, "text/html", website); });

  server.on("/LED1OFF", HTTP_GET, [](AsyncWebServerRequest *request)
            {
    digitalWrite(LEDmerah, LOW);
    request->send(200, "text/html", website); });

  server.on("/LED2OFF", HTTP_GET, [](AsyncWebServerRequest *request)
            {
    digitalWrite(LEDkuning, LOW);
    request->send(200, "text/html", website); });

  server.on("/LED3OFF", HTTP_GET, [](AsyncWebServerRequest *request)
            {
    digitalWrite(LEDhijau, LOW);
    request->send(200, "text/html", website); });

  server.begin();
}

void loop()
{
  // put your main code here, to run repeatedly:
}
