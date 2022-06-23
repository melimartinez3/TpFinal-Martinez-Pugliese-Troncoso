#include "cDespachante.h"
#include "cCliente.h"
#include "cVendedor.h"

void ClientePorMinuto(cMusimundo* musimundo);

int main() {

	srand(time(NULL));

	cElectrodomesticos* heladera1 = new cHeladera (2,"Gafa",45, 91500, "1414025", "freezersuperior", 81.3, 198, 60.0);
	cElectrodomesticos* microondas1 = new cMicroondas(50, "Philco", 13.5, 31523, "1515038", "digital", 39.2, 48.5, 29.2);
	cElectrodomesticos* televisor1 = new cTelevisor(22, "Samsung", 13.9, 119.999, "1616083", "smart4k", 123, 70.7, 5.9);

	cMusimundo* musimundo = new cMusimundo();

	cVendedor* vendedor1 = new cVendedor();
	cDespachante* despachante1 = new cDespachante();

	musimundo->get_lista_vendedores()->operator+(vendedor1); //agregamos a los empleados a sus respectivas listas
	musimundo->get_lista_despachantes()->operator+(despachante1);

	//imprimimos
	heladera1->imprimir();
	microondas1->imprimir();
	televisor1->imprimir();

	musimundo->get_lista_electrodomesticos()->operator+(heladera1); //agregamos la heladera, el microondas y el tellevisor a la lista de electrodomesticos de musimundo
	musimundo->get_lista_electrodomesticos()->operator+(microondas1);
	musimundo->get_lista_electrodomesticos()->operator+(televisor1);

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

	ClientePorMinuto(musimundo);
	//adentro del bucle
	musimundo->Determinar_Descuento(); //se fija si es o no el dia 31 del mes para aplicar el descuento
	
	musimundo->Termino_Dia_De_Descuentos();



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

void ClientePorMinuto(cMusimundo* musimundo)
{
	clock_t inicio;
	int contador = 0;
	int resta;

	do {
		inicio = clock();

		do {

			if (clock() - inicio == 60)
			{
				resta = clock() / CLOCKS_PER_SEC - inicio / CLOCKS_PER_SEC;
				if (resta == 60) {
					cCliente* cliente=NULL;
					try {
						cliente = new cCliente();
					}
					catch (bad_alloc *e) {// buscar si new lanza bad allcoc dinamico o estatico, dinamico es con *e estatico con &e, el e contiene el tipo de error 
						cout << "\nOcurrio un error: "<< e->what()<< " Se cerrara esta funcion";
						delete e;
						e = NULL;
						return;
					}
				  cliente->PedirDatosCliente();

				 cout << "Informacion del cliente:";
				 cout << *cliente;
				 cliente->Comprar(musimundo, 20, 06, 2022);
				 delete cliente;// no chequeamos que este en NULL porque ya esta controlado con el try catch anterior
				 contador++;
				 break;
			    }
			}

	

		} while (1);

	} while (contador < 3);
}