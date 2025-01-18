# # Pasos de Montaje del Proyecto: Automatización de una Cocina

## Introducción
Este documento proporciona una guía detallada para ensamblar el sistema de automatización de una cocina, conectando correctamente los componentes electrónicos y preparando la maqueta funcional.

---

## Lista de Materiales

1. **Componentes Electrónicos:**
   - Sensor DHT11 (1 unidad).
   - Arduino UNO (1 unidad).
   - Pantalla LCD con interfaz I2C (1 unidad).
   - LED rojo (1 unidad).
   - Zumbador (1 unidad).
   - Botón pulsador (1 unidad).
   - Resistencias de 220 Ω (2 unidades).
   - Cables de conexión (varios).

2. **Herramientas:**
   - Protoboard.
   - Soldador y estaño (opcional).
   - Destornillador pequeño.
   - Multímetro (opcional para pruebas).

3. **Materiales para la Maqueta:**
   - Cartón, madera o acrílico (para la estructura).
   - Pegamento o cinta adhesiva.
   - Tijeras o cutter.

---

## Instrucciones de Montaje

### Paso 1: Preparación del Arduino y Protoboard
1. Coloca el Arduino UNO en un área segura y accesible.
2. Conecta el protoboard cerca del Arduino para facilitar las conexiones.

### Paso 2: Conexión del Sensor DHT11
1. Identifica los tres pines del DHT11: VCC, GND y Datos.
2. Conecta:
   - VCC al pin de 5V del Arduino.
   - GND al pin GND del Arduino.
   - Datos al pin digital 2 del Arduino.
3. Usa un cable para asegurar una conexión estable.

### Paso 3: Instalación de la Pantalla LCD
1. Conecta la pantalla LCD al Arduino mediante el adaptador I2C:
   - SDA al pin A4 del Arduino.
   - SCL al pin A5 del Arduino.
   - VCC al pin de 5V.
   - GND al pin GND.
2. Asegúrate de que los cables estén bien fijados.

### Paso 4: Conexión del Sistema de Alarma
1. **LED rojo:**
   - Conecta una resistencia de 220 Ω al pin digital 3 del Arduino.
   - Conecta el otro extremo de la resistencia al ánodo (+) del LED.
   - Conecta el cátodo (-) del LED al GND.

2. **Zumbador:**
   - Conecta el pin positivo del zumbador al pin digital 4 del Arduino.
   - Conecta el pin negativo al GND.

### Paso 5: Conexión del Botón Pulsador
1. Coloca el botón en el protoboard.
2. Conecta:
   - Un extremo al pin digital 5 del Arduino.
   - El otro extremo a GND.
   - Usa la resistencia pull-up interna del Arduino para estabilizar la señal.

### Paso 6: Ensamblaje de la Maqueta
1. Diseña la estructura de la maqueta para representar una cocina.
2. Fija los componentes en sus posiciones correspondientes:
   - El sensor DHT11 cerca de la "zona de riesgo" (simulada).
   - La pantalla LCD en un lugar visible.
   - El LED y el zumbador cerca del sensor.
3. Usa pegamento o tornillos para asegurar los componentes.

### Paso 7: Alimentación y Pruebas
1. Conecta el Arduino a una fuente de alimentación (cable USB o batería).
2. Sube el código al Arduino desde el IDE.
3. Verifica que:
   - El sensor mide correctamente la humedad.
   - La pantalla LCD muestra los valores adecuados.
   - El LED y el zumbador se activan cuando se detecta alta humedad.
   - El botón desactiva la alarma correctamente.

---

## Notas Finales

- Asegúrate de revisar todas las conexiones antes de encender el sistema.
- Usa el multímetro para comprobar la continuidad de las conexiones si es necesario.
- Consulta el código fuente para verificar los pines y la lógica del sistema.

Con estos pasos, el sistema estará completamente ensamblado y listo para su demostración.

