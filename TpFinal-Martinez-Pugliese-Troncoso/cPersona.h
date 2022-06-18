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
	string fechanacimiento;
public:
	cPersona(string nomyap, string _dni, string fechanac);
	virtual ~cPersona() {};
	string get_nombre() {
		return this->nombrecompleto;
	}
	string get_dni() {
		return this->dni;
	}
	string get_fechanac() {
		return this->fechanacimiento;
	}
};

