#include "cMusimundo.h"
#include "cVendedor.h"
#include "cDespachante.h"
#include "cCliente.h"


cMusimundo::cMusimundo() :stockminimo(5)
{
	this->totalrecaudado = 0;
	lista_electrodomesticos = new cLista<cElectrodomesticos>(TMAX);
	lista_vendidos = new cLista<cElectrodomesticos>(TMAX);
	lista_vendedores = new cLista<cVendedor>(TMAX);
	lista_despachantes = new cLista<cDespachante>(TMAX);
	this->dia = 24;// asumimos que es la inaguracion de musimundo
	this->mes = 6;
	this->anio = 2022;
}

int cMusimundo::vendidos_dia = 0;
float cMusimundo::totalrecaudado = 0;


/// <summary>
/// Se fija que hija de electrodomestico es y setea el stock a uno menor, le suma su precio al total recaudado y devuelve a el puntero
/// esta funcion nos sirve para ver el tema stock y el total recaudado, retornamos al puntero por izquierda porque nos parece que deja al codigo mas entendible cuando lo utlizamos en otras funciones
/// <param name="electrodomestico"></param>
/// <returns></returns>
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
		
	}else if (microondas != NULL)
	{
		aux_elect = new cMicroondas(*microondas);
		int n = microondas->get_stock();
		microondas->set_stock(n--);


	}
	else if (televisor != NULL)
	{
		aux_elect = new cTelevisor(*televisor);
		int n = televisor->get_stock();
		televisor->set_stock(n--);
	}
	else
	{
		throw new exception("\nNo se encontro en articulo buscado ");
		return NULL; 
	}

	totalrecaudado = totalrecaudado + aux_elect->get_precio();
	return aux_elect;
}




/// <summary>
/// con un random elegimos al primer vendedor que se encuentra en la lista que esta atendiendo, esta trabajando.
/// </summary>
/// <returns></returns>
cVendedor* cMusimundo:: EleccionVendedor()
{
	int n = lista_vendedores->get_cant_actual();
	bool ok =false;
	int pos;

	do
	{
	    pos = rand() % n;
		if (lista_vendedores->lista[pos] != NULL)
		{
			ok = lista_vendedores->lista[pos]->get_atendiendo();// elegimos al primer vendedor disponible
			break;
		}
			
	} while (ok != true);

	return lista_vendedores->lista[pos]; 

	/*No se va a salir del bucle hasta que se encuentre un vendedor disponible. Asumimos que el cliente se 
	quedará esperando*/

}




/// <summary>
/// le pasamos el codigo del producto a un despacante rnadom que se encuentre en la lista asociada a los despachantes
/// </summary>
/// <param name="codigo"></param>
void cMusimundo::DespacharProducto(string codigo)
{
	int n = lista_despachantes->get_cant_actual();
	int pos = rand() % n;

	lista_despachantes->lista[pos]->DespacharProducto(codigo, this);
}



/// <summary>
/// hace las cuentas sobre el cambio de dia, imrpime los datos del dia transcurrido una vez finalizado y resetea a 0 la lista de vendidos y recaudado
/// </summary>
/// <param name="_dia"></param>
/// <param name="_mes"></param>
/// <param name="_anio"></param>
/// <param name="vendido"></param>
void cMusimundo::VendidosenelDia(int _dia, int _mes, int _anio, cElectrodomesticos* vendido) {
	
	cVendedor* vendedor = EleccionVendedor();

	cElectrodomesticos* electrodomestico = ProductoAVender(vendido);

	if (this->dia == _dia && this->mes  == _mes && this->anio  == _anio) {
		vendidos_dia++;// es el dia de hoy, le sumamos uno
		lista_vendidos->operator+(electrodomestico);
		vendedor->AgregarElectrodomesticoVendido(electrodomestico);

	}
	else 
	{ //comenzo un nuevo dia
		if (this->dia != 31) {
			set_dia(dia++);
		}
		else if (this->dia == 31 && this->mes!=12) {
			set_mes(mes++);
			set_dia(1);
		}
		else {
			set_anio(anio++);
			set_mes(1);
			set_dia(1);
		}
		imprimir();
		totalrecaudado = 0;
		vendidos_dia = 0; //las ventas vuelven a 0
		totalrecaudado = 0;
		vendidos_dia++;//le sumamos uno
		vendedor->EliminarYCrearNuevaLista();
		lista_vendidos = new cLista<cElectrodomesticos>(TMAX);
		lista_vendidos->operator+(electrodomestico);
		vendedor->AgregarElectrodomesticoVendido(electrodomestico);
	}
}


/// <summary>
/// verifica que el stock de todos los tipos de electrodomesticos tengan minimo de 5 en stock y retorna la lista de electrodomesticos que no cumple con la condicion
/// </summary>
/// <returns></returns>
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

	n = aux->get_cant_actual();
	if (n == 0)
	{
		return NULL;
	}

	return aux;
}


/// <summary>
/// agrega las heladeras necesarias al stock para llegar a 5
/// </summary>
/// <param name="aux"></param>
/// <param name="cant"></param>
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

/// <summary>
/// agrega los microondas necesarias al stock para llegar a 5
/// </summary>
/// <param name="aux"></param>
/// <param name="cant"></param>
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


/// <summary>
/// agrega los televisores necesarias al stock para llegar a 5
/// </summary>
/// <param name="aux"></param>
/// <param name="cant"></param>
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



/// <summary>
///llamamos a las funciones agregar_electrodomestico y verificar stockminimo, para esencialmente realizar las funciones
/// </summary>
/// <returns></returns>
cLista<cElectrodomesticos>* cMusimundo::CompletarStock() {
	
	cLista<cElectrodomesticos>* aux = VerificarStockMinimo();

	if (aux == NULL)
	{
		return NULL;
	}

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
			if (cont_h == 0)
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
			if (cont_m == 0)
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
			if (cont_t == 0)
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



/// <summary>
/// verificca que la lista de electrodomesticos qeu tienen stock menor a 5(ahora completa) valga mas de 20mil o tenga mas de 15 productos, si es asi, la une con la original. Si no, es eliminada
/// </summary>
/// <returns></returns>
cLista<cElectrodomesticos>* cMusimundo::VerificarCostoListaCompleta() {
	
	cLista<cElectrodomesticos>* aux = CompletarStock();

	if (aux == NULL)
	{
		return NULL;
	}

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


/// <summary>
/// si cumplio la condicion de verfificarcostolistacompleta los agregamos a la lista asociada a musimundo
/// </summary>
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



cElectrodomesticos& operator++(cElectrodomesticos& electro) {
	float precio_anterior = electro.get_precio();
	electro.set_precio(1.25 * precio_anterior);
	return electro;
}

cElectrodomesticos& operator--(cElectrodomesticos& electro) {
	float precio_anterior = electro.get_precio();
	electro.set_precio(0.8 * precio_anterior);
	return electro;
}

string cMusimundo::tostring() {
	
	string recaudado = to_string(totalrecaudado);
	string dato = "\nTotal Recaudado En el Dia:  " + recaudado;
	return dato;
}

/// <summary>
/// imprimimos los datos del dia
/// </summary>
void cMusimundo::imprimir() {
	string dato = tostring();
	cout << dato;
	int n = lista_vendidos->get_cant_actual();
	
	cout << "\nLos electrodomesticos vendidos en el dia fueron: ";

	for (int i = 0; i < n; i++)
	{
		cout << lista_vendidos->lista[i]->tostring() << endl;
	}

}


/// <summary>
/// si es el dia 31 del mes se le aplicara un descuento a la compra
/// </summary>
void cMusimundo::Determinar_Descuento() {
	time_t rawtime;
	struct tm timeinfo;
	time(&rawtime);
	localtime_s(&timeinfo, &rawtime);

	int dia_hoy = timeinfo.tm_mday;
	if (dia_hoy == 31) {
		Dia_De_Descuentos();
	
	}
	

}

/// <summary>
/// se le resta un porcentaje de su precio original al precio del productor (es el descuentpo) y lo seteamos en su atributo
/// </summary>
void cMusimundo::Dia_De_Descuentos() {

	int n = lista_electrodomesticos->get_cant_actual();

	for (int i = 0; i < n; i++) {
		operator--(*(lista_electrodomesticos->lista[i]));
	}

}

/// <summary>
/// pasado el 31 los precios vuelven a ser los originales
/// </summary>
void cMusimundo::Termino_Dia_De_Descuentos() {
	int n = lista_electrodomesticos->get_cant_actual();

	for (int i = 0; i < n; i++) {
		operator++(*(lista_electrodomesticos->lista[i]));
	}
}

/// <summary>
/// determina (para usar en otras funciones) si es o no el dia 31 y le avisa al usuario si su compra va a ser con descuento
/// </summary>
void cMusimundo::Con_o_Sin_Descuento() {
	time_t rawtime;
	struct tm timeinfo;
	time(&rawtime);
	localtime_s(&timeinfo, &rawtime);
	int dia_hoy = timeinfo.tm_mday;
	if (dia_hoy == 31)
		cout << "\nEsta comprando con descuento! Enhorabuena! ";
}



cElectrodomesticos* cMusimundo::BuscarPorCodigo(string _codigo) {
	cElectrodomesticos* aux = NULL;
	int pos = 0;
	int n = this->lista_electrodomesticos->get_cant_actual();
	for (int i = 0; i < n; i++) {
		if (this->lista_electrodomesticos->lista[i]->get_codigo() == _codigo) {
			aux = this->lista_electrodomesticos->lista[i];
		}
	}
	return aux;

}


cLista<cElectrodomesticos>* cMusimundo::BuscarPorMarca(string _marca) {

	int n = this->lista_electrodomesticos->get_cant_actual();
	cLista<cElectrodomesticos>* aux = new cLista<cElectrodomesticos>(n);

	for (int i = 0; i < n; i++) {

		if (this->lista_electrodomesticos->lista[i]->get_marca() == _marca) {

			aux->operator+(this->lista_electrodomesticos->lista[i]);
		}
	}

	return aux;

}

cLista<cElectrodomesticos>* cMusimundo::BuscarporTipoyNombre(string _tipo) {

	int n = this->lista_electrodomesticos->get_cant_actual();

	cLista<cElectrodomesticos>* aux = new cLista<cElectrodomesticos>(n);

	for (int i = 0; i < n; i++) {

		if (this->lista_electrodomesticos->lista[i]->get_tipo() == _tipo) {

			aux->operator+(this->lista_electrodomesticos->lista[i]);
		}
	}

	return aux;
}

/// <summary>
/// creamos de manera automatica a los clientes 
/// </summary>
/// <returns></returns>
cCliente* cMusimundo::crear_cliente() {
	string array_nombres[6] = { "Juan Carlos Fernandez","Pepito Gomez","Monica Perez","Lucho Garcia","Marcos Lopez","Jose Hidalgo" };
	string array_dni[6] = { "55667788","78945634","78567829","654786132","87612345","907856342" };
	eMedioPago pago;
	int rand_nom = rand() % 6;
	int rand_dni = rand() % 6;
	float saldo = (float)(rand() % 120000) + 200000;
	int cant = (rand() % 3)+1;
	int medio = rand() % 4;
	if (medio == 0)
		pago = efectivo;
	if (medio == 1)
		pago = credito;
	if (medio == 2)
		pago = debito;
	if (medio == 3)
		pago = mercadopago;
	// aca se deberia llamar al cin del padre, pero como nos recomendaron no pedir por consola no lo implementamos
	cCliente* aux = NULL;

	try {
		aux = new cCliente(array_nombres[rand_nom], array_dni[rand_dni], saldo, cant, pago);
	}
	catch (bad_alloc* e) {// buscar si new lanza bad allcoc dinamico o estatico, dinamico es con *e estatico con &e, el e contiene el tipo de error 
		cout << "\nOcurrio un error: " << e->what() << " Se cerrara esta funcion";
		delete e;
		e = NULL;
		return NULL;
	}
	return aux;
}

cMusimundo::~cMusimundo()
{
	if (lista_electrodomesticos != NULL)
		delete lista_electrodomesticos;


	if (lista_vendedores != NULL)
		delete lista_vendedores;

	if (lista_despachantes != NULL)
		delete lista_despachantes;
}
