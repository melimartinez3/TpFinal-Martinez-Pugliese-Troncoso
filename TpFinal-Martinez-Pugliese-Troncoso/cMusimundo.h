#pragma once
#include "cMicroondas.h"
#include  "cTelevisor.h"
#include "cHeladera.h"

class cVendedor;
class cDespachante;


#define TMAX 50

class cMusimundo
{
private:
	static int vendidos_dia;
	static float totalrecaudado;
	const int stockminimo;
	cLista<cElectrodomesticos>* lista_electrodomesticos;
	cLista<cElectrodomesticos>* lista_vendidos;

public:
	friend class cDespachante;
	friend class cElectrodomesticos;
	cMusimundo();


	void VendidosenelDia(int dia, int mes, int anio, cElectrodomesticos* vendido, cVendedor* vendedor);
	cLista<cElectrodomesticos>* VerificarStockMinimo();// devolvemos en una lista todos los electrodomesticos que tienen un stock menor a 5
	cLista<cElectrodomesticos>* CompletarStock();// llamamos a la funcion de verificar el stock minimo y a los elementos que tengan uno menor a 5 las completamos
	cLista<cElectrodomesticos>* VerificarCostoListaCompleta();// devuelve true si vale mas de 20000
	void AgregarListaAlStock();// si es verdadera la anterior se agrega la lista auxiliar al stock total
	string tostring();
	void imprimir();
	void Dia_De_Descuentos();
	void Termino_Dia_De_Descuentos();
	void Determinar_Descuento();
	void Con_o_Sin_Descuento();
	friend cElectrodomesticos& operator++(cElectrodomesticos& electro);
	friend cElectrodomesticos& operator--(cElectrodomesticos& electro);
	void AgregarHeladeras(cLista<cElectrodomesticos>* aux, int cantidad);
	void AgregarMicroondas(cLista<cElectrodomesticos>* aux, int cantidad);
	void AgregarTelevisores(cLista<cElectrodomesticos>* aux, int cantidad);

	cElectrodomesticos* ProductoAVender(cElectrodomesticos* electrodomestico);
	~cMusimundo();

	void set_totalrecaudado(float nuevorecaudo) {
		this->totalrecaudado = this->totalrecaudado + nuevorecaudo;
	}

	float get_totalrecaudado() {
		return this->totalrecaudado;
	}
	int get_stockminimo() {
		return this->stockminimo;
	}
};

