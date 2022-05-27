#pragma once
#include "cElectrodomesticos.h"

class cMusimundo
{
private:
	float totalrecaudado;
	const int stockminimo;
	cLista<cElectrodomesticos>* electrodomesticos;

public:
	cLista<cElectrodomesticos>* VendidosenelDia();
	int TotalRecaudadoenelDia();
	void VerificarStockMinimo(cElectrodomesticos* electrodomesticos);
	void CompletarStock(cElectrodomesticos* electrodomesticos);
};

