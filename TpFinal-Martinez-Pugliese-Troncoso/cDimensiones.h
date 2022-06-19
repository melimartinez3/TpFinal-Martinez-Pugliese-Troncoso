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

	float get_ancho()
	{
		return this->ancho;
	}

	float get_alto()
	{
		return this->alto;
	}

	float get_profundidad()
	{
		return this->profundidad;
	}
};



