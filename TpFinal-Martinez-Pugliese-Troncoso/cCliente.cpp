#include "cCliente.h"


cCliente::cCliente(string nombre, string _dni, string fechanac, eMedioPago mediopago, float _saldo, int compras):cPersona(nombre, _dni, fechanac)
{
	this->mediodepago = mediopago;
	this->tarjeta = 0;
	this->saldo = _saldo;
	this->cantcompras = compras;
}

void cCliente::Comprar(cLista<cElectrodomesticos>* listaelectro, cMusimundo* musimundo)
{
	cElectrodomesticos* aux = NULL;
	for (int i = 0; i < cantcompras; i++) {
	aux= ElegirProducto(listaelectro);

		if (aux != NULL) {
			if (mediodepago == credito || mediodepago == debito || mediodepago == mercadopago) {

				IngresarTarjeta();
				try {
					if (saldo < aux->get_precio())
						throw;
				}
				catch (int& e) {
					cerr << "No se puede realizar la compra" << endl;
					return;
				}

				musimundo->ProductoAVender(aux);
			}
		}
		else
			cout << "El cliente es de libra (como fiona) y no se pudo decidir :/" << endl; //SACAR
	}
	float precio = aux->get_precio();
	float saldo = this->get_saldo();
	this->set_saldo(saldo - precio);

	musimundo->Con_o_Sin_Descuento();
}

cElectrodomesticos* cCliente::ElegirProducto(cLista<cElectrodomesticos>* listaelectro)
{
	int n=listaelectro->get_cant_actual();
	for (int i = 0; i < n; i++) {
		cout << i <<"- "<< listaelectro->lista[i]->to_string() << endl;
	}
	int prod;
	cout << "Elija el producto a comprar: ";
	cin >> prod;
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
		}
	} while (suma != 16);
		
}

cCliente::~cCliente()
{
}
