#include "cMicroondas.h"
//suponemos que todos los microondas tienen una potencia maxima de 1200watts  
cMicroondas::cMicroondas(int _potencia, string _marca, float _peso, float _precio, string _codigo, string _tipo, float _ancho, float _alto, float _profundidad):potencia_max(1200),cElectrodomesticos(_marca, _peso, _precio, _codigo, _tipo, _ancho, _alto, _profundidad) {
	
	this->potencia = _potencia;
	this->horaencendido = 0;
	this->luz = true;
	this->modocalentamiento = true;
}

cMicroondas::cMicroondas(const cMicroondas& microondas) :potencia_max(1200),cElectrodomesticos(microondas.marca, microondas.peso, microondas.precio, microondas.codigo, microondas.tipo, microondas.dimensiones->get_ancho(), microondas.dimensiones->get_alto(), microondas.dimensiones->get_profundidad())
{
	this->potencia = microondas.potencia;
	this->horaencendido = microondas.horaencendido;
	this->luz = microondas.luz;
	this->modocalentamiento = microondas.modocalentamiento;
}

int cMicroondas::stockactual = 6;

void cMicroondas::EnchufarMicroondas()
{
	time_t hora_t;
	hora_t = time(NULL);
	(void)ctime(&hora_t);

	this->set_horaenchufado(hora_t);
}

void cMicroondas::AjustePotenciaMaxima() {

	int n = get_potenciamax();
	set_potencia(n);

}

bool cMicroondas::ChequeoEncendidoPor1Min() {

	time_t hora_t;
	hora_t = time(NULL);
	(void)ctime(&hora_t);

	if (difftime(this->horaencendido, hora_t) > 60)
		return true;
	else
		return false;

}

bool cMicroondas::FuncionamientoIncorrecto()
{
	int random_error = (rand() %15 ) < 3;
	EnchufarMicroondas();
	AjustePotenciaMaxima();

	bool chequeo;

	try {
		chequeo = ChequeoEncendidoPor1Min();
	}
	catch (...) {
		cerr << "No ha pasado el minuto necesario de testeo" << endl;
		return false;
	}
	
	if (random_error < 3) {
		int random_caracteristiafallada = rand() % 5;

		switch (random_caracteristiafallada) {
		case teclado: { fallas[teclado] = true;
			return true; }
		case ventilador: { fallas[ventilador] = true;
			return true; }
		case puerta: {fallas[puerta] = true;
			return true; }
		case calentamiento: {fallas[calentamiento] = true;
			Modificar_fallas_calentamientos();
			return true; }
		case enchufe: {fallas[enchufe] = true;
			return true; }
		case temporizador: {fallas[temporizador] = true;
			return true; }
		}
	}
	else
		return false;

}

void cMicroondas::Modificar_fallas_calentamientos() {

int random_falla_calentamiento = rand() % 2;

switch (random_falla_calentamiento) {
case 0: {
	fallas_calentamiento[descongelar] = true;
	break;
}
case 1: {
	fallas_calentamiento[calentar] = true;
	break;
}
case 2: {
	fallas_calentamiento[cocinar] = true;
	break;
}
}
}

string cMicroondas::tostring() {

	string precio_string,dato, potencia_string;
	
	float precio_ = get_precio();
	precio_string = to_string(precio_);
	int potenciaa = get_potenciamaxima();
	potencia_string = to_string(potenciaa);

	dato = "\nMicroondas: Marca: " + marca + " Precio: " + precio_string + " Codigo: " + codigo + " Tipo: " + tipo + " Potencia: " + potencia_string;
	return dato;
}

void cMicroondas::imprimir() {
	string dato = tostring();
	cout << dato;
}

cMicroondas::~cMicroondas()
{

}
