#include "cMusimundo.h"

cMusimundo::cMusimundo() :stockminimo(5)
{
	this->totalrecaudado = 0;
	lista_electrodomesticos = new cLista<cElectrodomesticos>(50);
}
int cMusimundo::vendidos_dia = 0;

cLista<cElectrodomesticos>* cMusimundo::VendidosenelDia(int dia, int mes, int anio) {
	
	time_t rawtime;
	struct tm timeinfo;
	time(&rawtime);
	localtime_s(&timeinfo, &rawtime);

	int dia_hoy = timeinfo.tm_mday;
	int mes_hoy = timeinfo.tm_mon;
	int anio_hoy = timeinfo.tm_year - 100;

	if (dia_hoy == dia && mes_hoy == mes && anio == anio_hoy) {
		vendidos_dia++;// es el dia de hoy, le sumamos uno
	}
	else //PREGUNTAR SI LOS STATICS VAN CON SETTERS O SEPUEDEN HACER ASI
	{ //comenzo un nuevo dia
		vendidos_dia = 0; //las ventas vuelven a 0
		vendidos_dia++;//le sumamos uno
	}
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
