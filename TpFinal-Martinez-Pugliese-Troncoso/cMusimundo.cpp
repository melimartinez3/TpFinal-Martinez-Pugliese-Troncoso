#include "cMusimundo.h"

cMusimundo::cMusimundo() :stockminimo(5)
{
	this->totalrecaudado = 0;
	lista_electrodomesticos = new cLista<cElectrodomesticos>(50);
}
cLista<cElectrodomesticos>* cMusimundo::VendidosenelDia() {
	cLista<cElectrodomesticos>* aux = NULL;
	return aux;
}

cLista<cElectrodomesticos>* cMusimundo::VerificarStockMinimo() {
	cLista<cElectrodomesticos>* aux = NULL;
	return aux;
}
void cMusimundo::CompletarStock(cLista<cElectrodomesticos>* listaux) {
	cLista<cElectrodomesticos>* aux = NULL;

}
bool cMusimundo::VerificarCostoListaCompleta() {
	return true;
}
void cMusimundo::AgregarListaAlStock() {

}

cMusimundo::~cMusimundo()
{
	if (lista_electrodomesticos != NULL)
	{
		delete lista_electrodomesticos;
	}
}
