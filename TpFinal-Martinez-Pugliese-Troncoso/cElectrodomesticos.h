#pragma once
#include "cTemplate.h"
#include "cDimensiones.h"
#include "ctime"
class cDespachante;

using namespace std;

class cElectrodomesticos
{
protected:
	const string marca;
	cDimensiones dimensiones;
	float peso;
	float precio;
	const string codigo;
	const string tipo;
	static int vendidos;

public:

	cElectrodomesticos(string _marca, float _peso, float _precio, string _codigo, string _tipo, float ancho, float alto, float profundidad);// declarar los const
	cLista<cElectrodomesticos>*BuscarPorCodigo(string _codigo);
	cLista<cElectrodomesticos>*BuscarPorMarca(string _marca);
	cLista<cElectrodomesticos>*BuscarporTipoyNombre(string _tipo, string _nombre);
	void RemitirProducto(cDespachante* despachante);
	virtual bool FuncionamientoCorrecto()=0;
	~cElectrodomesticos();

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

