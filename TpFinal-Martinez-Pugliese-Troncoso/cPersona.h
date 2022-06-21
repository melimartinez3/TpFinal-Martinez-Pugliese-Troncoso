#pragma once
#include <stdio.h>
#include<string>
#include<iostream>

#include "cMusimundo.h"

using namespace std;
class cPersona
{
private:
	string nombrecompleto;
	string dni;
public:
	cPersona();
	virtual ~cPersona() {};
	string get_nombre() {
		return this->nombrecompleto;
	}
	string get_dni() {
		return this->dni;
	}

	friend ostream& operator<<(ostream& out, const cPersona& persona);
	friend istream& operator>>(istream& in, cPersona& persona);

};

