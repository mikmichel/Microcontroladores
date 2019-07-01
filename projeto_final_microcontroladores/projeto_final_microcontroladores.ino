// http://megumijr.com/Video-MonitorCaixa.php

int IN1 = 4;
int IN2 = 5;
const int ledMotor = 3;

const int pinLed4 = 12;
const int pinLed3 = 11; 
const int pinLed2 = 10;
const int pinLed1 = 9; 
const int pinProbe4 = A1; 
const int pinProbe3 = A2; 
const int pinProbe2 = A3;
const int pinProbe1 = A4; 
const int vRef = 10; // Valor superior às leituras flutuantes por indutância 
float p4 = 0;
float p3 = 0; 
float p2 = 0; 
float p1 = 0;
void setup() { 

   pinMode(ledMotor, OUTPUT);
   pinMode(IN1, OUTPUT);
   pinMode(IN2, OUTPUT);
  
   // Inicializa pins. 
   pinMode(pinLed4, OUTPUT); 
   pinMode(pinLed3, OUTPUT);
   pinMode(pinLed2, OUTPUT); 
   pinMode(pinLed1, OUTPUT);
    
   pinMode(pinProbe4, INPUT);
   pinMode(pinProbe3, INPUT); 
   pinMode(pinProbe2, INPUT);   
   pinMode(pinProbe1, INPUT);
   // Inicia serial para debug 
   Serial.begin(9600); 
} 
 
void loop() { 
   // Leitura dos probes 
   p4 = analogRead(pinProbe4);
   p3 = analogRead(pinProbe3); 
   p2 = analogRead(pinProbe2);
   p1 = analogRead(pinProbe1); 
 
   // Para debug 
   Serial.print(p1);  
   Serial.print(" ");
   Serial.print("\n"); 

   Serial.print(p2);  
   Serial.print(" ");
   Serial.print("\n"); 

   Serial.print(p3);  
   Serial.print(" ");
   Serial.print("\n"); 

   Serial.print(p3);  
   Serial.print(" ");
   Serial.print("\n"); 
   //Serial.print(pL); 
   Serial.print(" "); 
   //Serial.print("\n");
   // delay(500); 
 
   // Reseta todos os leds 
   digitalWrite(pinLed4, LOW);
   digitalWrite(pinLed3, LOW); 
   digitalWrite(pinLed2, LOW);
   digitalWrite(pinLed1, LOW); 
 
   // Nível > 3/4: liga somente led verde 
   if (p4 > vRef) { 
      digitalWrite(pinLed4, HIGH);
      digitalWrite(pinLed3, HIGH);
      digitalWrite(pinLed2, HIGH);
      digitalWrite(pinLed1, HIGH); 

      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);  
      digitalWrite(ledMotor, LOW); 
      
   } 
   
   if (p4 < vRef && p3 > vRef) {
      digitalWrite(pinLed4, LOW);
      digitalWrite(pinLed3, HIGH);
      digitalWrite(pinLed2, HIGH);
      digitalWrite(pinLed1, HIGH); 
   }

   if (p3 < vRef && p2 > vRef) {
      digitalWrite(pinLed4, LOW);
      digitalWrite(pinLed3, LOW);
      digitalWrite(pinLed2, HIGH);
      digitalWrite(pinLed1, HIGH); 
   }  
   
   if (p2 < vRef && p1 > vRef) {
      digitalWrite(pinLed4, LOW);
      digitalWrite(pinLed3, LOW);
      digitalWrite(pinLed2, LOW);
      digitalWrite(pinLed1, HIGH); 

      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(ledMotor, HIGH); 
   }      
} 
 
