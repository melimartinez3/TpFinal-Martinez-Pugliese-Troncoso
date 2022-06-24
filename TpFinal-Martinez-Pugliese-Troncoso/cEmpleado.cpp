#include "cEmpleado.h"

cEmpleado::cEmpleado(string nombre_, string dni_, float sueldo_, char turno_) :codigo(cont_codigo++) ,cPersona(nombre_,dni_)
{
	this->sueldo = sueldo_;
	this->turno =turno_;
	this->atendiendo = false;	
}

int cEmpleado::cont_codigo = 0;

void cEmpleado::FicharEntrada()
{
	this->atendiendo = true;
}

void cEmpleado::FicharSalida()
{
	this->atendiendo = false;
}

ostream& operator<<(ostream& out, const cEmpleado& empleado)
{
	out << (cPersona&)empleado;

	string cod = to_string(empleado.codigo);

	out << "Codigo: " << cod << "Sueldo: " << empleado.sueldo;
	return out;
}

