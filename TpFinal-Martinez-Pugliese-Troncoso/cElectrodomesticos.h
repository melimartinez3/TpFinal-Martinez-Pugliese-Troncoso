#pragma once
#include "cTemplate.h"
#include "cDimensiones.h"
#include <ctime>
#include <sstream>
class cMusimundo;
//#pragma warning(disable:4996)
//#define _CRT_SECURE_NO_WARNINGS
class cDespachante;
class cVendedor;


using namespace std;

class cElectrodomesticos
{
protected:
	const int voltaje;// volatje es 220 
	const string marca;
	cDimensiones* dimensiones;
	float peso;
	float precio;
	const string codigo;
	const string tipo;
	static int vendidos;

public:

	cElectrodomesticos(string _marca, float _peso, float _precio, string _codigo, string _tipo, float _ancho, float _alto, float _profundidad);// declarar los const
	virtual bool FuncionamientoIncorrecto()=0;
	// estas funciones no las implementamos en el cpp ya que son virtual
	virtual string tostring() const {
		string precio_string = to_string(precio);
		
		string dato = "\nMarca: " + marca + " Codigo: " + codigo + " Tipo: " + tipo + " Precio: " + precio_string;
		return dato;
	}
	virtual void imprimir() const {

		string dato = tostring();
		cout << dato;
	}

	~cElectrodomesticos();
	void set_precio(float precio) {
		this->precio = precio;
	}
	float get_peso() {
		return this->peso;
	}
	float get_precio() {
		return this->precio;
	}
	string get_marca() {
		return this->marca;
	}
	string get_codigo() {
		return this->codigo;
	}
	string get_tipo() {
		return this->tipo;
	}
	int get_vendidos() {
		return this->vendidos;
	}
};

