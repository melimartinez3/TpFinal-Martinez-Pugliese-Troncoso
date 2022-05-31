#include "cDespachante.h"

cDespachante::cDespachante(string _cod_operacion)
{
	this->cod_operacion = _cod_operacion;
}
bool cDespachante::TestearHeladera(cHeladera* heladera) {
	return true;
}
bool cDespachante::TestearTelevisor(cTelevisor* televisor) {
	return true;
}
bool cDespachante::TestearMicroondas(cMicroondas* microondas) {
	return false;
}
void cDespachante::DespacharProducto(cElectrodomesticos* electrodomestico) {
	
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