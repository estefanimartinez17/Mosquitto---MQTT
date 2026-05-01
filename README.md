# Mosquitto---MQTT
## Práctica: Publisher MQTT con ESP32
**Escuela Superior de Cómputo - Instituto Politécnico Nacional** 
**Carrera:** Ingeniería en Sistemas Computacionales
**UA:** Internet Of Things 6CM3 
**Autor:** Martinez Ortiz Patricia Estefania  

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
<img width="1919" height="1026" alt="Evidencia_MensajesESP32" src="https://github.com/user-attachments/assets/703919f7-30dd-4a1f-b6db-aa4d65846966" />


En la evidencia adjunta se demuestra el flujo de comunicación MQTT en tiempo real. Del lado izquierdo, el Monitor Serial de PlatformIO muestra al nodo ESP32 (Publisher) enviando mensajes de forma cíclica. A su vez, del lado derecho, la terminal de Windows operando como cliente suscriptor mediante Mosquitto, confirma la recepción exitosa e inmediata de los paquetes de datos.
