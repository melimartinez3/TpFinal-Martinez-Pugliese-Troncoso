#include "cMusimundo.h"
int main() {
	srand(time(NULL));
	cElectrodomesticos* heladera1 = new cHeladera (1,"Gafa",45, 91500, "1414025", "freezersuperior", 81.3, 198, 60.0);
	cElectrodomesticos* microondas1 = new cMicroondas(50, "Philco", 13.5, 31523, "1515038", "digital", 39.2, 48.5, 29.2);
	cElectrodomesticos* televisor1 = new cTelevisor(22, "Samsung", 13.9, 119.999, "1616083", "smart4k", 123, 70.7, 5.9);

	cMusimundo* musimundo = new cMusimundo();

	musimundo->imprimir();
	heladera1->imprimir();
	microondas1->imprimir();
	televisor1->imprimir();

	cLista<cElectrodomesticos>* listaaux = musimundo->VerificarStockMinimo();
	if (listaaux != NULL)
	{
		musimundo->CompletarStock();
		bool ok=musimundo->VerificarCostoListaCompleta();
		if (ok)
			musimundo->AgregarListaAlStock();
		else {
			delete listaaux;
			listaaux = NULL;
		}
	}

	

	if (heladera1 != NULL)
		delete heladera1;
	if (microondas1 != NULL)
		delete microondas1;
	if (televisor1 != NULL)
		delete televisor1;
	if (listaaux != NULL)
		delete listaaux;

	return 0;
}