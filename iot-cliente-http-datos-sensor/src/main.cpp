#include <Arduino.h>
#include "libwifi.h"
#include <WiFi.h>
#include <Adafruit_SHT31.h>

#define LED 2

const char *ssid = "Franki";
const char *password = "Jusadi4132";
const char *host = "codelab.denkitronik.com";
const char *name = "franki";
const int port = 8080;
int temperatura;
int humedad;
int presion;
Adafruit_SHT31 sht31 = Adafruit_SHT31(); // Dirección I2C del sensor SHT31

void setup()
{
  pinMode(LED, OUTPUT);
  Serial.begin(115200);
  Serial.println("Iniciando cliente http");
  conectarWifi(ssid, password);

  // Inicializar el sensor SHT31
  if (!sht31.begin(0x44)) {
    Serial.println("No se pudo inicializar el sensor SHT31.");
    while (1);
  }
}

void loop()
{
  Serial.println("Iniciando loop");
  temperatura = sht31.readTemperature(); // Leer temperatura
  humedad = sht31.readHumidity();       // Leer humedad
  String url = "/thingname/" + String(name) + "?humedad=" + String(humedad) + "&temperatura=" + String(temperatura);
  Serial.println("Enviando datos a freeboard...");
  Serial.println(url);

  WiFiClient cliente;
  if (!cliente.connect(host, port))
  {
    Serial.println("Error al conectar con freeboard");
    delay(2000);
    return;
  }

  cliente.print("GET " + url + " HTTP/1.1\r\nHost: " + String(host) + "\r\nConnetion: close\r\n\r\n"); // el HTTP/1.1 es la version del protocolo

  // Agregamos un tiempo de espera para recibir los primeros caracteres enviados por el servidor
  unsigned long timeout = millis();
  while (cliente.available() == 0)
  {
    if (millis() - timeout > 5000)
    {
      Serial.println("Tiempo de espera agotado");
      cliente.stop();
    }
  }

  Serial.println("Respuesta del servidor:");
  while (cliente.available())
  {
    String line = cliente.readStringUntil('\r');
    Serial.print(line);
  }

  Serial.println("Finando conexion");
  cliente.stop();

  delay(3000);
}
