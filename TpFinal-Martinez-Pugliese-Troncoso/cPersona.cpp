#include "cPersona.h"


cPersona::cPersona(string nombre, string dni) {
	this->nombrecompleto = nombre;
	this->dni = dni;
}

ostream& operator<<(ostream& out, const cPersona& persona)
{
	out << "Nombre y Apellido: " << persona.nombrecompleto << " DNI: " << persona.dni + " ";
	return out;
}
istream& operator>>(istream& in, cPersona& persona)
{
	cout << " Ingrese el mail de la persona : "<<persona.nombrecompleto << endl;
	string mail_;
	in >> mail_;	
	persona.mail = mail_;
	fflush(stdin);
	
	return in;
}

