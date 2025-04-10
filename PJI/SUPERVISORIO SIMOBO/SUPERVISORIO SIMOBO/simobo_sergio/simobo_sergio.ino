#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);  // Chamada da funcação LiquidCrystal para ser usada com o I2C

#define echoPin 9   //recebe
#define trigPin 10  //envia
#define botaoA 11   // Sensor B
#define botaoB 12   // Sensor A
#define modrele 13  // Controle do modulo
#define valvula 6   //valvula
const int sensorPin = A0;

int duracao = 0;
int distanciaCM = 0;
int conv4, conv5;
int sensorA, sensorB;
int contador1, contador2, contador3,valvula2, clicks;
int bomba = 1;
float vazao;
float sensorValue;
float vazaoConvertida;



const int linhas = 1;   // Número de linhas no teclado
const int colunas = 2;  // Número de colunas no teclado

// Definindo os pinos do teclado
const int pinosLinhas[linhas] = { 2 };
const int pinosColunas[colunas] = { 3, 4 };


void setup() {
  Serial.begin(9600);

  lcd.init();  // Serve para iniciar a comunicação com o display já conectado
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("ON");

  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(modrele, OUTPUT);
  pinMode(botaoA, INPUT_PULLUP);
  pinMode(botaoB, INPUT_PULLUP);
  pinMode(sensorPin, INPUT);

  digitalWrite(modrele, HIGH);
  digitalWrite(valvula, HIGH);

  

  // Configurando os pinos de linha como OUTPUT
  for (int i = 0; i < linhas; i++) {
    pinMode(pinosLinhas[i], OUTPUT);
    digitalWrite(pinosLinhas[i], HIGH);  // Configurando para alto por padrão
  }

  // Configurando os pinos de coluna como INPUT com resistor de pull-up
  for (int i = 0; i < colunas; i++) {
    pinMode(pinosColunas[i], INPUT_PULLUP);
  }
}
void loop() {
 
  sensorA = digitalRead(botaoA);  // lEITURA SENSOR A
  sensorB = digitalRead(botaoB);  // LEITURA SENSOR B

  digitalWrite(trigPin, HIGH);  //LIGA PINO TRIG
  delayMicroseconds(5);         // DELAY EM MICROSSEGUNDOS
  digitalWrite(trigPin, LOW);   //DESLIGA PINO TRIG
  delayMicroseconds(10);        // DELAY EM MICROSSEGUNDOS

  duracao = pulseIn(echoPin, HIGH);  // RECEBE VALOR PINO ECHO
  distanciaCM = duracao * 0.017175;  //((344*100)/ 10e6)
  delay(500);

  sensorValue = analogRead(sensorPin);
  vazaoConvertida = map(sensorValue, 0, 1023, 0, 100);

  //Serial.println(distanciaCM);

  conv4 = (map(distanciaCM, 2.7, 17.1, 0, 100));
  conv5 = (map(conv4, 0, 100, 100, 0));
  //Serial.print(conv5);
  //Serial.println("%");
  
  // Lê o valor do sensor de fluxo
  sensorValue = analogRead(sensorPin);
  vazaoConvertida = map(sensorValue, 0, 1023, 0, 100);
  
  if (bomba == 1) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("NIVEL ATUAL:");
    lcd.setCursor(13, 0);
    lcd.print(conv5);
    lcd.setCursor(15, 0);
    lcd.print("%");
    lcd.setCursor(1, 1);
    lcd.print("DO RESERVATORIO");
    delay(1000);
  }


  // Verificando as teclas pressionadas
  for (int i = 0; i < linhas; i++) {
    // Configurando a linha atual como LOW
    digitalWrite(pinosLinhas[i], LOW);

    // Verificando as colunas para teclas pressionadas
    for (int j = 0; j < colunas; j++) {
      if (digitalRead(pinosColunas[j]) == LOW) {
        // Tecla pressionada
        int tecla = i * colunas + j + 1;  // Calculando o número da tecla
                                          // Serial.println("Tecla pressionada: " + String(tecla));


        // Lógica para lidar com as teclas 1 e 2
        if (tecla == 1 ) {
          // Código para a tecla 1
          Serial.println("Tecla 1 pressionada");
          delay(500);

          if (tecla == 1) {
            contador1++;
          }

          if (contador1 == 1) {
            if (sensorB == 1 && contador2 == 0) {


              digitalWrite(modrele, LOW);
              delay(50);
              digitalWrite(valvula, HIGH);

              lcd.setBacklight(HIGH);  // Serve para ligar a luz do display

              lcd.clear();
              lcd.setCursor(2, 0);
              lcd.print("BOMBA LIGADA");
              lcd.setCursor(0, 1);
              lcd.print("ACRESCENTANDO NIVEL");
              lcd.setCursor(0, 2);
              lcd.print("NIVEL INICIAL:");
              lcd.setCursor(15, 2);
              lcd.print(conv5);
              lcd.setCursor(17, 2);
              lcd.print("%");
              delay(1500);
              bomba = 0;
            }
          }
          if (contador1 > 1) {
            bomba = 1;
            contador1 = 0;
            digitalWrite(modrele, HIGH);
            digitalWrite(valvula, HIGH);
          }
         
        }
      
          
    digitalWrite(pinosLinhas[i], HIGH);
      
        }
      
    
}

  if (sensorA == 1 && sensorB == 1) {  // Se sensor de nivel baixo e alto OFF, NIVEL CRITICO
    if (bomba == 1) {
      if(valvula2=1){
      lcd.clear();
      lcd.setCursor(2, 0);
      lcd.print("NIVEL CRITICO");
      lcd.setCursor(1, 1);
      lcd.print("DO RESERVATORIO");
      delay(1500);
    }
  }
  }
  if (sensorA == 0 && sensorB == 0) {  //Se os dois sensores ON, NIVEL MAXIMO
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("NIVEL MAXIMO");
    lcd.setCursor(1, 1);
    lcd.print("DO RESERVATORIO");
  }

}
} 
