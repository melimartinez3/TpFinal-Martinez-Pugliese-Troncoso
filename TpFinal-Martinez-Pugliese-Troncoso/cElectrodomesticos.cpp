#include "cElectrodomesticos.h"
#include "cMusimundo.h"

cElectrodomesticos::cElectrodomesticos(string _marca, float _peso, float _precio, string _codigo, string _tipo, float _ancho, float _alto, float _profundidad):marca(_marca),codigo(_codigo),tipo(_tipo),voltaje(220)
{
	this->peso = _peso;
	this->precio = _precio;
	dimensiones = new cDimensiones(_ancho, _alto, _profundidad);

}

int cElectrodomesticos::vendidos = 0;

cElectrodomesticos* cElectrodomesticos::BuscarPorCodigo(string _codigo, cMusimundo*musimundo) {
	cElectrodomesticos* aux = NULL;
	int n = musimundo->lista_electrodomesticos->get_cant_actual();
	for (int i = 0; i < n; i++) {
		if (musimundo->lista_electrodomesticos->lista[i]->get_codigo() == _codigo) {
			aux = musimundo->lista_electrodomesticos->lista[i];
		}
	}
	return aux;
	
}

cLista<cElectrodomesticos>* cElectrodomesticos::BuscarPorMarca(string _marca, cMusimundo* musimundo) {

	int n = musimundo->lista_electrodomesticos->get_cant_actual();
	cLista<cElectrodomesticos>* aux = new cLista<cElectrodomesticos>(n);
	
	for (int i = 0; i < n; i++) {

		if (musimundo->lista_electrodomesticos->lista[i]->get_marca() == _marca) {

			aux->operator+(musimundo->lista_electrodomesticos->lista[i]);
		}
	}

	return aux;

}

cLista<cElectrodomesticos>* cElectrodomesticos::BuscarporTipoyNombre(string _tipo, string _nombre, cMusimundo* musimundo) {
	
	int n = musimundo->lista_electrodomesticos->get_cant_actual();

	cLista<cElectrodomesticos>* aux = new cLista<cElectrodomesticos>(n);

	for (int i = 0; i < n; i++) {

		if (musimundo->lista_electrodomesticos->lista[i]->get_tipo() == _tipo) {

			aux->operator+(musimundo->lista_electrodomesticos->lista[i]);
		}
	}

	return aux;
}

void cElectrodomesticos::RemitirProducto(cDespachante* despachante, cMusimundo* musimundo) {

	bool chequeo=despachante->DespacharProducto(this,musimundo);
	if (chequeo)
	{
		time_t rawtime;
		struct tm timeinfo;
		time(&rawtime);
		localtime_s(&timeinfo, &rawtime);

		int dia_hoy = timeinfo.tm_mday;
		int mes_hoy = timeinfo.tm_mon;
		int anio_hoy = timeinfo.tm_year - 100;

		musimundo->VendidosenelDia(dia_hoy, mes_hoy, anio_hoy,this);
	}
}

cElectrodomesticos::~cElectrodomesticos()
{
	if (dimensiones != NULL)
	{
		delete dimensiones;
	}

}