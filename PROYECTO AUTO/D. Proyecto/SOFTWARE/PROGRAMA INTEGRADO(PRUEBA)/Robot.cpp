#include "Robot.h"
#include <Arduino.h> //Permite utilizar los comandos de Arduino
#include <SoftwareSerial.h>
void Sensor::Inicializar()
{
  pinMode(Pin_sensor, OUTPUT);
}
int Sensor::Leer_sensor()
{
  int Estado;
  Estado=digitalRead(Pin_sensor);
  return Estado;
}
void Motor::Inicializar_Motor()
{
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(Pwm, OUTPUT);
}
void Motor::Atras(int Velocidad)
{
  analogWrite(Pwm,Velocidad );
  digitalWrite(A, HIGH);
  digitalWrite(B, LOW);
}
void Motor::Adelante(int Velocidad)
{
  analogWrite(Pwm,Velocidad );
  digitalWrite(A, LOW);
  digitalWrite(B, HIGH);
}
void Motor::Stop()
{
  analogWrite(0, Pwm);
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
}

char Robot::Leer_BT()
{
  if (Bluetooth.available() > 0)
      {
        Estado = Bluetooth.read();
      }
  return Estado;
}
void Robot::Inicializar_Robot()
{
  Motor_1.Inicializar_Motor();
  Motor_2.Inicializar_Motor();
  sonar.Inicializar_ultrasonico();
  Bluetooth.begin(9600);//Iniciar la comunicacion a 9600
}

void Robot::Atras(int Velocidad_1,int Velocidad_2)
{
  Motor_1.Atras(Velocidad_1);
  Motor_2.Atras(Velocidad_2);
}
void Robot::Adelante(int Velocidad_1,int Velocidad_2)
{
  Motor_1.Adelante(Velocidad_1);
  Motor_2.Adelante(Velocidad_2);
}
void Robot::Stop()
{
  Motor_1.Stop();
  Motor_2.Stop();
}

void Robot::Modo_Bluetooth()
{
  int Estado;
  int Velocidad_Max=255;
  int Velocidad_Med=180;
  Estado=Leer_BT();
  if (Estado == '1')
      {
        //Arriba_Izquierda
        Adelante(Velocidad_Med,Velocidad_Max);
      }
      if (Estado == '2')
      {
        //Derecho
        Adelante(Velocidad_Max,Velocidad_Max);
      }
      if (Estado == '3')
      {
        //Arriba_Derecha
        Adelante(Velocidad_Max,Velocidad_Med);
      }
      if (Estado == '4')
      {
        //Girar a la izquierda
        Motor_2.Adelante(Velocidad_Max);
        Motor_1.Atras(Velocidad_Max);
      }
      if (Estado == '5')
      {
        
      }
      if (Estado == '6')
      {
        //Girar a la derecha
        Motor_2.Atras(Velocidad_Max);
        Motor_1.Adelante(Velocidad_Max);
      }
      if (Estado == '7')
      {
        //Abajo Izquierda
        Atras(Velocidad_Med,Velocidad_Max); 
      }
      if (Estado == '8')
      {
        //Reversa
        Atras(Velocidad_Max,Velocidad_Max);
      }
      if (Estado == '9')
      {
        //Abajo Derecha
        Atras(Velocidad_Max,Velocidad_Med);
      }
      if (Estado == 'w')
      {
        Stop();
      }
}

void Robot::Modo_Evasor(int Dis_giro)
{
  int Distancia;
   Distancia = sonar.Obtener_Distancia();
   if (Distancia <= Dis_giro)
      {
        //Girar a la derecha
        Motor_1.Atras(255);
        Motor_2.Adelante(255);
        delay(500);
      }
      else
      {
        Adelante(255,255);
      }
}
void Robot::Modo_Seguidor()
{
      int val_sensor_Derecha=Sensor_1.Leer_sensor();
      int val_sensor_Izquierda=Sensor_2.Leer_sensor();
      
      if (val_sensor_Derecha == 0 && val_sensor_Izquierda == 0)
      {
        Adelante(255,255);
      }
      else if (val_sensor_Derecha == 0 && val_sensor_Izquierda == 1)
      {
        Adelante(255,0);
      }
      else if (val_sensor_Derecha == 1 && val_sensor_Izquierda == 0)
      {
        Adelante(0,255);
      }
}
