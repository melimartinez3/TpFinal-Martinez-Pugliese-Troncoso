#include "cMusimundo.h"

cMusimundo::cMusimundo(float _totalrecaudado, cLista<cElectrodomesticos>* _lista_electrodomesticos):stockminimo(5)
{
	this->totalrecaudado = _totalrecaudado;
	lista_electrodomesticos = _lista_electrodomesticos;
}

cMusimundo::~cMusimundo()
{
	if (lista_electrodomesticos != NULL)
	{
		delete lista_electrodomesticos;
	}
}
