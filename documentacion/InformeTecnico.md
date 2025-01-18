#  Informe Técnico del Proyecto: Automatización de una Cocina

## Introducción

Este documento presenta el desarrollo y la implementación de un sistema de automatización para una cocina, diseñado como evaluación final de la asignatura. El objetivo principal del proyecto es crear un sistema que detecte niveles elevados de humedad, simule una fuga de gas y emita una alarma visual y sonora. Además, incluye una pantalla LCD para mostrar el estado del sistema y un botón pulsador para desactivar temporalmente la alarma.

## Objetivos del Proyecto

1. Detectar niveles altos de humedad mediante el sensor DHT11.
2. Activar un sistema de alarma visual y sonora cuando la humedad supere un umbral definido.
3. Mostrar información en una pantalla LCD.
4. Permitir al usuario desactivar la alarma mediante un botón pulsador.
5. Integrar todos los componentes en una maqueta funcional.

## Diseño del Sistema

### Diseño de Alto Nivel

El diseño de alto nivel incluye los componentes principales y sus interacciones:

- **Sensor DHT11:** Detecta la humedad del ambiente.
- **Arduino:** Actúa como controlador central, procesando los datos del sensor y gestionando las salidas.
- **Pantalla LCD:** Muestra los niveles de humedad y el estado del sistema.
- **Sistema de Alarma:** Incluye un LED y un zumbador.
- **Botón Pulsador:** Permite desactivar la alarma manualmente.

### Diseño de Medio Nivel

El diseño de medio nivel detalla las interacciones entre hardware y software:

- El **sensor DHT11** envía los datos de humedad al Arduino.
- El Arduino procesa los datos y controla:
  - La pantalla LCD para mostrar información.
  - El sistema de alarma para emitir alertas visuales y sonoras.
  - La recepción de la señal del botón pulsador.

### Diseño de Bajo Nivel

El diseño de bajo nivel describe las conexiones eléctricas:

1. **Sensor DHT11:**
   - Alimentación: Conectado a 5V y GND del Arduino.
   - Señal de datos: Pin digital 2.

2. **Pantalla LCD:**
   - Controlada mediante interfaz I2C (conexión a SDA y SCL del Arduino).

3. **Sistema de Alarma:**
   - LED: Conectado al pin digital 3.
   - Zumbador: Conectado al pin digital 4.

4. **Botón Pulsador:**
   - Conectado al pin digital 5 con resistencia pull-up interna.

## Implementación

### Componentes Utilizados

1. **Hardware:**
   - Sensor DHT11.
   - Arduino UNO.
   - Pantalla LCD con interfaz I2C.
   - LED rojo.
   - Zumbador.
   - Botón pulsador.

2. **Software:**
   - Lenguaje de programación: C++ (IDE de Arduino).
   - Librerías:
     - `DHT.h` para el sensor DHT11.
     - `LiquidCrystal_I2C.h` para la pantalla LCD.

### Código Fuente

El código fuente está completamente documentado y puede encontrarse en el repositorio en el archivo `automatizacion_cocina.ino`.

## Pruebas y Resultados

### Procedimiento de Pruebas

1. **Prueba del Sensor DHT11:**
   - Configuración del sensor para medir humedad.
   - Validación de los datos mostrados en la pantalla LCD.

2. **Prueba del Sistema de Alarma:**
   - Simulación de niveles altos de humedad para activar el LED y el zumbador.
   - Verificación del apagado manual mediante el botón pulsador.

3. **Prueba de Integración:**
   - Comprobación del funcionamiento conjunto del sensor, la pantalla LCD y la alarma.

### Resultados Obtenidos

El sistema respondió adecuadamente a las pruebas realizadas, cumpliendo con los objetivos del proyecto:
- Detección precisa de humedad.
- Activación y desactivación del sistema de alarma.
- Visualización clara de información en la pantalla LCD.

## Conclusiones

El sistema de automatización de la cocina fue diseñado e implementado exitosamente. Cumple con los requisitos establecidos y proporciona una solución funcional para la detección de niveles altos de humedad y la emisión de alertas. Este proyecto demuestra la aplicación efectiva de sensores y sistemas embebidos en entornos domésticos.

## Referencias

- Documentación oficial de Arduino: https://www.arduino.cc
- Librería DHT: https://github.com/adafruit/DHT-sensor-library
- Librería LiquidCrystal_I2C: https://github.com/johnrickman/LiquidCrystal_I2C



Contenido de ejemplo para este archivo.
