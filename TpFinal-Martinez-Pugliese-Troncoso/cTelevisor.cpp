#include "cTelevisor.h"

cTelevisor::cTelevisor(int _volumen, string _marca, float _peso, float _precio, string _codigo, string _tipo, float ancho, float dalto, float profundidad) :cElectrodomesticos(_marca, _peso, _precio, _codigo, _tipo, ancho, dalto, profundidad)
{
	this->volumen = _volumen;
	this->canal = 0;

}

int cTelevisor::stockactual = 6;

bool cTelevisor::Falla_EncenderTelevisor(){

	int random_error = (rand() % 10) < 1;
	if (random_error < 1)
		return true;
	else
		return false;

}

bool cTelevisor::FuncionamientoIncorrecto() {

	int random_caracteristiafallada = rand() % 6;// segun su valor en el enum es la caracteristca fallada

	if (Falla_EncenderTelevisor())
	{
		switch (random_caracteristiafallada) {

		case smart: { fallas[smart] = true;
			return true; }
		case sonido: { fallas[sonido] = true;
			return true; }
		case cable: {fallas[cable] = true;
			return true; }
		case control: {fallas[control] = true;
			return true; }
		case display: {fallas[display] = true;
			return true; }
		case cambiocanal: {fallas[cambiocanal] = true;
			return true; }
		case saltovoltaje: {
			fallas[saltovoltaje] = true;
			return true;
		}

		}
	}
	else return false;

}

string cTelevisor::to_string() {
	string dato;
	string volumen_string, stockactual_string, cablee, precio_string;
	if (cable == true)
		cablee = "Si";
	else
		cablee = "No";

	stringstream sstream;
	sstream << volumen;
	volumen_string = sstream.str();

	sstream << stockactual_string;
	stockactual_string = sstream.str();

	sstream << precio_string;
	precio_string = sstream.str();
	dato = "\nTelevisor: Marca: "+ marca+ " Precio: "+ precio_string+ " Codigo: "+ codigo+ " Tipo: "+ tipo+ " Volumen : " + volumen_string + " Stock actual : " + stockactual_string + " Clabe conectado : " + cablee;
	return dato;
}

void cTelevisor::imprimir() {
	string dato = to_string();
	cout << dato;
}

cTelevisor::~cTelevisor()
{

}
