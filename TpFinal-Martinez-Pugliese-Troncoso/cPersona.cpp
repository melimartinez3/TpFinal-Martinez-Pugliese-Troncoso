#include "cPersona.h"


cPersona::cPersona() {
	this->nombrecompleto = " ";
	this->dni = " ";
}

ostream& operator<<(ostream& out, const cPersona& persona)
{
	out << "Nombre y Apellido: " << persona.nombrecompleto << "DNI: " << persona.dni;
	return out;
}
istream& operator>>(istream& in, cPersona& persona)
{
	cout << "Ingresar Nombre y Apellido: " << endl;
	string nom;
	in >> nom;	
	persona.nombrecompleto = nom;
	fflush(stdin);
	cout << "Ingresar DNI: " << endl;
	string dni_;
	in >> dni_;
	persona.dni = dni_;
	fflush(stdin);

	return in;
}

