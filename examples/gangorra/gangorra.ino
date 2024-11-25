#include "driver_lcd_i2c.h"

DriverLCD_I2C lcdDriver(0x27, 16, 2);  // Endereço I2C do LCD, 16 colunas e 2 linhas

void setup() {
  // Inicializa a comunicação serial para depuração
  Serial.begin(9600);
  Serial.println("Iniciando testes do LCD...");
  delay(500);
}

void loop() {
  lcdDriver.dashboardLightOn();
  // Testa a exibição de ângulo
  lcdDriver.postAngle(45.75);
  delay(2000);  // Espera 1 segundo para visualizar o resultado

  // Testa a exibição do modo operacional
  lcdDriver.postOperatingMode(DriverLCD_I2C::Modo::Manual);
  delay(2000);
  lcdDriver.postOperatingMode(DriverLCD_I2C::Modo::Automatico);
  delay(2000);
  lcdDriver.postOperatingMode(DriverLCD_I2C::Modo::Ensaio);
  delay(2000);

  // Testa a exibição de distância TOF (simulando valores)

  lcdDriver.postTofRight(23.5);
  delay(2000);
  lcdDriver.postTofLeft(18.2);
  delay(2000);

  // Testa a exibição de aceleração
  lcdDriver.postAccelerometer(9.81);
  delay(2000);

  // Testa a exibição de ponto de ajuste
  lcdDriver.postSetPoint(15.25);
  delay(2000);

  // Testa a exibição de consumo de energia (voltagem e corrente)
  lcdDriver.postConsumption(12.5, 3.2, "mV", "mA");
  delay(2000);

  // Testa limpar linha específica
  lcdDriver.clearLine(1);  // Limpa a segunda linha
  delay(2000);
  lcdDriver.postSetPoint(15.25);
  delay(2000);
  lcdDriver.clearLine(0);  // Limpa a primeira linha
  delay(2000);
  lcdDriver.postTofLeft(18.2);
  delay(2000);
  lcdDriver.postTofRight(128.233);
  delay(2000);
  lcdDriver.dashboardLightOff();
  // Testa o retroiluminamento
  delay(2000);

}