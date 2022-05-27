#pragma once
#include "cElectrodomesticos.h"

using namespace std;

class cDespachante
{
private:
	string cod_operacion;

public:
	bool TestearHeladera(cHeladera* heladera);
	bool TestearTelevisor(cTelevisor* televisor);
	bool TestearMicroondas(cMicroondas* microondas);
	void DespacharProducto(cElectrodomesticos* electrodomestico);

};

