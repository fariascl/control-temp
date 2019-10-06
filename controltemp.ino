#include <OneWire.h>
#include <DallasTemperature.h>
#define Pin 2
OneWire ourWire(Pin);
DallasTemperature sensors(&ourWire);
const int cale = 9; // Declara constante del calentador
const int vent = 8; // Declara constante del ventilador
const int Temp = 39.50; // Temperatura seteada

void setup(void){
  pinMode(cale, OUTPUT);
  pinMode(vent, OUTPUT);
  Serial.begin(9600);
  sensors.begin(); // Se inician los sensores
}

void loop(void){
  float t = sensors.getTempCByIndex(0);
  sensors.requestTemperatures(); // Prepara el sensor para lectura
  Serial.print(); // Imprime la temperatura en celsius
  Serial.println(" grados Centigrados ");

  if (t < Temp){
    digitalWrite(cale, HIGH);
    digitalWrite(vent, LOW);
  }
  else if (t > Temp){
    digitalWrite(vent, HIGH);
    digitalWrite(cale, LOW);
  }
  delay(3000);
}
