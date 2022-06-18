#include "cEmpleado.h"

cEmpleado::cEmpleado(string nombre, string _dni, string fechanac, string cod, float _sueldo, char _turno):cPersona(nombre, _dni, fechanac)
{
	this->sueldo = _sueldo;
	this->turno = _turno;
	this->atendiendo = false;
	this->codigo = cod;
}

void cEmpleado::FicharEntrada()
{
	this->atendiendo = true;
}

void cEmpleado::FicharSalida()
{
	this->atendiendo = false;
}
