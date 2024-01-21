#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <FS.h>

const char* ssid = "kamehouse";
const char* password = "Oliver-jeremy-051177";

ESP8266WebServer server(80);

void setup() {
  Serial.begin(115200);

  // Conectar a la red WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  if (!SPIFFS.begin()) {
    Serial.println("Error al iniciar SPIFFS");
    return;
  }

  server.begin();
}

void handleRoot() {
  File file = SPIFFS.open("/index.html", "r");
  if (!file) {
    server.send(404, "text/plain", "Archivo no encontrado");
    return;
  }
  server.streamFile(file, "text/html");
  file.close();
}

void loop() {
  server.handleClient();
}
