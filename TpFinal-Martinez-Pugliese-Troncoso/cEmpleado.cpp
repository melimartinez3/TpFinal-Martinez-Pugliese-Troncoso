#include "cEmpleado.h"

cEmpleado::cEmpleado() :codigo(cont_codigo++) ,cPersona()
{
	this->sueldo = 0;
	this->turno ='T';
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

istream& operator>>(istream& in, cEmpleado& empleado)
{
	in >> (cPersona&)empleado;
	cout << "Ingresar sueldo: ";
	float sueldo_;
	in >> sueldo_;
	empleado.sueldo = sueldo_;
	cout << "Ingresar su turno (M para mañana, T para tarde): ";
	char turno_;
	in >> turno_;
	empleado.turno = turno_;
	
	return in;
}