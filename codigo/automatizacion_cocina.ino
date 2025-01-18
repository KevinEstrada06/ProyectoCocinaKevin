#include <DHT.h>
#include <LiquidCrystal_I2C.h>

// Definiciones de pines
#define DHTPIN 2        // Pin del sensor DHT11
#define DHTTYPE DHT11   // Tipo de sensor DHT
#define LEDPIN 3        // Pin del LED rojo
#define BUZZERPIN 4     // Pin del zumbador
#define BUTTONPIN 5     // Pin del botón pulsador

// Configuración del sensor y la pantalla LCD
DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Variables del sistema
bool alarmaActiva = false;
unsigned long tiempoInicio = 0;
const unsigned long tiempoDesactivacion = 5000; // Tiempo de desactivación de alarma en milisegundos

void setup() {
  // Configuración de pines
  pinMode(LEDPIN, OUTPUT);
  pinMode(BUZZERPIN, OUTPUT);
  pinMode(BUTTONPIN, INPUT_PULLUP);

  // Inicialización de componentes
  dht.begin();
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Sistema Iniciado");
  delay(2000);
  lcd.clear();
}

void loop() {
  // Lectura de la humedad
  float humedad = dht.readHumidity();

  if (isnan(humedad)) {
    lcd.setCursor(0, 0);
    lcd.print("Error Sensor");
    return;
  }

  // Mostrar la humedad en la pantalla LCD
  lcd.setCursor(0, 0);
  lcd.print("Humedad: ");
  lcd.print(humedad);
  lcd.print("%   ");

  // Verificar si la alarma debe estar activa
  if (alarmaActiva && millis() - tiempoInicio > tiempoDesactivacion) {
    alarmaActiva = false; // Desactivar la alarma automáticamente
  }

  if (humedad > 70 && !alarmaActiva) { // Umbral de alarma
    activarAlarma();
  }

  // Verificar si se presiona el botón para desactivar la alarma
  if (digitalRead(BUTTONPIN) == LOW) {
    desactivarAlarma();
  }
}

void activarAlarma() {
  digitalWrite(LEDPIN, HIGH);
  digitalWrite(BUZZERPIN, HIGH);
  lcd.setCursor(0, 1);
  lcd.print("ALARMA ACTIVADA");
  alarmaActiva = true;
}

void desactivarAlarma() {
  digitalWrite(LEDPIN, LOW);
  digitalWrite(BUZZERPIN, LOW);
  lcd.setCursor(0, 1);
  lcd.print("ALARMA OFF     ");
  alarmaActiva = false;
  tiempoInicio = millis();
}
