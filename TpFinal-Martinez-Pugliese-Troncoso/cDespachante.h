#pragma once
#include "cMusimundo.h";
#include "cVendedor.h"

using namespace std;

class cDespachante:
	public cEmpleado
{
private:
	string cod_operacion;
	
public:
	cDespachante(string _cod_operacion, string nombre, string _dni, string fechanac, string cod, float _sueldo, char _turno);
	bool TestearElectrodomestrico(cElectrodomesticos* electrodomestico);
	bool DespacharProducto(cElectrodomesticos* electrodomestico, cMusimundo* musimundo);
	string to_string();
	void imprimir();
	~cDespachante();

	string get_cos_operacion() {
		return this->cod_operacion;
	}

};

