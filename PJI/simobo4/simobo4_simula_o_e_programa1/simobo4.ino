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
float conversao1,conversao2,conversao3;
int conv4,conv5;
int volume,volumeLITROS,sensorA,sensorB;
int base,altura,largura;
int contador1,contador2,contador3,clicks;


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
    delay(1000);
  
  // Considerando objeto de base 20cm,largura 18cm e altura 25cm.
	  
  	  base = 20 ;
  	  altura = 40;
  	  largura = 20;
  
  	 
  	  
      //Serial.println(distanciaCM);
      //Serial.println(conversao2);
  
      int porcentagem;
      porcentagem = 0;
      porcentagem = (distanciaCM * 100)/40;
      conversao3 = (map(porcentagem,0,100,100,0));
  		
   	  conv4 = (map(distanciaCM,6,18,0,100));
  	  conv5 = (map(conv4,0,100,100,0));
  	  //Serial.print(conv5);
      //Serial.println("%");
  	  delay(500);
  
  	
  
  	
  	  lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("NIVEL ATUAL:");
  	  lcd.setCursor(13,0);
      lcd.print(conv5);
      lcd.setCursor(15,0);
      lcd.print("%");
      lcd.setCursor(1,1);
      lcd.print("DO RESERVATORIO");
      delay(2000);
  
  
  
  
  if(clicks==0){
    if(contador1 < 10 && conv5 < 100){
      if(sensorB==1){
        
        contador1++;
        
        contador2 = contador1 * 10;
        Serial.print(contador2);
        Serial.println("%");
          
        lcd.clear();
      	lcd.setCursor(6,0);
      	lcd.print(contador2);
        lcd.setCursor(8,0);
      	lcd.print("%");
      	lcd.setCursor(1,1);
        lcd.print("ACRESCENTADOS");
        delay(2000);
        
        contador3= contador2 + conv5;
        
        Serial.print(contador3);
        
        //lcd.clear();
      	//lcd.setCursor(3,0);
      	//lcd.print("NOVO NIVEL");
      	//lcd.setCursor(8,1);
        //lcd.print(contador3);
        //lcd.setCursor(10,1);
      	//lcd.print("%");
        //delay(2000);
        
        
		
        if(contador1==10 ){
    		contador1=0;
    		contador2=0;
    	}
      }
    }
  }
  	Serial.print(contador3);	
  
  if(contador3 > conv5){
    if(contador1>0){
    
    
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("ACRESCENTANDO...");
      lcd.setCursor(0,1);
      lcd.print("NOVO NIVEL:");
      lcd.setCursor(12,1);
      lcd.print(contador3);
      lcd.setCursor(14,1);
      lcd.print("%");
      delay(2000);
    
      
      
      
      digitalWrite(modrele,HIGH);
    
      
    
 }
  }  
	if(contador3 <= conv5){
        digitalWrite(modrele,LOW);
      }
  
  
  if(sensorA==1 && sensorB==1){ // Se sensor de nivel baixo e alto OFF, NIVEL CRITICO
      lcd.clear();
      lcd.setCursor(2,0);
      lcd.print("NIVEL CRITICO");
      lcd.setCursor(1,1);
      lcd.print("DO RESERVATORIO");
      delay(2000);
    
   	  
 }
    //if(sensorA==0 && sensorB==1){ //Se sensor nivel baixo ON e alto OFF, mostra o ultrassonico
     
      
      //lcd.clear();
      //lcd.setCursor(7,0);
      //lcd.print(conv5);
      //lcd.setCursor(6,0);
      //lcd.print("%");
      //lcd.setCursor(1,1);
      //lcd.print("DO RESERVATORIO");
      //delay(2000);
      
	  
   // }
  
    if(sensorA==0 && sensorB==0){ //Se os dois sensores ON, NIVEL MAXIMO
    lcd.clear();
      lcd.setCursor(2,0);
      lcd.print("NIVEL MAXIMO");
      lcd.setCursor(1,1);
      lcd.print("DO RESERVATORIO");
      
      digitalWrite(modrele, LOW);
    
    }
}
