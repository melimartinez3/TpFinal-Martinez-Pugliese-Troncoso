#include "cVendedor.h"

cVendedor::cVendedor():cEmpleado()
{
	this->vendidos = 0;
	this->comision = 0;
	listaelectro = NULL;
}

void cVendedor::CalcularComision()
{
	float acum = 0;
	for (int i = 0; i < listaelectro->get_cant_actual(); i++) {
		acum += listaelectro->lista[i]->get_precio();
	}
	comision = (0.1 * acum); // le sumamos al sueldo el 10% de sus ventas
	set_sueldo(comision);
}

void cVendedor::AgregarElectrodomesticoVendido(cElectrodomesticos* electrodomestico)
{
	listaelectro->operator+(electrodomestico);
}

void cVendedor::EliminarYCrearNuevaLista()
{
	if (listaelectro != NULL) {
		for (int i = 0; i < listaelectro->cantactual; i++) {
			if (listaelectro->lista[i] != NULL) {
				delete listaelectro->lista[i];
			}
		}
		delete[] listaelectro;
	}
	listaelectro = new cLista<cElectrodomesticos>(TMAX);

}

//cLista<cElectrodomesticos>* BuscarProducto(string detalle, cMusimundo* musimundo) {
//	int n = musimundo->get_lista_electrodomesticos()->get_cant_actual();
//	cLista<cElectrodomesticos>* aux = musimundo->get_lista_electrodomesticos();
//	for (int i = 0; i < n; i++) {
//		if(detalle == aux->)
//	}
//}

cVendedor::~cVendedor()
{
	if (listaelectro != NULL) {
		delete listaelectro;
	}
}
