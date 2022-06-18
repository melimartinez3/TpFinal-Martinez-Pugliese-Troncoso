#include "cMusimundo.h"

cMusimundo::cMusimundo() :stockminimo(5)
{
	this->totalrecaudado = 0;
	lista_electrodomesticos = new cLista<cElectrodomesticos>(TMAX);
	lista_vendidos = new cLista<cElectrodomesticos>(TMAX);
}
int cMusimundo::vendidos_dia = 0;

cElectrodomesticos* cMusimundo::ProductoAVender(cElectrodomesticos* electrodomestico)
{
	cElectrodomesticos* aux_elect = NULL;

	cHeladera* heladera = dynamic_cast<cHeladera*>(electrodomestico);
	cMicroondas* microondas = dynamic_cast<cMicroondas*>(electrodomestico);
	cTelevisor* televisor = dynamic_cast<cTelevisor*>(electrodomestico);

	if (heladera != NULL)
	{
		aux_elect = new cHeladera(*heladera);
		int n = heladera->get_stock();
		heladera->set_stock(n--);
	}

	if (microondas != NULL)
	{
		aux_elect = new cMicroondas(*microondas);
		int n = microondas->get_stock();
		microondas->set_stock(n--);

	}

	if (televisor != NULL)
	{
		aux_elect = new cTelevisor(*televisor);
		int n = televisor->get_stock();
		televisor->set_stock(n--);
	}

	return aux_elect;
}

void cMusimundo::VendidosenelDia(int dia, int mes, int anio, cElectrodomesticos* vendido) {
	
	time_t rawtime;
	struct tm timeinfo;
	time(&rawtime);
	localtime_s(&timeinfo, &rawtime);

	int dia_hoy = timeinfo.tm_mday;
	int mes_hoy = timeinfo.tm_mon;
	int anio_hoy = timeinfo.tm_year - 100;

	cElectrodomesticos* electrodomestico = ProductoAVender(vendido);

	if (dia_hoy == dia && mes_hoy == mes && anio == anio_hoy) {
		vendidos_dia++;// es el dia de hoy, le sumamos uno
		lista_vendidos->operator+(electrodomestico);
	}
	else //PREGUNTAR SI LOS STATICS VAN CON SETTERS O SEPUEDEN HACER ASI
	{ //comenzo un nuevo dia
		vendidos_dia = 0; //las ventas vuelven a 0
		vendidos_dia++;//le sumamos uno
		lista_vendidos = new cLista<cElectrodomesticos>(TMAX);
		lista_vendidos->operator+(electrodomestico);
	}
}

cLista<cElectrodomesticos>* cMusimundo::VerificarStockMinimo() {
	cLista<cElectrodomesticos>* aux = new cLista<cElectrodomesticos>(TMAX);
	int n = lista_electrodomesticos->get_cant_actual();

	for (int i = 0; i < n; i++)
	{
		cHeladera* heladera = dynamic_cast<cHeladera*>(lista_electrodomesticos->lista[i]);
		cMicroondas* microondas = dynamic_cast<cMicroondas*>(lista_electrodomesticos->lista[i]);
		cTelevisor* televisor = dynamic_cast<cTelevisor*>(lista_electrodomesticos->lista[i]);
		
		if (heladera != NULL)
		{
			if (heladera->get_stock() < 5)
				aux->operator+(lista_electrodomesticos->lista[i]);
		}

		if (microondas != NULL)
		{
			if (microondas->get_stock() < 5)
				aux->operator+(lista_electrodomesticos->lista[i]);
		}

		if (televisor != NULL)
		{
			if (televisor->get_stock() < 5)
				aux->operator+(lista_electrodomesticos->lista[i]);
		}
	}


	return aux;
}

void cMusimundo::AgregarHeladeras(cLista<cElectrodomesticos>* aux, int cant)
{
	switch (cant)
	{
	case 1:
	{
		cHeladera* h1 = new cHeladera(4, "Philco", 50, 90500, "1414750", "dos puertas", 180, 200, 70);
		aux->operator+(h1);
	}
	case 2:
	{
		cHeladera* h1 = new cHeladera(4, "Philco", 50, 85500, "1414750", "dospuertas", 180, 200, 70);
		cHeladera* h2 = new cHeladera(1, "Gafa", 45, 91500, "1414025", "freezersuperior", 81.3, 198, 60.0);
		aux->operator+(h1);
		aux->operator+(h2);
	}

	case 3:
	{
		cHeladera* h1 = new cHeladera(4, "Philco", 50, 65500, "1414700", "freezerinferior", 70, 180, 55);
		cHeladera* h2 = new cHeladera(1, "Gafa", 45, 91500, "1414025", "freezersuperior", 81.3, 198, 60.0);
		cHeladera* h3 = new cHeladera(4, "Whirpool", 35, 85500, "1414750", "dos puertas", 180, 200, 70);

		aux->operator+(h1);
		aux->operator+(h2);
		aux->operator+(h3);

	}
	}
}

void cMusimundo::AgregarMicroondas(cLista<cElectrodomesticos>* aux, int cant)
{
	switch (cant)
	{
	case 1:
	{
		cMicroondas* m1 = new cMicroondas(50, "Philco", 13.5, 31523, "1515038", "digital", 39.2, 48.5, 29.2);
		aux->operator+(m1);
	}
	case 2:
	{
		cMicroondas* m1 = new cMicroondas(50, "Philco", 13.5, 31523, "1515038", "digital", 39.2, 48.5, 29.2);
		cMicroondas* m2 = new cMicroondas(60, "Samsung", 15, 36000, "1515040", "digital", 45.2, 50.5, 32.2);
		aux->operator+(m1);
		aux->operator+(m2);
	}

	case 3:
	{
		cMicroondas* m1 = new cMicroondas(50, "Philco", 13.5, 31523, "1515038", "digital", 39.2, 48.5, 29.2);
		cMicroondas* m2 = new cMicroondas(60, "Samsung", 15, 36000, "1515040", "digital", 45.2, 50.5, 32.2);
		cMicroondas* m3 = new cMicroondas(50, "Atma", 20, 20500, "1515555", "analogo", 32, 41, 25);

		aux->operator+(m1);
		aux->operator+(m2);
		aux->operator+(m3);

	}
	}
}

void cMusimundo::AgregarTelevisores(cLista<cElectrodomesticos>* aux, int cant)
{
	switch (cant)
	{
	case 1:
	{
		cTelevisor* t1 = new cTelevisor(22, "Samsung", 13.9, 119.999, "1616083", "smart4k", 123, 70.7, 5.9);
		aux->operator+(t1);
	}
	case 2:
	{
		cTelevisor* t1 = new cTelevisor(22, "Samsung", 13.9, 119.999, "1616083", "smart4k", 123, 70.7, 5.9);
		cTelevisor* t2 = new cTelevisor(10, "LG", 20.9, 100.300, "1616081", "FullHD", 110, 60.7, 7.9);
		aux->operator+(t1);
		aux->operator+(t2);
	}
	
	case 3:
	{
		cTelevisor* t1 = new cTelevisor(22, "Samsung", 13.9, 119.999, "1616083", "smart4k", 123, 70.7, 5.9);
		cTelevisor* t2 = new cTelevisor(10, "LG", 20.9, 100.300, "1616081", "FullHD", 110, 60.7, 7.9); 
		cTelevisor* t3 = new cTelevisor(22, "Philips", 17.9, 50000, "1616086", "3D", 50, 30.2, 5.5);
		aux->operator+(t1);
		aux->operator+(t2);
		aux->operator+(t3);

	}
	}
}

cLista<cElectrodomesticos>* cMusimundo::CompletarStock() {
	
	cLista<cElectrodomesticos>* aux = VerificarStockMinimo();
	
	int n = aux->get_cant_actual();

	int cont_h = 0;
	int cont_m = 0;
	int cont_t = 0;

	for (int i = 0; i < n; i++)
	{
		cHeladera* heladera = dynamic_cast<cHeladera*>(aux->lista[i]);
		cMicroondas* microondas = dynamic_cast<cMicroondas*>(aux->lista[i]);
		cTelevisor* televisor = dynamic_cast<cTelevisor*>(aux->lista[i]);

		if (heladera != NULL)
		{
			if (cont_h = 0)
			{
				int cont = heladera->get_stock();
				int cant_heladeras_crear = 5 - cont;
				heladera->set_stock(5);
				
				AgregarHeladeras(aux, cant_heladeras_crear);
				cont_h++;
			}
		}

		if (microondas != NULL)
		{
			if (cont_m = 0)
			{
				int cont = microondas->get_stock();
				int cant_microondas_crear = 5 - cont;
				microondas->set_stock(5);

				AgregarMicroondas(aux, cant_microondas_crear);
				cont_m++;
			}
		}

		if (televisor != NULL)
		{
			if (cont_t = 0)
			{
				int cont = televisor->get_stock();
				int cant_televisores_crear = 5 - cont;
				televisor->set_stock(5);

				AgregarHeladeras(aux, cant_televisores_crear);
				cont_t++;
			}
		}

	} 

	return aux;

	/*Observar que nosotras estamos agregando elementos a la lista por lo que su cantidad actual va a aumentar, pero el for 
	va a ir desde la cantidad actual inicial (antes de que se empiecen a agregar electrodomesticos) ya que entendemos que no es 
	neesario a analizar estos nuevos elementos. Ademas, ni siquiera es necesario analizar todos ya que con el primer electrodomestico 
	que aparezca de cada tipo, ya se va a satisfacer lo pedido*/

}
cLista<cElectrodomesticos>* cMusimundo::VerificarCostoListaCompleta() {
	
	cLista<cElectrodomesticos>* aux = CompletarStock();
	float acum = 0;
	int n = aux->get_cant_actual();

	for (int i = 0; i < n; i++)
	{
		acum = acum + aux->lista[i]->get_precio();
	}

	if (acum < 20000 || n < 15)
	{
		if (aux != NULL) {
			for (int i = 0; i < n; i++) {
				if (aux->lista[i] != NULL) {
					delete aux->lista[i];
				}
			}
			delete[] aux;
		}
		return NULL;
	}

	return aux;
}
void cMusimundo::AgregarListaAlStock() {

	cLista<cElectrodomesticos>* aux = VerificarCostoListaCompleta();

	if (aux == NULL)
		return;

	int n = aux->get_cant_actual();

	for (int i = 0; i < n; i++)
	{
		lista_electrodomesticos->operator+(aux->lista[i]);
	}

	return;

}

cMusimundo::~cMusimundo()
{
	if (lista_electrodomesticos != NULL)
	{
		delete lista_electrodomesticos;
	}
}
