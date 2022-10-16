#include <LiquidCrystal.h>
 LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

float sensorValue1 = 0;
float sensorValue2 = 0;
float voltageValue = 0;
float currentValue = 0;
float Power_now = 0;                                     
void setup() 
{
  lcd.begin(16, 2);
}

void loop() 
{
  sensorValue1 = analogRead(A0);
  sensorValue2 = analogRead(A1);
  voltageValue= (sensorValue1 * 5.0 /1023.0) *5;
  currentValue= (sensorValue2 * 5.0 /1023.0);
  lcd.setCursor(0, 0);
  Power_now = voltageValue * currentValue;
  
  lcd.print("Ppv=");
  lcd.print(Power_now);
  lcd.print("W");  
  lcd.setCursor(0, 1);
  lcd.print("V=");
  lcd.print(voltageValue);
  lcd.print("V I=");
  lcd.print(currentValue);
  lcd.print("A");
}
