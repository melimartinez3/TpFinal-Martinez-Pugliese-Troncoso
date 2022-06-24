#include "cVendedor.h"

cVendedor::cVendedor(string nombre_, string dni_, float sueldo_, char turno_):cEmpleado(nombre_,dni_,sueldo_,turno_)
{
	this->vendidos = 0;
	this->comision = 0;
	listaelectro = NULL;
}

void cVendedor::CalcularComision()
{
	float acum = 0;
	for (int i = 0; i < listaelectro->get_cant_actual(); i++) {
		acum += listaelectro->lista[i]->get_precio();
	}
	comision = (0.1 * acum); // le sumamos al sueldo el 10% de sus ventas
	set_sueldo(comision);
}

void cVendedor::AgregarElectrodomesticoVendido(cElectrodomesticos* electrodomestico)
{
	listaelectro->operator+(electrodomestico);
}

void cVendedor::EliminarYCrearNuevaLista()
{

	if (listaelectro != NULL) {
		for (int i = 0; i < listaelectro->cantactual; i++) {
			if (listaelectro->lista[i] != NULL) {
				listaelectro->lista[i] = NULL;
			}
		}
	}
	listaelectro = new cLista<cElectrodomesticos>(TMAX);
	
}

void cVendedor::BuscarProducto(string codigo, cMusimundo* musimundo)
{
	cElectrodomesticos* electrodomestico = musimundo->BuscarPorCodigo(codigo);

	int n = rand() % 1; //0 es para buscar por marca y 1 para buscar por tipo y nombre

	cLista<cElectrodomesticos>* aux = NULL;

	if (n == 0)
	{
		aux = musimundo->BuscarPorMarca(electrodomestico->get_marca());
		cout << "\nLista de elementos que coinciden con la marca " + electrodomestico->get_marca() << endl;
		cout << *aux;
	}
	else
	{
		aux = musimundo->BuscarporTipoyNombre(electrodomestico->get_tipo());
		cout << "\nLista de elementos que coinciden con el tipo " + electrodomestico->get_tipo() << endl;
		cout << *aux;
	}
}


cVendedor::~cVendedor()
{
	if (listaelectro != NULL) {
		delete listaelectro;
	}
}
