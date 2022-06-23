#include "cHeladera.h"

cHeladera::cHeladera(int _temperatura, string _marca, float _peso, float _precio, string _codigo, string _tipo, float _ancho, float _alto, float _profundidad) :cElectrodomesticos(_marca, _peso, _precio, _codigo, _tipo, _ancho, _alto, _profundidad)
{
	this->temperatura = _temperatura;
	this->horaenchufado = 0;
	stockactual++;
}

int cHeladera::stockactual = 6; //arancamos con 6 para probar el programa. En realidad debería estar en 0

cHeladera:: cHeladera(const cHeladera& heladera):cElectrodomesticos(heladera.marca, heladera.peso, heladera.precio, heladera.codigo, heladera.tipo, heladera.dimensiones->get_ancho(), heladera.dimensiones->get_alto(), heladera.dimensiones->get_profundidad())
{
	this->temperatura = heladera.temperatura;
	this->horaenchufado = heladera.horaenchufado;
}

void cHeladera::EnchufarHeladera()
{
	time_t hora_t;
	hora_t = time(NULL);
	(void)ctime(&hora_t);

	this->set_horaenchufado(hora_t);
}

bool cHeladera::FuncionamientoIncorrecto()
{
	int random_error = (rand() % 20) < 4;
	EnchufarHeladera();

	time_t hora_t;
	hora_t = time(NULL);
	(void)ctime(&hora_t);

	try {
		if (difftime(this->horaenchufado, hora_t) < 600)//la  diferencia entre la hora de enchufado y actual es menor a 10 minutos-> 10*60=600
			throw;
	}
	catch (int& e) {
		cerr << "No han pasado los 10 minutos necesarios de testeo" << e << endl;
		return false;
	}

	if (random_error < 4) {
		int random_caracteristiafallada = rand() % 5;// segun su valor en el enum es la caracteristca fallada

		switch (random_caracteristiafallada) {
		case luzinterior: { fallas[luzinterior] = true;
			return true; }
		case termostato: { fallas[termostato] = true;
			return true; }
		case obstruccionhielo: {fallas[obstruccionhielo] = true;
			return true; }
		case sellomagnetico: {fallas[sellomagnetico] = true;
			return true; }
		case saltodevoltaje: {fallas[saltodevoltaje] = true;
			return true; }
		case perdidarefrigerante: {fallas[perdidarefrigerante] = true;
			return true; }
		}

	}
	else
		return false;

}

string cHeladera::tostring()const {

	string dato,temp_string;
	temp_string = to_string(temperatura);


	dato = " Temperatura en grados centigrados: " + temp_string;
	return dato;
}

void cHeladera::imprimir()const {
	cElectrodomesticos::imprimir();
	string dato = tostring();
	cout << dato;
}

cHeladera::~cHeladera()
{

}