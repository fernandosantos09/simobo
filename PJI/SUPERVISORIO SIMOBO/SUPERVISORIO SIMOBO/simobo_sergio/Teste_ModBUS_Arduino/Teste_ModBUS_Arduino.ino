 /*
 * Copyright © 2011-2012 Stéphane Raimbault <stephane.raimbault@gmail.com>
 * License ISC, see LICENSE for more details.
 */

#include <Modbusino.h>
#include "DHT.h"

//Sensores de Luminosidade
int LDR_0 = A0;
int LDR_1 = A1;

//Leds
int azul = 2;
int vermelho = 3;
int estado_led_vermelho;
int estado_led_azul;

int valor_LDR_0;
int valor_LDR_1;

//Configurações Sensor DHT-11
#define DHTPIN  A2 
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
float valor_umidade;
float valor_temperatura;

/* Initialize the slave with the ID 1 */
ModbusinoSlave modbusino_slave(1);
/* Allocate a mapping of 10 values */
uint16_t tab_reg[10];

void setup() {
    pinMode(azul,OUTPUT);
    pinMode(vermelho,OUTPUT);
    modbusino_slave.setup(9600);
    delay(100);
    dht.begin();
}

void loop() {

//Ler sensores
valor_LDR_0 = analogRead(LDR_0);
valor_LDR_1 = analogRead(LDR_1);
valor_umidade = dht.readHumidity();
valor_temperatura= dht.readTemperature();

//Organizar pacotes
tab_reg[0] = valor_LDR_0;
tab_reg[1] = valor_LDR_1;
tab_reg[2] = valor_umidade;
tab_reg[3] = valor_temperatura;

//Enviar para o Elipse Scada
modbusino_slave.loop(tab_reg, 10);

//Atualizar estado dos Leds do controle do supervisório
estado_led_vermelho = tab_reg[4];
estado_led_azul= tab_reg[5];
digitalWrite(azul,estado_led_azul);
digitalWrite(vermelho,estado_led_vermelho);


}
