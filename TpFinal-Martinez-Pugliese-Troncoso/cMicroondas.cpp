#include "cMicroondas.h"
cMicroondas::cMicroondas(int _potencia, string _marca, float _peso, float _precio, string _codigo, string _tipo, float _ancho, float _alto, float _profundidad):cElectrodomesticos(_marca, _peso, _precio, _codigo, _tipo, _ancho, _alto, _profundidad)
{
	this->potencia = _potencia;
	this->horaencendidio = 0;
	this->luz = true;
	this->modocalentamiento = true;
}

int cMicroondas::stockactual = 6;

void cMicroondas::AbrirPuerta() {

}

void cMicroondas::PotenciaMaxima() {
	
}

void cMicroondas::ChequeoEncendidoPor1Min() {

}


bool cMicroondas::FuncionamientoInorrecto()
{
	return true;
}
string cMicroondas::to_string() {

	string precio_string,dato, potencia_string;
	stringstream sstream;

	sstream << precio_string;
	precio_string = sstream.str();

	sstream << potencia_string;
	potencia_string = sstream.str();

	dato = "\nMicroondas: Marca: " + marca + " Precio: " + precio_string + " Codigo: " + codigo + " Tipo: " + tipo + " Potencia: " + potencia_string;
	return dato;
}
void cMicroondas::imprimir() {
	string dato = to_string();
	cout << dato;
}
cMicroondas::~cMicroondas()
{

}
