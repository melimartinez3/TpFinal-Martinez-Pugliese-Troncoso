#include "cCliente.h"


cCliente::cCliente():cPersona()
{
	this->mediodepago = efectivo;
	this->tarjeta = 0;
	this->saldo = (float)((rand() % 200000) + 20000);
	this->cantcompras = 0;
}

void cCliente::Comprar(cMusimundo* musimundo, int dia, int mes, int anio)
{
	cElectrodomesticos* aux = NULL;
	for (int i = 0; i < cantcompras; i++) {
	aux= ElegirProducto(musimundo->get_lista_electrodomesticos());

		if (aux != NULL) {
			if (mediodepago == credito ||mediodepago == debito || mediodepago == mercadopago){

				IngresarTarjeta();
				try {
					if (saldo < aux->get_precio())
						throw;
				}
				catch (int& e) {
					cerr << "No se puede realizar la compra" << endl;
					return;
				}
		
			}
		}
		else
		{
			cout << "El cliente es de libra (como fiona) y no se pudo decidir :/" << endl; //SACAR
			return;
		}
	}

	float precio = aux->get_precio();
	float saldo = this->get_saldo();
	this->set_saldo(saldo - precio);

	musimundo->Con_o_Sin_Descuento();
	musimundo->VendidosenelDia(dia, mes, anio, aux);
	musimundo->DespacharProducto(aux->get_codigo());
	cout << "El cliente salio";
	return;
}

cElectrodomesticos* cCliente::ElegirProducto(cLista<cElectrodomesticos>* listaelectro)
{
	int n=listaelectro->get_cant_actual();
	for (int i = 0; i < n; i++) {
		cout << i <<"- "<< listaelectro->lista[i]->tostring() << endl;
	}
	int prod;
	cout << "Elija el producto a comprar: ";
	cin >> prod;
	fflush(stdin);
	if (prod < n)
		return listaelectro->lista[prod];
	else
	return NULL;

}

void cCliente::IngresarTarjeta()
{
	int suma = 0;
	do {
		cout << "Ingrese su numero de tarjeta" << endl;
		cin >> tarjeta;
		int tarjetaaux = tarjeta;// nos creamos un auxiliar para chequear la cantidad de cifras asi no se modifica la variable del objeto

		int aux;

		while (tarjetaaux != 0) {
			aux = tarjetaaux % 10;
			tarjetaaux /= 10;
			suma += aux;
		}
		if (suma != 16) {
			cout << "Ingrese nuevamente su nuemro de tarjeta: " << endl;
			cin >> tarjeta;
			fflush(stdin);
		}
	} while (suma != 16);
		
}

bool cCliente::operator==(const eMedioPago& ingresado)
{
	if ( this->mediodepago == ingresado)
		return true;

	return false;
}

ostream& operator<<(ostream& out, const cCliente& cliente)
{
	out << (cPersona&)cliente;
	out << "Cantidad de productos a comprar:" << cliente.cantcompras << endl;

	string medp;
	if(cliente.mediodepago==efectivo)
		medp = "efectivo"; 
	if (cliente.mediodepago==credito)
		medp = "credito";
	if (cliente.mediodepago==debito)
		medp = "debito";
	if (cliente.mediodepago== mercadopago)
		medp = "mercadopago";

	out << "Medio de Pago:" << medp << endl;

	return out;
}

istream& operator>>(istream& in, cCliente& cliente)
{
	in >> (cPersona&)cliente;
	
	cout << "Ingresar la cantidad de productos a comprar: ";
	int cant;
	in >> cant;
	fflush(stdin);
	cliente.cantcompras = cant;
	cout << endl;
	cout << "Ingresar el medio de pago (E para efectivo, C para credito, D para debito y M para mercadopago): ";
	char medp;
	in >> medp;
	if (medp == 'E' || medp == 'e')
		cliente.mediodepago = efectivo;
	if (medp == 'C' || medp == 'c')
		cliente.mediodepago = credito;
	if (medp == 'D' || medp == 'd')
		cliente.mediodepago = debito;
	if (medp == 'M' || medp == 'm')
		cliente.mediodepago = mercadopago;

	cout << endl;
	
	return in;
	
}

void cCliente::PedirDatosCliente()
{
	cin >> *this;
}


cCliente::~cCliente()
{
}
