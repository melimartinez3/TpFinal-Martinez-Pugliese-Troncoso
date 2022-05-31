#include "cTelevisor.h"

cTelevisor::cTelevisor(int _volumen, bool _veoprogramacion, string _marca, float _peso, float _precio, string _codigo, string _tipo, float ancho, float dalto, float profundidad) :cElectrodomesticos(_marca, _peso, _precio, _codigo, _tipo, ancho, dalto, profundidad)
{
	this->volumen = _volumen;
	this->veoprogramacion = _veoprogramacion;
	this->cable = true;
}

int cTelevisor::stockactual = 6;

bool cTelevisor::FuncionamientoCorrecto() {
	return true;
}
void cTelevisor::Encender() {

}
void cTelevisor::VerificarVolumen() {
	
}
void cTelevisor::ConectarCable() {

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
