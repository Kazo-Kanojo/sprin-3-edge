# ⏱️ Cronômetro com Arduino e Display LCD I2C

Este projeto implementa um cronômetro simples utilizando um **Arduino UNO**, um **display LCD 16x2 com interface I2C** e um **botão** para iniciar/parar a contagem do tempo.

---

## 🚀 Funcionalidades
- Inicia e pausa a contagem do tempo com apenas um botão.
- Exibe o tempo decorrido no formato **MM:SS** no display LCD.
- Também envia o tempo decorrido para o **Monitor Serial**.
- Tempo continua acumulado mesmo após pausar.

---

## 🛠️ Componentes Utilizados
- 1x Arduino UNO  
- 1x Display LCD 16x2 com módulo I2C  
- 1x Botão (push button)  
- 1x Resistor de 10kΩ (caso o botão não use `INPUT_PULLUP`)  
- Jumpers de conexão  

---

## 🔌 Ligações (Wiring)

### LCD I2C
- **GND → GND (Arduino)**  
- **VCC → 5V (Arduino)**  
- **SDA → A4 (Arduino UNO)**  
- **SCL → A5 (Arduino UNO)**  

### Botão
- Um terminal → **pino digital 2 (Arduino)**  
- Outro terminal → **GND**  
*(O `INPUT_PULLUP` já ativa o resistor interno de pull-up, então não é necessário resistor externo.)*

---

## 📂 Estrutura do Código
O código utiliza a biblioteca **LiquidCrystal_I2C** para comunicação com o display.  

- `setup()` → Inicializa LCD, botão e comunicação serial.  
- `loop()` → Verifica se o botão foi pressionado para iniciar/pausar o cronômetro.  
- `mostrarTempo()` → Converte os milissegundos em minutos e segundos e exibe no LCD/Serial.  

---

## 📦 Bibliotecas Necessárias
Antes de carregar o código, instale a biblioteca:  
- **LiquidCrystal I2C**  
- **Wire.h** (já vem na IDE Arduino)

No Arduino IDE:  
```text
Sketch → Incluir Biblioteca → Gerenciar Bibliotecas → Pesquisar: LiquidCrystal I2C
