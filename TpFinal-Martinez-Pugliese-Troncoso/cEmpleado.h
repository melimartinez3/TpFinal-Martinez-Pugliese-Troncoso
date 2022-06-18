#pragma once
#include "cPersona.h"


class cEmpleado :
    public cPersona
{
private:
    string codigo;// determina si es vendedor(33) o despachante(44) 
    float sueldo;
    char turno; // M mañana T tarde N noche
    bool atendiendo;
public:
    cEmpleado(string nombre, string _dni, string fechanac, string cod, float _sueldo, char _turno);
    void FicharEntrada();
    void FicharSalida();
    virtual~cEmpleado() {};

    void set_sueldo(float _sueldo) {
        this->sueldo += _sueldo;
    }

};

