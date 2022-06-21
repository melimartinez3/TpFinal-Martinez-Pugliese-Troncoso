#pragma once
#include "cPersona.h"


class cEmpleado :
    public cPersona
{
private:
    const int codigo;
    static int cont_codigo;
    float sueldo;
    char turno; // M mañana T tarde N noche
    bool atendiendo;
public:
    cEmpleado();
    void FicharEntrada();
    void FicharSalida();
    virtual~cEmpleado() {};

    void set_sueldo(float _sueldo) {
        this->sueldo += _sueldo;
    }

    bool get_atendiendo()
    {
        return this->atendiendo;
    }

    friend ostream& operator<<(ostream& out, const cEmpleado& empleado);
    friend istream& operator>>(istream& in, cEmpleado& empleado);
};

