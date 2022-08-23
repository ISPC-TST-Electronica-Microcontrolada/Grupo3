// Pedir un valor entre 0 y 255, para controlar el brillo de un diodo led.

int led=5;
int i;

void setup() {
  Serial.begin(9600);
  pinmode(led, output)
}

void loop() {
  serial.println ("Bienvenido/a, por favor ingrese un valor entre 0 y 255:");
  while(!serial.available()>0);
  i=serial.parseint();
  serial.print("El valor ingresado es:");
  serial.println(i);
  if((i>=0)and(i<=255)){
    analogwrite(led,i9,
    delay(1000));
  }
}

