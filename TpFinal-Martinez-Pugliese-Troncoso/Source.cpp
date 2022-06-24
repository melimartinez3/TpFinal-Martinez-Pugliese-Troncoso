#include "cDespachante.h"
#include "cCliente.h"
#include "cVendedor.h"

//void ClientePorMinuto(cMusimundo* musimundo);
void PRUEBA(cMusimundo* musimundo);
int main() {

	srand(time(NULL));

	cElectrodomesticos* heladera1 = new cHeladera (2,"Gafa",45, 91500, "1414025", "freezersuperior", 81.3, 198, 60.0);
	cElectrodomesticos* microondas1 = new cMicroondas(50, "Philco", 13.5, 31523, "1515038", "digital", 39.2, 48.5, 29.2);
	cElectrodomesticos* televisor1 = new cTelevisor(22, "Samsung", 13.9, 119.999, "1616083", "smart4k", 123, 70.7, 5.9);

	cMusimundo* musimundo = new cMusimundo();

	cVendedor* vendedor1 = new cVendedor("juan perez","44514408",345987,'T');
	cDespachante* despachante1 = new cDespachante("Juan Carlos", "44894408", 349997, 'M');

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

	vendedor1->BuscarProducto("1414025", musimundo);

	//ClientePorMinuto(musimundo);
	PRUEBA(musimundo);

	//adentro del bucle
	musimundo->Determinar_Descuento(); //se fija si es o no el dia 31 del mes para aplicar el descuento
	
	musimundo->Termino_Dia_De_Descuentos();



	/*if (heladera1 != NULL)
		delete heladera1;
	if (microondas1 != NULL)
		delete microondas1;
	if (televisor1 != NULL)
		delete televisor1;
	if (listaaux != NULL)
		delete listaaux;*/

	return 0;
}

//void ClientePorMinuto(cMusimundo* musimundo)
//{
//
//	clock_t inicio;
//	int contador = 0;
//	int resta;
//
//	do {
//		inicio = clock();
//
//		do {
//
//			if (clock() - inicio == 10)
//			{
//				resta = clock() / CLOCKS_PER_SEC - inicio / CLOCKS_PER_SEC;
//				if (resta == 10) {
//
//					cout << "\nIngreso un cliente";
//					cCliente* cliente=NULL;
//					
//					cliente = musimundo->crear_cliente();
//
//					if (cliente == NULL)
//						break;
//					
//				 cout << "Informacion del cliente:";
//				 cout << *cliente;
//				 cliente->Comprar(musimundo, 20, 06, 2022);
//				 delete cliente;// no chequeamos que este en NULL porque ya esta controlado con el try catch anterior
//				 contador++;
//
//				 cout << "\nEl cliente finalizo su compra";
//
//				 break;
//			    }
//			}	
//
//		} while (1);
//
//	} while (contador < 3);
//}

void PRUEBA(cMusimundo* musimundo) {

	int cont = 0;

	time_t hora_inicial;
	hora_inicial = time(NULL);
	(void)ctime(&hora_inicial);
	
	cout << "\nIngreso un cliente";
	cCliente* cliente = NULL;

	cliente = musimundo->crear_cliente();

	if (cliente == NULL)
		return;

	cout << "Informacion del cliente:";
	cout << *cliente;
	
		cliente->Comprar(musimundo, 20, 06, 2022);
	
	delete cliente;// no chequeamos que este en NULL porque ya esta controlado 
	cont++;

	do {
		time_t hora_actual;
		hora_actual = time(NULL);
		(void)ctime(&hora_actual);
		time_t aux = difftime(hora_actual, hora_inicial);
		if (aux >= 3) {

			cout << "\nIngreso un cliente";
			cCliente* cliente = NULL;

			cliente = musimundo->crear_cliente();

			if (cliente == NULL)
				return;

			cout << "Informacion del cliente:";
			cout << *cliente;
			cliente->Comprar(musimundo, 20, 06, 2022);
			delete cliente;// no chequeamos que este en NULL porque ya esta controlado 
			cont++;

			hora_inicial = time(NULL);
			(void)ctime(&hora_inicial);

		}
		

	} while (cont < 5);

}

