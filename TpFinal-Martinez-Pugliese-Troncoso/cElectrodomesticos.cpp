#include "cElectrodomesticos.h"

cElectrodomesticos::cElectrodomesticos(string _marca, float _peso, float _precio, string _codigo, string _tipo, float _ancho, float _alto, float _profundidad):marca(_marca),codigo(_codigo),tipo(_tipo)
{
	this->peso = _peso;
	this->precio = _precio;
	dimensiones = new cDimensiones(_ancho, _alto, _profundidad);

}

int cElectrodomesticos::vendidos = 0;

cElectrodomesticos::~cElectrodomesticos()
{
	if (dimensiones != NULL)
	{
		delete dimensiones;
	}

}