#include "cMicroondas.h"
cMicroondas::cMicroondas(int _potencia, string _marca, float _peso, float _precio, string _codigo, string _tipo, float _ancho, float _alto, float _profundidad):cElectrodomesticos(_marca, _peso, _precio, _codigo, _tipo, _ancho, _alto, _profundidad)
{
	this->potencia = _potencia;
	this->horaencendidio = 0;
	this->luz = true;
	this->modocalentamiento = true;
}

int cMicroondas::stockactual = 6;

bool cMicroondas::FuncionamientoCorrecto()
{

}

cMicroondas::~cMicroondas()
{

}
