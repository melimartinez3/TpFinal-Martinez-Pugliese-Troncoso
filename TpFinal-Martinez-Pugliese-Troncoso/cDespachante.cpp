#include "cDespachante.h"
#include "cMusimundo.h"


bool cDespachante::TestearElectrodomestrico(cElectrodomesticos* electrodomestico) {
	bool control = electrodomestico->FuncionamientoIncorrecto();
	if (control)
		return true;//funciona mal :((
	else return false;//funciona bien :))
}


 bool cDespachante::DespacharProducto(string codigo,cMusimundo*musimundo) {

	 cElectrodomesticos* electrodomestico = musimundo->BuscarPorCodigo(codigo);

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
		musimundo->lista_electrodomesticos->operator-(electrodomestico);
		return true;//el producto funciona bien y se eliminó de la lista porque se despachó
	}
}


cDespachante::~cDespachante()
{
	
}