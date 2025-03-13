#include <Arduino.h>
#define LED 2

/**
 * Esta funcion se ejecuta cuando inicia el programa
 * una unica vez
 */
void setup(){
  Serial.begin(115200); // Inicializa el puerto serial a 115200 de velocidad
  pinMode(LED, OUTPUT); // Configura el pin 2 como salida, para controlar un led
  digitalWrite(LED, LOW); // Apaga el led, hay dos modos HIGH y LOW que representan 1 y 0 respectivamente
}


/**
 * Esta funcion es similar al main de un programa en C
 * Se ejecuta una vez que el microcontrolador se inicia
 * y se ejecuta de manera infinita
 */
void loop(){
  /**
   * Loop que imprime un mensaje en el puerto serial y enciende y apaga un led cada segundo pero implementado de forma incorrecta
   */
  Serial.println("Hello World");
  delay(3000); // Espera 1 segundo, No son buenas practicas usar delay ya que bloquea el microcontrolador y no permite ejecutar otras tareas
  digitalWrite(LED, HIGH);
  delay(3000);
  digitalWrite(LED, LOW);
}