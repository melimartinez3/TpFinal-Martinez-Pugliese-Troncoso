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

	time_t rawtime;
	struct tm timeinfo;
	time(&rawtime);
	localtime_s(&timeinfo, &rawtime);

	int dia_hoy = timeinfo.tm_mday;
	int mes_hoy = timeinfo.tm_mon;
	int anio_hoy = timeinfo.tm_year - 100;
	
	if (chequeo)
		return false;//no se puedo despachar el producto porque esta fallado
	else
	{
		musimundo->VendidosenelDia(dia_hoy, mes_hoy, anio_hoy, electrodomestico);
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