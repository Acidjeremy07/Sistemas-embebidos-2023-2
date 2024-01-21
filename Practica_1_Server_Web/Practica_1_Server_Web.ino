// Sistemas Embebidos.
// GCV2
// Deberán probar este código, que desplegará una página html.
// Los botones no hacen ejecutan nada.

// Deberás conectarte a un Access Point, e ingresar los datos para que
// el ESP se conecte. Deberás descargar la librería ESP8266 Generic
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char* ssid = "kamehouse";
const char* password = "Oliver-jeremy-051177";

ESP8266WebServer server(80);

void handleRoot(){

}

// Deberás verificar que en tu consola de Arduino el baudaje sea el
// mismo, para poder visualizar los mensajes de manera correcta
void setup() {
  Serial.begin(115200);
  delay(10);

  // Conecta a la red wifi.
  Serial.println();
  Serial.print("Conectando con ");
  Serial.println(ssid);

  //WiFi.begin(ssid, password);
  server.on("/", handleRoot); // Manejador para la ruta raíz
  server.begin();

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("Conectado con WiFi.");

// Inicio del Servidor web.
server.begin();
Serial.println("Servidor web iniciado.");

// Esta es la IP a la cual deberás conectarte una vez se haya
// establecido comunicación con el ESP. Es decir, cuando se vea
// en consola la IP, deberás conectarte desde tu navegador a esa IP
Serial.print("Esta es la IP para conectar: ");
Serial.print("http://");
Serial.println(WiFi.localIP());
Serial.println("");
}

void loop() {
  // Consulta si se ha conectado algún cliente.
  server.handleClient();
  if (!Client) {
    return;
  }

  // Espera hasta que el cliente envíe datos.
  Serial.println("Nuevo cliente.");
  while(!Client.available()){
    delay(1);
  }

  // Página WEB.
  ////////////////////////////////
  Client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println(""); // NO eliminar esta línea.
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");

client.println("<head><meta charset=utf-8></head>");
client.println("<body><font face='Arial' center><h1>Practica de Servidor web con NodeMCU.</h1>");
client.println("<h2><font color='#009900'>Grupo 6CV2</font></h2>");
client.println("<h3>Página web.</h3>");
client.println("<img src='https://lagarto.ipn.mx/images/2019/10/03/img_20190905_091841_124.jpg'><br><br>");
client.println("<button>Sistemas </button>");
client.println("<button>Embebidos </button>");
client.println("<button>6CV2 </button>");
client.println("<a href='/mensaje4'><button>Práctica </button></a>");
client.println("</font></center></body></html>");

Serial.println("Cliente desconectado.");
}