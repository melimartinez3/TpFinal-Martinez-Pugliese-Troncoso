#include "cEmpleado.h"

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

