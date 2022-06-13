#pragma once
#include "cMusimundo.h";

using namespace std;

class cDespachante
{
private:
	string cod_operacion;
	
public:
	cDespachante(string _cod_operacion);
	bool TestearElectrodomestrico(cElectrodomesticos* electrodomestico);
	bool DespacharProducto(cElectrodomesticos* electrodomestico, cMusimundo* musimundo);
	string to_string();
	void imprimir();
	~cDespachante();

	string get_cos_operacion() {
		return this->cod_operacion;
	}

};

