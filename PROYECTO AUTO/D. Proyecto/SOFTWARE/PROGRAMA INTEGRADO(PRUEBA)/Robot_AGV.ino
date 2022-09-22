/*
 * Para inicializar el Robot se necesita definir los pines de la siguiente manera
 * Robot Nombre_Robot(In1,In2,Vss1-2,IN3,IN4,Vss3-4,S1,S2,TX_Bluetooth,RX_Bluettoth,Trig_Ultrasonico,Echo_Ultrasonico) 
 *                   (-------------------------------------Parametros:-----------------------------------------------)
 * 
 *     /////////////////Parametros///////////////
 *    /            Puente H                     /
 *    /    Parametro -> Numero de pin           /
 *    /    IN1       ->     2                   /
 *    /    In2       ->     7                   /   
 *    /    Vss1-2    ->     1                   /  
 *    /    In3       ->     10                  /   
 *    /    In4       ->     15                  /                                      
 *    /    Vss3-4    ->     9                   /           
 *    / ----------------------------------------/             
 *    /         Sensores opticos                /   
 *    /    Parametro -> Numero de pin           /                     
 *    /    S1        ->            DO           /       
 *    /    S2        ->            DO           /             
 *    / ----------------------------------------/     
 *    /         Modulo Bluetooth                /     
 *    /    Parametro -> Numero de pin           /       
 *    /    TX        ->    TX(3)                /       
 *    /    RX        ->    RX(2)                /       
 *    / ----------------------------------------/   
 *    /        Sensor Ultrasonico               /         
 *    /    Parametro -> Numero de pin           /     
 *    /    Trig      -> Trig(2)                 / 
 *    /    Echo      -> Echo(3)                 /       
 *    //////////////////////////////////////////
 */
#include "Robot.h"
 Robot Robot(13,12,11,10,8,9,4,5,2,3,6,7);

int Menu;
void setup() 
{
  Robot.Inicializar_Robot();
  Serial.begin(9600);
}

void loop() 
{
  char Estado;
  Estado=Robot.Leer_BT();
  if (Estado == 'a')
  {
    Menu=3;
  }
  if (Estado == 'b')
  {
    Menu=1;
  }
  if (Estado == 'c')
  {
    Menu=2;
  }
  
  switch(Menu)
  {
    case 1:
    Robot.Modo_Bluetooth();
    break;

    case 2:
    Robot.Modo_Evasor(25);//25cm=Distancia del obstaculo
    break;

    case 3:
    Robot.Modo_Seguidor();
    break;
  }
}
