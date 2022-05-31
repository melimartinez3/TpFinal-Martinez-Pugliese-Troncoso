#pragma once
#include "cMicroondas.h"
#include"cTelevisor.h"
#include"cHeladera.h"

using namespace std;

class cDespachante
{
private:
	string cod_operacion;

public:
	cDespachante(string _cod_operacion);
	bool TestearHeladera(cHeladera* heladera);
	bool TestearTelevisor(cTelevisor* televisor);
	bool TestearMicroondas(cMicroondas* microondas);
	void DespacharProducto(cElectrodomesticos* electrodomestico);
	string to_string();
	void imprimir();
	~cDespachante();

	string get_cos_operacion() {
		return this->cod_operacion;
	}

};

