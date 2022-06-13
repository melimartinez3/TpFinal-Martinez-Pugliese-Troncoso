#include "cDespachante.h"

cDespachante::cDespachante(string _cod_operacion)
{
	this->cod_operacion = _cod_operacion;
}
bool cDespachante::TestearElectrodomestrico(cElectrodomesticos* electrodomestico) {
	bool control = electrodomestico->FuncionamientoIncorrecto();
	if (control)
		return true;//funciona mal :((
	else return false;//funciona bien :))
}



 bool cDespachante::DespacharProducto(cElectrodomesticos* electrodomestico,cMusimundo*musimundo) {
	bool chequeo = TestearElectrodomestrico(electrodomestico);
	
	if (chequeo)
		return false;//no se puedo despachar el producto porque esta fallado
	else
	{
		musimundo->lista_electrodomesticos->operator-(electrodomestico);
		return true;//el producto funciona bien y se eliminó de la lista porque se despachó
	}
}

string cDespachante::to_string() {
	string dato;
	dato = "\nDespachante: Codigo Operacion " + cod_operacion;
	return dato;
}
void cDespachante::imprimir() {
	string dato = to_string();
	cout << dato;
}
cDespachante::~cDespachante()
{
	

}