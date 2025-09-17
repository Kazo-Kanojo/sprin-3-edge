#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const int botao = 2;
bool rodando = false;
unsigned long tempoInicio = 0;
unsigned long tempoTotal = 0;

LiquidCrystal_I2C lcd(0x3F, 16, 2);

void mostrarTempo(unsigned long tempo);

void setup() {
  pinMode(botao, INPUT_PULLUP); 
  lcd.init();        
  lcd.backlight();   
  lcd.setCursor(0, 0);
  lcd.print("00:00"); 
  Serial.begin(9600);
}

void loop() {
  static bool ultimoEstado = HIGH;
  int leitura = digitalRead(botao);

  if (ultimoEstado == HIGH && leitura == LOW) {
    if (!rodando) {
      rodando = true;
      tempoInicio = millis();
    } else {
      rodando = false;
      tempoTotal += millis() - tempoInicio;
    }
    delay(50); 
  }
  ultimoEstado = leitura;

  unsigned long tempoAtual;
  if (rodando) {
    tempoAtual = tempoTotal + (millis() - tempoInicio);
  } else {
    tempoAtual = tempoTotal;
  }

  mostrarTempo(tempoAtual);  
  delay(100);
}


void mostrarTempo(unsigned long tempo) {
  unsigned long segundos = tempo / 1000;
  unsigned long minutos = segundos / 60;
  segundos = segundos % 60;

  lcd.setCursor(0, 0);
  if (minutos < 10) lcd.print("0");
  lcd.print(minutos);
  lcd.print(":");
  if (segundos < 10) lcd.print("0");
  lcd.print(segundos);

  Serial.print(minutos);
  Serial.print(":");
  if (segundos < 10) Serial.print("0");
  Serial.println(segundos);
}
