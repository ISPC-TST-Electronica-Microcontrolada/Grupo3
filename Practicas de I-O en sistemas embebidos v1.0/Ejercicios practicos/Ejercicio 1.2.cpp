// Preguntar Nombre, Apellido, Direccion y Celular en mensajes diferentes. Completar las respuestas.

string nombre;
string apellido;
string direccion;
string celular;

void setup() {
  serial.begin (9600);
}

void loop() {
  serial.println ("Bienvenido/a, por favor ingrese su nombre:");
  while (!serial.available()>0);
  nombre=serial.readstringuntil(´\n´);

  serial.println ("Por favor ingrese su apellido:");
  while (!serial.available()>0);
  apellido=serial.readstringuntil(´\n´);

  serial.println ("Por favor ingrese su direccion:");
  while (!serial.available()>0);
  direccion=serial.readstringuntil(´\n´);

  serial.println ("Por favor ingrese su celular:");
  while (!serial.available()>0);
  celular=serial.readstringuntil(´\n´);

  serial.println ("Sus datos son los siguiente:");
  serial.println ("Nombre:" +nombre);
  serial.println ("Apellido:" +apellido);
  serial.println ("Direccion:" +direccion);
  serial.println ("Celular:" +celular);
  
}


