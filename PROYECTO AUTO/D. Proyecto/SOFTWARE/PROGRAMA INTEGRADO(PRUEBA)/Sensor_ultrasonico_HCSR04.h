class Sensor_ultrasonico_HCSR04
{
private:
	int Echo;
	int Trig;
	long lduration;
	long ldistance;
public:
	Sensor_ultrasonico_HCSR04(int echo,int trig): Echo(echo),Trig(trig){lduration=0;ldistance=0;};//Contructor
	void Inicializar_ultrasonico();
	float Obtener_Distancia();
};
