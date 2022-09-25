#include <Arduino.h>
//DECLARO VARIABLES
float DistanciaObstaculo = 0;
int velocidad = 115;
int velocidadGiro = 100;
//NOMBRAMOS PINES
//pines de motores
  #define ENA_IZQ 15
  #define IN1 2
  #define IN2 0
  #define ENB_DER 17
  #define IN3 4
  #define IN4 16
//pines de ultrasonico
  #define pinTrig 14
  #define pinEcho 12
//define correspondiente a los sensores IR
  #define pinIR_Centro 18
  #define pinIR_Izquierda 5
  #define pinIR_Derecha 19




//Declaro funciones

void HABILITAR_MOTORES() {
  analogWrite(ENA_IZQ, velocidad); //encendemos motores 
  analogWrite(ENB_DER, velocidad); //encendemos motores 
}

void AVANZAR() {
  HABILITAR_MOTORES();

  //HACIENDO QUE EL MOTOR A (LADO IZQ) GIRE EN SENTIDO HORARIO
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  
  //HACIENDO QUE EL MOTOR B (LADO DER) GIRE EN SENTIDO HORARIO
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
}

void RETROCESO(){
  HABILITAR_MOTORES();

   //HACIENDO QUE EL MOTOR A (LADO IZQ) GIRE EN SENTIDO ANTI HORARIO
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  
  //HACIENDO QUE EL MOTOR B (LADO DER) GIRE EN ANTI HORARIO
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
}

void STOP() {
  analogWrite(ENA_IZQ, 0);  //apago motores IZQ
  analogWrite(ENB_DER, 0); //apago motores DER
  
}

void GIRAR_IZQ() {
  HABILITAR_MOTORES();
 
//motores IZQ giran anti horario
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);

//motores DER giran horario
  digitalWrite(IN3,HIGH); 
  digitalWrite(IN4,LOW);
}

void GIRAR_DER() {
  HABILITAR_MOTORES();
  
//motores IZQ giran horario
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);

//motores DER giran anti horario
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
  
}

//DEFINO FUNCIÓN "MEDIR DISTANCIA"
float medirDistancia(){
  long duracion = 0; //variable para almacenar el tiempo 
  int distancia = 0; //variable para almacenar la distancia hasta el obstáculo
  digitalWrite(pinTrig, LOW); //nos aseguramos que el pin "trig" se encuentre en estado bajo
  delayMicroseconds(2);
  digitalWrite(pinTrig, HIGH); //colocamos en alto el pin "trig"
  delayMicroseconds(10);        //esperamos 10 microsegundos para generar el pulso correspondiente
  digitalWrite(pinTrig, LOW); //colocamos en bajo el pin "trig"

  duracion = pulseIn(pinEcho, HIGH); //realizamos la medicion del tiempo (en microsegundos) que se encuentra en alto el pin "Echo"
  distancia = duracion/58.2;
  return(distancia); //devolvemos la distancia calculada en cm

}

//FUNCION SEGUIDOR DE LINEA
void modoSeguidorLinea(){
    if(digitalRead(pinIR_Centro) == 1){        //pregunto si el sensor del centro detectó línea oscura
      Serial.println("CENTRO");
      AVANZAR();                                  //si está centrado en la línea, el robot debe avanzar   
    }else if(digitalRead(pinIR_Izquierda) == 1){   //Cuando el sensor del centro no detecte línea pero el de la izquierda sí
      Serial.println("IZQUIERDA");
      GIRAR_IZQ();
    }else if(digitalRead(pinIR_Derecha) == 1){     //Cuando ni el sensor del centro ni el de la izquierda estén detectando línea pero el de la derecha sí
    Serial.println("DERECHA");
      GIRAR_DER();
   }else {  
      Serial.println("STOP");                                      //cuando ninguno de los sensores detecte línea
      STOP();
  }
}


void setup() {
//CONFIGURO PINES
//pines de motores
  pinMode(ENA_IZQ, OUTPUT);
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(ENB_DER,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);

//pines de ultrasonico
  pinMode(pinTrig, OUTPUT);
  pinMode(pinEcho,INPUT);

//pines de infrarrojo seguidor de linea
  pinMode(pinIR_Centro,INPUT);
  pinMode(pinIR_Izquierda,INPUT);
  pinMode(pinIR_Derecha,INPUT);

  Serial.begin(9600);
}

void loop() {
  DistanciaObstaculo = medirDistancia();
  if(DistanciaObstaculo >20){
    modoSeguidorLinea();
  }

  else {
    STOP();
    Serial.println(DistanciaObstaculo);
  }
}