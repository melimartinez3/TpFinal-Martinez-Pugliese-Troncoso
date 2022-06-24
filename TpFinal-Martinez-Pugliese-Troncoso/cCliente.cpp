#include "cCliente.h"


cCliente::cCliente(string nombre_, string dni_, float saldo_, int cant_compras, eMedioPago medio):cPersona(nombre_,dni_)
{
	this->mediodepago = efectivo;
	this->tarjeta = 0;
	this->saldo = saldo_;
	this->cantcompras = cant_compras;
}


/// <summary>
/// se selecciona el producto a comprar (la cantidad de veces que diga un random)(maximo 3) si se compra con tarjeta se debe introducir el numero de esta. se resta el precio del producto del saldo, se llama a vendidos en el dia para contar una compra y se lo despacha
/// </summary>
/// <param name="musimundo"></param>
/// <param name="dia"></param>
/// <param name="mes"></param>
/// <param name="anio"></param>
void cCliente::Comprar(cMusimundo* musimundo, int dia, int mes, int anio)
{
	cElectrodomesticos* aux = NULL;
	float acum_precios = 0; //acumulador de precios por si el cliente compra mas de un electrodomestico
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
					cerr << "\nNo se puede realizar la compra : "<<e->what() <<endl;
					return;
				}
		
			}
		}
		else
		{
			cout << "\nEl cliente no continuo con la compra" << endl;
			return;
		}

		musimundo->Con_o_Sin_Descuento();
		acum_precios = acum_precios + aux->get_precio(); 
	}

	
	if (saldo > acum_precios)
		this->set_saldo(saldo - acum_precios);
	else {
		cout << "\n El cliente no pudo comprar nada por su saldo insuficiente " << endl;
		return;
	}

	try {
		musimundo->VendidosenelDia(dia, mes, anio, aux);
	}
	catch (...) {
		return;
	}
	musimundo->DespacharProducto(aux->get_codigo());
	return;
}


/// <summary>
/// de forma random se selecciona un producto
/// </summary>
/// <param name="listaelectro"></param>
/// <returns></returns>
cElectrodomesticos* cCliente::ElegirProducto(cLista<cElectrodomesticos>* listaelectro)
{
	int n=listaelectro->get_cant_actual();

	int prod = rand() % n;

	return listaelectro->lista[prod];

}


/// <summary>
/// se pide por consola el numero de tarjeta del usuraio, el cliente no sale de aca sin poner bien los 16 digitos de la tarjeta
/// </summary>
void cCliente::IngresarTarjeta()
{
	int suma = 0;
	int tarjetaaux;

		cout << " Ingrese su numero de tarjeta" << endl;
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


/// <summary>
/// compara si los metodos de pago son los mismos
/// </summary>
/// <param name="ingresado"></param>
/// <returns></returns>
bool cCliente::operator==(const eMedioPago ingresado)
{
	if ( this->mediodepago == ingresado)
		return true;

	return false;
}

/// <summary>
/// compara si los metodos de pago son distintos
/// </summary>
/// <param name="ingresado"></param>
/// <returns></returns>
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

/// <summary>
/// compara si el saldo es menor al precio del producto
/// </summary>
/// <param name="precio_"></param>
/// <returns></returns>
bool cCliente::operator<(const float precio_) {
	if (this->saldo < precio_)
		return false;
	else return true;
}



cCliente::~cCliente()
{
}
