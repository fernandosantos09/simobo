#include <LiquidCrystal.h>

LiquidCrystal lcd(3,4,5,6,7,8);
#define echoPin 9 //recebe
#define trigPin 10 //envia 
#define botaoA 11 // Sensor B
#define botaoB 12 // Sensor A
#define botaoC 2 // acrescenta nivel
#define modrele 13// Controle do modulo

int duracao = 0;
int distanciaCM = 0;
int conv4,conv5;
int sensorA,sensorB;
int contador1,contador2,contador3,clicks;
int bomba=1;

void setup()
{
  
  lcd.begin(16,2);
  lcd.clear();
  pinMode(echoPin,INPUT);
  pinMode(trigPin,OUTPUT);
  pinMode(modrele,OUTPUT);
  pinMode(botaoA, INPUT_PULLUP);
  pinMode(botaoB, INPUT_PULLUP);
  pinMode(botaoC, INPUT_PULLUP);
  Serial.begin(9600);
  digitalWrite(modrele,HIGH);
  
}

void loop()
{
    sensorA=digitalRead(botaoA); // lEITURA SENSOR A
    sensorB=digitalRead(botaoB); // LEITURA SENSOR B
    clicks=digitalRead(botaoC); // LEITURA SENSOR C
    
  
  
    digitalWrite(trigPin,HIGH); //LIGA PINO TRIG
  	delayMicroseconds(5); // DELAY EM MICROSSEGUNDOS
  	digitalWrite(trigPin,LOW); //DESLIGA PINO TRIG
    delayMicroseconds(10); // DELAY EM MICROSSEGUNDOS
   
  
  
  	duracao = pulseIn(echoPin,HIGH); // RECEBE VALOR PINO ECHO
    distanciaCM = duracao*0.017175; //((344*100)/ 10e6)
    delay(500);
  

      
      Serial.println(distanciaCM);
      
     
      
      conv4 = (map(distanciaCM,4,17.1,0,100));
      conv5 = (map(conv4,0,100,100,0));
      //Serial.print(conv5);
      //Serial.println("%");
      
  
    
  
  if(bomba==1){  
     lcd.clear();
     lcd.setCursor(0,0);
     lcd.print("NIVEL ATUAL:");
     lcd.setCursor(13,0);
     lcd.print(conv5);
     lcd.setCursor(15,0);
     lcd.print("%");
     lcd.setCursor(1,1);
     lcd.print("DO RESERVATORIO");
     delay(1500);
  
  } 

   if(clicks==0){
  contador1++;
   }
  
  if(contador1==1){
    if(sensorB==1){
      
  digitalWrite(modrele, LOW);
  delay(50);
  
      lcd.clear();
      lcd.setCursor(2,0);
      lcd.print("BOMBA LIGADA");
      lcd.setCursor(0,1);
      lcd.print("NIVEL ATUAL:");
      lcd.setCursor(13,1);
      lcd.print(conv5);
      lcd.setCursor(15,1);
      lcd.print("%");
      delay(1500);
      bomba=0;
    }
} 
  if(contador1 > 1){ 
  bomba=1;
  contador1=0;
  digitalWrite(modrele, HIGH);
}

    
  
  if(sensorA==1 && sensorB==1){ // Se sensor de nivel baixo e alto OFF, NIVEL CRITICO
    if(bomba==1){
    
      lcd.clear();
      lcd.setCursor(2,0);
      lcd.print("NIVEL CRITICO");
      lcd.setCursor(1,1);
      lcd.print("DO RESERVATORIO");
      delay(1500);
    
    
    
    }   
 }
    
    if(sensorA==0 && sensorB==0){ //Se os dois sensores ON, NIVEL MAXIMO
    lcd.clear();
      lcd.setCursor(2,0);
      lcd.print("NIVEL MAXIMO");
      lcd.setCursor(1,1);
      lcd.print("DO RESERVATORIO");
      

  }
}