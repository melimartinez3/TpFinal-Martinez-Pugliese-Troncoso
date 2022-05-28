#pragma once
#include "cMicroondas.h"
#include  "cTelevisor.h"
#include "cHeladera.h"

class cMusimundo
{
private:
	float totalrecaudado;
	const int stockminimo;
	cLista<cElectrodomesticos>* lista_electrodomesticos;

public:
	cMusimundo(float _totalrecaudado, cLista<cElectrodomesticos>* _lista_electrodomesticos);
	//declarar const
	cLista<cElectrodomesticos>* VendidosenelDia();
	int TotalRecaudadoenelDia();
	cLista<cElectrodomesticos>* VerificarStockMinimo(cElectrodomesticos* electrodomesticos);// devolvemos en una lista todos los electrodomesticos que tienen un stock menor a 5
	cLista<cElectrodomesticos>* CompletarStock();// llamamos a la funcion de verificar el stock minimo y a los elementos que tengan uno menor a 5 las completamos
	bool VerificarCostoListaCompleta();// devuelve true si vale mas de 20000
	void AgregarListaAlStock();// si es verdadera la anterior se agrega la lista auxiliar al stock total
	~cMusimundo();

	float get_totalrecaudado() {
		return this->totalrecaudado;
	}
	int get_stockminimo() {
		return this->stockminimo;
	}
};

