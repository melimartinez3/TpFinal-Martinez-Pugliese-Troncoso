#include "cHeladera.h"

cHeladera::cHeladera(int _temperatura, string _marca, float _peso, float _precio, string _codigo, string _tipo, float _ancho, float _alto, float _profundidad) :cElectrodomesticos(_marca, _peso, _precio, _codigo, _tipo, _ancho, _alto, _profundidad)
{
	this->temperatura = _temperatura;
	this->horaenchufado = 0;
}

int cHeladera::stockactual = 6;

void cHeladera::EnchufarHeladera()
{
	time_t hora_t;
	hora_t = time(NULL);
	(void)ctime(&hora_t);

	this->set_horaenchufado(hora_t);
}

bool cHeladera::FuncionamientoInorrecto()
{
	int random_error = (rand() % 20) < 4;
	int random_caracteristiafallada = rand() % 5;// segun su valor en el enum es la caracteristca fallada
	EnchufarHeladera();
	
	time_t hora_t;
	hora_t = time(NULL);
	(void)ctime(&hora_t);
	
	try {
		if (difftime(this->horaenchufado, hora_t) < 600)//la  diferencia entre la hora de enchufado y actual es menor a 10 minutos-> 10*60=600
			throw;
	}
	catch (int& e) {
		cerr << "No han pasado los 10 minutos necesarios de testeo"<<e <<endl;
		return false;
	}

	switch (random_caracteristiafallada) {
	case luzinterior: { fallas[luzinterior] = true;
			break; }
	case termostato: { fallas[termostato] = true;
		break;
	}
	case obstruccionhielo: {fallas[obstruccionhielo] = true;
		break;
	}
	case sellomagnetico: {fallas[sellomagnetico] = true;
		break;
	}
	case saltodevoltaje: {fallas[saltodevoltaje] = true;
		break;
	}
	case perdidarefrigerante: {fallas[perdidarefrigerante] = true;
		break; }
	}
	
	for (int i = 0; i < 7; i++) {
		if (fallas[i] == true) {
			return true;
		}
	}
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