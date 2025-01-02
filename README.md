# Repositorio del Proyecto: Automatización de una Cocina

Este repositorio contiene el código, diseños, y documentación completa para el proyecto **"Automatización de una Cocina"**, desarrollado como evaluación final de la asignatura.

## Descripción General
El proyecto consiste en un sistema de automatización que detecta niveles altos de humedad (simulando una fuga de gas) y emite una alarma visual y sonora. Además, incluye una pantalla LCD que muestra el estado del sistema y un botón pulsador para desactivar temporalmente la alarma.

### Características Principales
- **Sensor de Humedad (DHT11):** Mide los niveles de humedad en el ambiente.
- **Sistema de Alarma:** Activación de un LED rojo y un buzzer cuando se superan los límites establecidos.
- **Pantalla LCD:** Muestra el nivel de humedad y un mensaje de alarma.
- **Botón Pulsador:** Permite desactivar la alarma y reiniciar un contador en la pantalla LCD.
- **Simulación en Maqueta:** Todo el sistema está integrado en una maqueta que simula una cocina.

---

## Estructura del Repositorio

```
proyecto-arduino-cocina/
├── codigo/
│   └── automatizacion_cocina.ino
├── diagramas/
│   ├── diseño_alto_nivel.png
│   ├── diseño_electrico.png
│   └── flujo_sistema.png
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

## Código Fuente
```cpp
#include <DHT.h>
#include <LiquidCrystal_I2C.h>

#define DHTPIN 2        // Pin del sensor DHT11
#define DHTTYPE DHT11   // Tipo de sensor
#define LEDPIN 3        // Pin del LED rojo
#define BUZZERPIN 4     // Pin del zumbador
#define BUTTONPIN 5     // Pin del botón pulsador

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);

bool alarmaActiva = false;
unsigned long tiempoInicio = 0;
const unsigned long tiempoDesactivacion = 5000; // 5 segundos

void setup() {
  pinMode(LEDPIN, OUTPUT);
  pinMode(BUZZERPIN, OUTPUT);
  pinMode(BUTTONPIN, INPUT_PULLUP);
  dht.begin();
  lcd.init();
  lcd.backlight();
}

void loop() {
  float humedad = dht.readHumidity();

  if (isnan(humedad)) {
    lcd.setCursor(0, 0);
    lcd.print("Error Sensor");
    return;
  }

  lcd.setCursor(0, 0);
  lcd.print("Humedad: ");
  lcd.print(humedad);
  lcd.print("%");

  if (alarmaActiva && millis() - tiempoInicio > tiempoDesactivacion) {
    alarmaActiva = false;
  }

  if (humedad > 70 && !alarmaActiva) {
    digitalWrite(LEDPIN, HIGH);
    digitalWrite(BUZZERPIN, HIGH);
    lcd.setCursor(0, 1);
    lcd.print("ALARMA ACTIVADA");
    alarmaActiva = true;
  }

  if (digitalRead(BUTTONPIN) == LOW) {
    digitalWrite(LEDPIN, LOW);
    digitalWrite(BUZZERPIN, LOW);
    lcd.setCursor(0, 1);
    lcd.print("ALARMA OFF     ");
    alarmaActiva = false;
    tiempoInicio = millis();
  }
}
```

---

## Contribuciones
Este proyecto fue desarrollado por **Kevin Estrada** y está diseñado para fines educativos. Se aceptan sugerencias y mejoras.

---

## Licencia
Este proyecto está bajo la Licencia MIT.
