#include <Arduino.h> //Permite utilizar los comandos de Arduino
#include "Sensor_ultrasonico_HCSR04.h"

void Sensor_ultrasonico_HCSR04::Inicializar_ultrasonico()
{
	pinMode(Trig, OUTPUT);
	pinMode(Echo, INPUT); 
}
float Sensor_ultrasonico_HCSR04::Obtener_Distancia()
{
	////////////////////////////////////////////////////////////////
      //    Mide la distancia a la que se encuentra el obstaculo    //
      ////////////////////////////////////////////////////////////////
      
      digitalWrite(Trig, LOW);               
      delayMicroseconds(2); 
      digitalWrite(Trig, HIGH);
      delayMicroseconds(10);
      digitalWrite(Trig, LOW);
      lduration = pulseIn(Echo, HIGH);
      ldistance =  (lduration/2) / 29.1;
      return ldistance;
}