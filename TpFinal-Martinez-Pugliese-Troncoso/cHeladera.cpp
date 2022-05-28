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
	ctime(&hora_t);

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
	ctime(&hora_t);

	if (difftime(this->horaenchufado, hora_t) < (10 * 60) && this->chequeoluzinterior == true && this->chequeotemperatura == true)
		return true;

	else 
		return false;

}


cHeladera::~cHeladera()
{

}