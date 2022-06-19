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
	cElectrodomesticos* BuscarPorCodigo(string _codigo, cMusimundo* musimundo);
	cLista<cElectrodomesticos>* BuscarPorMarca(string _marca, cMusimundo* musimundo);
	cLista<cElectrodomesticos>* BuscarporTipoyNombre(string _tipo, string _nombre, cMusimundo* musimundo);
	void RemitirProducto(cDespachante* despachante, cMusimundo* musimundo, cVendedor* vendedor);
	
	virtual bool FuncionamientoIncorrecto()=0;
	virtual string to_string()=0;
	virtual void imprimir()=0;

	~cElectrodomesticos();
	void set_precio(float precio) {
		this->precio = precio;
	}
	bool get_peso() {
		return this->peso;
	}
	bool get_precio() {
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

