#include <Arduino.h>
#include <WiFi.h>

const char * ssid = "Franki";
const char * password = "Jusadi4132";

WiFiServer server(80);

void conectarRedWifi(){
   WiFi.begin(ssid, password);
   Serial.print("Estableciendo conexion WiFi..");
   while(WiFi.status() != WL_CONNECTED) {
     delay(1000);
     Serial.print(".");
   }
   Serial.println("\nConectado a la red WiFi");
}

String getTipoCrifrado(wifi_auth_mode_t tipoCifrado){
  switch(tipoCifrado){
    case (WIFI_AUTH_OPEN):
            return "Abierta";
    case (WIFI_AUTH_WEP):
            return "WEP";
    case (WIFI_AUTH_WPA_PSK):
            return "WPA_PSK";
    case (WIFI_AUTH_WPA2_PSK):
            return "WPA2_PSK";
    case (WIFI_AUTH_WPA_WPA2_PSK):
            return "WPA_WPA2_PSK";
    case (WIFI_AUTH_WPA2_ENTERPRISE):
            return "WPA2_ENTERPRISE";
    case (WIFI_AUTH_MAX):  
            return "WPA_MAX";      
  }
}

void escanearRedes(){
  int numberOfNetworks = WiFi.scanNetworks();
  Serial.println("Numero de redes encontradas: " + String(numberOfNetworks));
  for (int i = 0; i < numberOfNetworks; i++)
  {
    Serial.println("Nombre de la red: " + WiFi.SSID(i));
    Serial.println("Fuerza de la Señal: " + WiFi.RSSI(i));
    Serial.println("MAC Address: " + WiFi.BSSIDstr(i));
    String tipoCifradoDescription = getTipoCrifrado(WiFi.encryptionType(i));
    Serial.println("Tipo de cifrado: " + tipoCifradoDescription);
    Serial.println("-----------------------------");  
  }
  
}

void setup() {
  Serial.begin(115200);
  pinMode(2, OUTPUT);
  escanearRedes();
  conectarRedWifi();
  Serial.println("IP local: ");
  Serial.println(WiFi.localIP());
  server.begin();
}

void loop() {
  // Maneja las peticiones al servidor y controla el LED
  WiFiClient cliente = server.available();
  if(cliente){
     String mensaje="";
     Serial.println("Llego un nuevo cliente");
     while(cliente.connected()){
       if(cliente.available()){
         char letra = cliente.read();
         Serial.write(letra);
         if(letra=='\n'){  //Es un caracter enter?
            if(mensaje.length()==0){  //La longitud de la linea es 0 ?
                 cliente.println("HTTP/1.1 200 OK");
                 cliente.println("Content-type:text/html");
                 cliente.println();  //Indicamos que terminamos de enviar la cabecera HTTP
                 cliente.println("<br>Clic <a href=\"H\">aqui</a> para encender la lampara<br>");
                 cliente.println("Clic <a href=\"L\">aqui</a> para apagar la lampara");
                 cliente.println();
                 break;
            } else
                 mensaje="";
         } else if (letra != '\r'){
           mensaje+=letra;
         }
         if(mensaje.endsWith("GET /H")){
           digitalWrite(2, HIGH);
         }
         if(mensaje.endsWith("GET /L")){
           digitalWrite(2,LOW);
         }
       }
     }
     Serial.println("Fin de conexion");
     cliente.stop();
  }
}