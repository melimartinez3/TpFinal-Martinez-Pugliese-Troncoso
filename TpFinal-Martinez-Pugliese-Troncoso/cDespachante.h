#pragma once
#include "cEmpleado.h"
class cMusimundo;


using namespace std;

class cDespachante :
	public cEmpleado
{

public:

	cDespachante(string nombre_, string dni_, float sueldo_, char turno_);
	bool TestearElectrodomestrico(cElectrodomesticos* electrodomestico);
	bool DespacharProducto(string codigo, cMusimundo* musimundo);
	~cDespachante();

};

