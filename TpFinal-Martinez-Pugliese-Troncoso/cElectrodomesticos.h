#pragma once
#include <stdio.h>
#include<string>
#include<iostream>
class cDespachante;

using namespace std;
struct Dimensiones {
	float ancho;
	float alto;
	float profundidad;
};
class cElectrodomesticos
{
protected:
	string marca;
	Dimensiones dimension;
	float peso;
	float precio;
	string codigo;
	string tipo;
	static int vendidos;

public:
	virtual cLista<cElectrodomesticos>*BuscarPorCodigo(string _codigo);
	virtual cLista<cElectrodomesticos>*BuscarPorMarca(string _marca);
	virtual cLista<cElectrodomesticos>*BuscarporTipoyNombre(string _tipo, string _nombre);
	void RemitirProducto(cDespachante* despachante);
	virtual bool FuncionamientoCorrecto();

};

