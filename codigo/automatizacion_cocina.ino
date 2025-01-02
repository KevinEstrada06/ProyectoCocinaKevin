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
