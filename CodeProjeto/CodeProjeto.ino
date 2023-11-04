// Exemplo 4 - Sensor de temperatura NTC
// Apostila Eletrogate - KIT Automação Residencial
//#include "acGraus.h"

#include <Arduino.h>
#include <IRremoteESP8266.h> // biblioteca Infravermelho
#include <IRsend.h> // biblioteca Infravermelho
#include <LiquidCrystal.h> // biblioteca Liquid Crystal

LiquidCrystal lcd(2, 0, 15, 13, 12, 14); // pinos do LCD - D4 D3 D8 D7 D6 D5
//int Vo;
//float R1 = 10000;
//float logR2, R2, T, Tc, Tf;
//float c1 = 1.009249522e-03, c2 = 2.378405444e-04, c3 = 2.019202697e-07;

#define Vin 3.3 // define constante igual a 3.3
#define T0 298.15 // define constante igual a 298.15 Kelvin
#define Rt 10000 // Resistor do divisor de tensao
#define R0 10000 // Valor da resistencia inicial do NTC
#define T1 273.15 // [K] in datasheet 0o C
#define T2 373.15 // [K] in datasheet 100° C
#define RT1 35563 // [ohms] resistencia in T1
#define RT2 549 // [ohms] resistencia in T2
float beta = 0.0; // parametros iniciais [K]
float Rinf = 0.0; // parametros iniciais [ohm]
float T = 0.0; // variable output
float Tc = 0.0; // variable output
float Vout = 0.0; // Vout in A0
float Rout = 0.0; // Rout in A0

const uint16_t kIrLed = 4;  // ESP8266 GPIO pin to use. Recommended: 4 (D2).
const uint16_t kRecvPin = 5;

IRsend irsend(kIrLed);  // Set the GPIO to be used to sending the message.
bool _onAir;
int graus;
int airCond = 0;

void setup(){
  Serial.begin(115200, SERIAL_8N1, SERIAL_TX_ONLY); // monitor serial
  irsend.begin();
  lcd.begin(16, 2); // inicializa LCD 16x2
  lcd.clear();

  beta = (log(RT1 / RT2)) / ((1 / T1) - (1 / T2)); // calculo de beta
  Rinf = R0 * exp(-beta / T0); // calculo de Rinf
}

void LCD(int airCond){
  lcd.clear(); // limpa tela do LCD
  lcd.setCursor(0, 0); // selecionando coluna 0 e linha 0
  lcd.print("Temp: "); // mostra no LCD
  lcd.print((int)Tc);
  lcd.print("\337C");
  lcd.setCursor(0, 1); // selecionando coluna 0 e linha 1
  lcd.print("Air Cond: ");
  if (airCond == 0) {
    lcd.print("Off");
  } else {
    lcd.print("On");
  }
}

//void onAir(bool _onAir){
//  if (_onAir == true) {
////    uint8_t stateON[8] = {0x08, 0x08, 0x60, 0x50, 0x00, 0x01, 0x00, 0xA0};
//    Serial.println("Send stateON");
//    _grausOFF((int)Tc);
//    irsend.sendGree(state);
//  }
//  else {
//    uint8_t stateOFF[8] = {0x00, 0x08, 0x20, 0x50, 0x00, 0x03, 0x00, 0x20};
//    Serial.println("Send stateOFF");
//    irsend.sendGree(state);
//  }
//}

float Temp(){
//  Vo = analogRead(0);
//  R2 = R1 * (1023.0 / (float)Vo - 1.0);
//  logR2 = log(R2);
//  T = (1.0 / (c1 + c2*logR2 + c3*logR2*logR2*logR2));
//  Tc = T - 273.15; // calculo da temp. em Celsius
  Vout = Vin * ((float)(analogRead(0)) / 1024.0); // calculo de V0 e leitura de A0
  Rout = (Rt * Vout / (Vin - Vout)); // calculo de Rout
  T = (beta / log(Rout / Rinf)); // calculo da temp. em Kelvins
  Tc = T- 273.15; // calculo da temp. em Celsius
  return Tc;
}

void loop(){

  graus = 24;
  Tc = Temp();
  LCD(airCond);

  
  Serial.println("Send stateOn with temp");
//  _grausOn((int)Tc);
  _grausOn(graus);
  airCond = 1;
  LCD(airCond);
  Serial.println(airCond);
  delay(5000);
//  _grausOff((int)Tc);
  _grausOff(graus);
  airCond = 0;
  Serial.println(airCond);
  LCD(airCond);
  delay(5000);
//  _onAir = true;
//  onAir(_onAir);
//  delay(1000);
//  _onAir = false;
//  onAir(_onAir);
//  delay(1000); // atraso de 1000 milisegundos
}
