#pragma once
#include "cPersona.h"


class cEmpleado :
    public cPersona
{
private:
    const int codigo;
    static int cont_codigo;
    float sueldo;
    char turno; // M ma�ana T tarde N noche
    bool atendiendo;//si esta en su turno o no
public:
    cEmpleado(string nombre, string dni, float sueldo,char turno);
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

