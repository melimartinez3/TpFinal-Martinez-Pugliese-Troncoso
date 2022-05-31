#include "cHeladera.h"

cHeladera::cHeladera(int _temperatura, string _marca, float _peso, float _precio, string _codigo, string _tipo, float _ancho, float _alto, float _profundidad) :cElectrodomesticos(_marca, _peso, _precio, _codigo, _tipo, _ancho, _alto, _profundidad)
{
	this->temperatura = _temperatura;
	this->horaenchufado = 0;
	this->chequeoluzinterior = true;
	this->chequeotemperatura = true;
}

int cHeladera::stockactual = 6;

void cHeladera::EnchufarHeladera()
{
	int random_luz = rand() % 1; //si sale 0 funciona, si sale 1 no funciona
	int random_temperatura = (rand() % 20) < 4;

	time_t hora_t;
	hora_t = time(NULL);
	(void)ctime(&hora_t);

	this->set_horaenchufado(hora_t);

	if (random_luz == 0)
		this->set_chequeoluzinterior(true);
	else
		this->set_chequeoluzinterior(false);

	if (random_temperatura < 4)
		this->set_chequeotemperatura(false);
	else
		this->set_chequeotemperatura(true);
}

bool cHeladera::FuncionamientoCorrecto()
{
	time_t hora_t;
	hora_t = time(NULL);
	(void)ctime(&hora_t);

	if (difftime(this->horaenchufado, hora_t) < 600 && this->chequeoluzinterior == true && this->chequeotemperatura == true) //la  diferencia entre la hora de enchufado y actual debe ser menor a 10 minutos-> 10*60=600
		return true;

	else 
		return false;

}

string cHeladera::to_string() {

	string precio_string, dato,temp_string;
	stringstream sstream;

	sstream << precio_string;
	precio_string = sstream.str();

	sstream << temp_string;
	temp_string = sstream.str();

	dato = "\nHeladera: Marca: " + marca + " Precio: " + precio_string + " Codigo: " + codigo + " Tipo: " + tipo + " Temperatura: " + temp_string;
	return dato;
}
void cHeladera::imprimir() {
	string dato = to_string();
	cout << dato;
}

cHeladera::~cHeladera()
{

}