# Codelabs IoT

Este repositorio almacena diferentes **Codelabs** relacionados con **Internet de las Cosas (IoT)**. Cada uno de estos proyectos sirve como guía y práctica para el desarrollo de aplicaciones IoT.

## 📁 Contenido del Repositorio

### 🎇 iot-led-basico
Codelab introductorio para IoT en el que se implementa una clase principal que permite:
- Encender y apagar un **LED de prueba**.
- Imprimir el mensaje **"Hola mundo"** en pantalla.

### 📲 iot-led-server
Este Codelab tiene como objetivo la conexión de un dispositivo IoT a una **red WiFi**. Además:
- Muestra información sobre la conexión establecida.
- Permite realizar pruebas de conectividad y monitoreo.

### 📡 iot-cliente-http
Este módulo facilita la conexión de un dispositivo IoT a una red WiFi mediante la clase `libwifi`. Sus características incluyen:
- Una función `conectarWifi(ssid, password)` para establecer la conexión de manera sencilla.
- Mensajes de estado detallados en la consola serie para depuración.
- Obtención y visualización de la dirección IP asignada al dispositivo.

### 🌐 iot-cliente-http-datos-sensor
Este Codelab establece una conexión mediante el **ESP32** para obtener los datos de un **sensor SHT31** y enviarlos a **Freeboard** para su visualización. El proyecto incluye:
- Conexión a una red WiFi.
- Lectura de los datos de temperatura y humedad del sensor SHT31.
- Envío de los datos a un tablero en Freeboard para monitoreo en tiempo real.

### 🐳 ejemplo-compose
Ejemplo básico del uso de **Docker Compose**, donde se explica cómo levantar múltiples servicios mediante un archivo `.yml`. Ideal para entender cómo orquestar servicios contenedorizados de manera sencilla.

### 📊 ejemplo-compose-timescaledb
En este codelab se muestra cómo implementar y levantar una base de datos **TimescaleDB** usando **Docker Compose**. Se explican los pasos necesarios y se incluye el siguiente archivo de configuración:

```yaml
services:
  timescale:
    image: timescale/timescaledb:latest-pg13
    container_name: timescaledb
    environment: 
      POSGRESQL_DB: iot_data
      POSGRESQL_USER: iot_data_user
      POSTGRESQL_PASSWORD: a1b2c3d4
    ports:
      - "5432:5432"
    volumes:
      - ./data:/var/lib/postgresql/data
    restart: always
```
### 🐍 mosquitto-project
Este codelab contiene la configuración de **Mosquitto** para trabajar con MQTT en entornos IoT. En la carpeta encontrarás los siguientes elementos:
- **`mosquitto.yml`**: Archivo de configuración para la ejecución de Mosquitto usando Docker Compose.
- **`mosquitto/`**: Carpeta que contiene los archivos de configuración adicionales:
  - **`acl`**: Control de acceso para Mosquitto.
  - **`conf`**: Configuraciones personalizadas para Mosquitto.
  - **`passwd`**: Archivo que contiene las credenciales de los usuarios.

El propósito de esta carpeta es facilitar la configuración de un broker MQTT utilizando Mosquitto en un entorno de contenedores.

## ✨✨ Uso del Repositorio
Para clonar este repositorio en tu equipo, ejecuta:

```sh
git clone https://github.com/santiago-diaz-franki/codelabs-iot.git
```
