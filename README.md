# Mosquitto---MQTT
## Práctica: Publisher MQTT con ESP32
## **Escuela Superior de Cómputo - Instituto Politécnico Nacional** 
## **Carrera:** Ingeniería en Sistemas Computacionales
## **UA:** Internet Of Things 6CM3 
## **Autor:** Martinez Ortiz Patricia Estefania  

## Objetivo
Implementar un nodo Publisher utilizando un microcontrolador ESP32 para enviar mensajes a un broker MQTT a través de una red Wi-Fi local de 2.4 GHz.

## Nota de Arquitectura y Hardware
El diseño original de esta práctica contemplaba el uso de una placa SBC (Orange Pi Lite) como broker MQTT. Debido a una falla de hardware en dicha placa, el entorno del broker (Eclipse Mosquitto) fue desplegado de manera local sobre Windows 11. Esto permitió demostrar con éxito la integración del nodo publisher (ESP32) y el flujo bidireccional de comunicación MQTT en la red local, cumpliendo con los objetivos del protocolo.

## Requisitos y Herramientas
- **Hardware:** ESP32 DevKitC V4.
- **Entorno de Desarrollo:** Visual Studio Code con extensión PlatformIO.
- **Librerías:** `PubSubClient` (v2.8) por Nick O'Leary.
- **Broker MQTT:** Eclipse Mosquitto (v2.0+).

## Instalación y Configuración
1. Clonar este repositorio en el entorno local.
2. Abrir la carpeta del proyecto utilizando PlatformIO. El archivo `platformio.ini` resolverá y descargará automáticamente las dependencias necesarias.
3. En el archivo `src/main.cpp`, reemplazar las credenciales Wi-Fi (`ssid` y `password`) por las de la red local.
4. Actualizar la constante `mqtt_server` con la dirección IP (IPv4) del equipo que ejecuta el servicio de Mosquitto.
5. Asegurar que el Firewall del servidor tenga habilitada una regla de entrada para el puerto TCP `1883`.
6. Compilar el proyecto y subir el firmware a la ESP32.

## Evidencia de Funcionamiento
*(poner mi captura de pantalla)*

En la imagen adjunta se observa el Monitor Serial (PlatformIO) de la ESP32 confirmando la conexión al broker y la publicación cíclica de mensajes, operando en paralelo con la terminal nativa del suscriptor recibiendo los paquetes de datos en tiempo real.
