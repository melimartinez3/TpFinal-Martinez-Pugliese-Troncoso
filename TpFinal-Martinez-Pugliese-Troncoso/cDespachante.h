#pragma once
#include "cEmpleado.h"
class cMusimundo;


using namespace std;

class cDespachante :
	public cEmpleado
{

public:

	cDespachante();
	bool TestearElectrodomestrico(cElectrodomesticos* electrodomestico);
	bool DespacharProducto(string codigo, cMusimundo* musimundo);
	~cDespachante();

};

