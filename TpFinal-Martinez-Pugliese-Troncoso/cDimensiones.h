#pragma once
#include <stdio.h>
#include<string>
#include<iostream>

using namespace std;

class cDimensiones
{
private:
	float ancho;
	float alto;
	float profundidad;
public:

	cDimensiones(float _ancho, float _alto, float _profundidad);
	~cDimensiones();

};

cDimensiones::cDimensiones(float _ancho, float _alto, float _profundidad)
{
	this->ancho = _ancho;
	this->alto = _alto;
	this->profundidad = _profundidad;
}

cDimensiones::~cDimensiones(){}

