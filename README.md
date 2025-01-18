# Proyecto: Automatización de una Cocina

## Descripción General

Este proyecto implementa un sistema de automatización para una cocina que detecta niveles altos de humedad, simulando una fuga de gas, y emite una alarma visual y sonora. Además, cuenta con una pantalla LCD que muestra información en tiempo real y un botón pulsador para desactivar temporalmente la alarma.

---

## Características Principales

- **Sensor de Humedad (DHT11):** Detecta la humedad ambiental.
- **Sistema de Alarma:** Activación de un LED y un zumbador al superar el umbral definido.
- **Pantalla LCD:** Visualiza los niveles de humedad y el estado del sistema.
- **Botón Pulsador:** Permite desactivar manualmente la alarma.
- **Maqueta Simulada:** Representa una cocina funcional.

---

## Contenidos del Repositorio

```
proyecto-arduino-cocina/
├── codigo/
│   └── automatizacion_cocina.ino
├── diagramas/
│   ├── diseño_alto_nivel.png
│   ├── diseño_medio_nivel.png
│   ├── diseño_bajo_nivel.png
│   ├── flujo_sistema.png
│   └── Diagrama_Flujo_Electrico.png
├── maqueta/
│   ├── fotos/
│   │   ├── maqueta_frontal.jpg
│   │   ├── maqueta_lateral.jpg
│   │   └── maqueta_conexion.jpg
│   └── descripcion_maqueta.md
├── documentacion/
│   ├── informe_tecnico.pdf
│   ├── pasos_montaje.md
│   └── pruebas_funcionamiento.md
└── README.md
```

---

## Requisitos de Hardware

1. Arduino UNO.
2. Sensor DHT11.
3. Pantalla LCD con interfaz I2C.
4. LED rojo.
5. Zumbador.
6. Botón pulsador.
7. Resistencias de 220 Ω (2).
8. Cables de conexión.
9. Protoboard.

---

## Instrucciones de Uso

### 1. Configuración Inicial
- Descarga el código fuente del directorio `codigo/automatizacion_cocina.ino`.
- Abre el archivo en el IDE de Arduino.
- Asegúrate de tener instaladas las librerías necesarias:
  - `DHT.h`
  - `LiquidCrystal_I2C.h`

### 2. Carga del Código
- Conecta el Arduino a tu ordenador mediante un cable USB.
- Selecciona el puerto y la placa correcta en el IDE de Arduino.
- Sube el código al Arduino.

### 3. Ensamblaje
- Sigue los pasos detallados en el archivo `documentacion/pasos_montaje.md`.

### 4. Pruebas
- Consulta el archivo `documentacion/pruebas_funcionamiento.md` para verificar el correcto funcionamiento del sistema.

---

## Funcionamiento del Sistema

1. **Estado Normal:**
   - La pantalla LCD muestra los niveles de humedad en tiempo real.
   - No hay activación del sistema de alarma.

2. **Estado de Alerta:**
   - Cuando la humedad supera el 70%, el LED y el zumbador se activan.
   - La pantalla LCD muestra "ALARMA ACTIVADA".

3. **Desactivación Manual:**
   - El usuario puede presionar el botón pulsador para apagar temporalmente la alarma.

---

## Licencia

Este proyecto está bajo la Licencia MIT. Puedes usarlo y modificarlo libremente con fines educativos y personales.

---

## Contacto

**Autor:** Kevin Estrada  
**Correo:** kevin.estrada@example.com

