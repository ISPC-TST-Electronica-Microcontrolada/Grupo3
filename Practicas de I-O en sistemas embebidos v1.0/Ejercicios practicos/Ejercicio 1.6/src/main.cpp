#include <Arduino.h>
int Rele = 13;
char tecla;
char clave[11];
char clave_maestra [11] = "2147483648";
byte indice = 0;

void setup () {
Serial.begin(9600);
pinMode(Rele,OUTPUT);
Serial.println("Ingrese el codigo:");
}

void loop() {
  
   if (Serial.available()) {
      boolean prenderele = false;
      tecla = Serial.read();     
	 if(tecla){
	    clave[indice] = tecla;
	    indice++;
	    Serial.print(tecla);      
	 }
   if(indice == 10){
      if(!strcmp(clave, clave_maestra)){
	 Serial.println(" CONTRASEÑA CORRECTA ");
         prenderele = true;
	 indice = 0;
      }else{
	 prenderele = false;
	 Serial.println(" CONTRASEÑA INCORRECTA ");
         indice = 0;
      }
   }     
   //Activar el rele
   if (prenderele){
      digitalWrite(Rele, HIGH); // Activa rele
      delay(8000); // Lo activa 8 segundos    
      digitalWrite(Rele, LOW); // Apaga rele
    }
  }
}