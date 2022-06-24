#include "cCliente.h"


cCliente::cCliente(string nombre_, string dni_, float saldo_, int cant_compras, eMedioPago medio):cPersona(nombre_,dni_)
{
	this->mediodepago = efectivo;
	this->tarjeta = 0;
	this->saldo = saldo_;
	this->cantcompras = cant_compras;
}

void cCliente::Comprar(cMusimundo* musimundo, int dia, int mes, int anio)
{
	cElectrodomesticos* aux = NULL;
	for (int i = 0; i < cantcompras; i++) {
	aux= ElegirProducto(musimundo->get_lista_electrodomesticos());

		if (aux != NULL) {
			if ( mediodepago!=efectivo){

				IngresarTarjeta();
				try {
					if (saldo < aux->get_precio())
						throw;
				}
				catch (exception* e) {
					cerr << "No se puede realizar la compra : "<<e->what() <<endl;
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
	int tarjetaaux;

		cout << "Ingrese su numero de tarjeta" << endl;
		cin >> tarjeta;
		tarjetaaux = tarjeta;
		int aux;

		while (tarjetaaux != 0) {
			aux = tarjetaaux % 10;
			tarjetaaux /= 10;
			suma += aux;
		}

		if (suma != 16) {
			tarjetaaux = 0;
			do {
				cout << "Ingrese nuevamente su numero de tarjeta: " << endl;
				cin >> tarjeta;
				tarjetaaux = tarjeta;
				fflush(stdin);
				while (tarjetaaux != 0) {
					aux = tarjetaaux % 10;
					tarjetaaux /= 10;
					suma += aux;
				}
			} while (suma != 16);
		}
		this->tarjeta = tarjetaaux;
//ingresa el numero de tarjeta y calculamos la cantidad de digitos que ingreso, si es diferente de 16 va a entrar a un do while 
// que va a repetir infinitamente que ingrese su tarjeta hasta que la suma sea igual. Trabajamos con un tarjeta aux, para no ir modificando
		
}

bool cCliente::operator==(const eMedioPago ingresado)
{
	if ( this->mediodepago == ingresado)
		return true;

	return false;
}
bool cCliente::operator!=(const eMedioPago ingresado) {

	if (this->mediodepago != ingresado)
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

	string tarjeta_;
	if (cliente.mediodepago == credito || cliente.mediodepago == debito || cliente.mediodepago == mercadopago) {

		cliente.IngresarTarjeta();
	}

	cout << endl;
	
	return in;
	
}

bool cCliente::operator<(const float precio_) {
	if (this->saldo < precio_)
		return false;
	else return true;
}



cCliente::~cCliente()
{
}
