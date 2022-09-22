#include <Arduino.h> //Permite utilizar los comandos de Arduino
//#include <SoftwareSerial.h>//Libreria para nuevo puerto serial para el bluetooth
#include "Sensor_ultrasonico_HCSR04.h"

class Sensor
{
  private:
  int Pin_sensor;

  public:
  Sensor(int pin): Pin_sensor(pin){}//Constructor
  void Inicializar(); 
  int Leer_sensor();
};
class Motor
{
  private:
  int A;
  int B;
  int Pwm;
 
  public:
  Motor(int a,int b,int pwm): A(a), B(b),Pwm(pwm){}//Constructor
  void Inicializar_Motor();
  void Adelante(int Velocidad);
  void Atras(int Velocidad);
  void Stop();
};

class Robot
{  
  private:
  char Estado;
  Motor Motor_1;
  Motor Motor_2;
  SoftwareSerial Bluetooth; // RX, TX
  Sensor_ultrasonico_HCSR04 sonar;
  
  public:
  Sensor Sensor_1;
  Sensor Sensor_2;
  Robot(int Pin_Motor_1A,int Pin_Motor_1B,int PWM_1, int Pin_Motor_1C, int Pin_Motor_1D,int PWM_2,int PinS1,int PinS2, int TX, int RX,int Trig, int Echo): Motor_1(Pin_Motor_1A,Pin_Motor_1B,PWM_1), Motor_2(Pin_Motor_1C,Pin_Motor_1D,PWM_2),Sensor_1(PinS1),Sensor_2(PinS2),Bluetooth(TX,RX),sonar(Echo,Trig){}
  void Inicializar_Robot();
  void Adelante(int Velocidad_1,int Velocidad_2);
  void Atras(int Velocidad_1,int Velocidad_2);
  void Stop();
  void Modo_Bluetooth();
  char Leer_BT();
  void Modo_Evasor(int Dis_giro);
  void Modo_Seguidor();
};
