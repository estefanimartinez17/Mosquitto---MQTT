#include <Arduino.h>
#include <WiFi.h>
#include <PubSubClient.h>


const char* ssid = "Tenda_8FA030";
const char* password = "openrice341";


const char* mqtt_server = "192.168.0.108";

WiFiClient espClient;
PubSubClient client(espClient);

void setup_wifi() {
  delay(10);
  Serial.println();
  Serial.print("Conectando a la red Wi-Fi: ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\n¡Wi-Fi conectado!");
  Serial.print("Dirección IP de la ESP32: ");
  Serial.println(WiFi.localIP());
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("Intentando conexión MQTT al broker... ");
    // Intentar conectar con un ID de cliente aleatorio
    if (client.connect("ESP32_Publisher_Client")) {
      Serial.println("¡Conectado exitosamente!");
    } else {
      Serial.print("Falló, código de error = ");
      Serial.print(client.state());
      Serial.println(" Intentando de nuevo en 5 segundos...");
      delay(5000);
    }
  }
}

void setup() {
  Serial.begin(115200);
  setup_wifi();
  
 
  client.setServer(mqtt_server, 1883);
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

 
  static unsigned long lastMsg = 0;
  unsigned long now = millis();
  
  if (now - lastMsg > 5000) {
    lastMsg = now;
    String mensaje = "Hola desde ESP32! Mensaje MQTT enviado a las " + String(now);
    
   
    client.publish("test/topic", mensaje.c_str());
    Serial.println("Publicando mensaje: " + mensaje);
  }
}