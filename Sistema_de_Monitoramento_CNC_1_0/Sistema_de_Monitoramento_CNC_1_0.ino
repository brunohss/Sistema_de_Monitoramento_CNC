#include <ESP8266WiFi.h>
#include <PubSubClient.h>  // Para MQTT
#include <ModbusMaster.h>  // Para Modbus RTU
#include <ESPAsyncWebServer.h>  // Para interface web

AsyncWebServer server(80); // Iniciando o servidor na porta 80


// Configurações Wi-Fi
const char* ssid = "SEU_SSID";
const char* password = "SUA_SENHA";

// Configurações MQTT
const char* mqtt_server = "broker.hivemq.com"; // Substitua pelo seu servidor MQTT
const char* topic_data = "cnc/data";  // Tópico para envio de dados
const char* topic_command = "cnc/command";  // Tópico para comandos

WiFiClient espClient;
PubSubClient client(espClient);

// Função para reconectar ao MQTT
void reconnectMQTT() {
  while (!client.connected()) {
    if (client.connect("CNC_Monitor")) {
      client.subscribe(topic_command);
    } else {
      delay(5000);
    }
  }
}

void setup() {
  Serial.begin(9600);
  setupModbus();

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
  }

  client.setServer(mqtt_server, 1883);
  client.setCallback(callbackMQTT);

  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send(200, "text/html", generateHTML());
  });

  server.on("/data", HTTP_GET, [](AsyncWebServerRequest *request) {
    String json = "{\"temp\": " + String(getTemperature()) +
                  ", \"vibration\": " + String(getVibration()) +
                  ", \"energy\": " + String(getEnergy()) + "}";
    request->send(200, "application/json", json);
  });

  server.begin();
}

void loop() {
  if (!client.connected()) {
    reconnectMQTT();
  }
  client.loop();

  float temp = getTemperature();
  float vibration = getVibration();
  float energy = getEnergy();

  String payload = "{\"temp\": " + String(temp) +
                   ", \"vibration\": " + String(vibration) +
                   ", \"energy\": " + String(energy) + "}";
  client.publish(topic_data, payload.c_str());

  delay(1000);
}
