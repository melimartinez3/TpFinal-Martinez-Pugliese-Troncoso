#pragma once
#include "cEmpleado.h"


class cVendedor :
    public cEmpleado
{
    float comision;// remuneracion por venta
    int vendidos;
    cLista<cElectrodomesticos>* listaelectro;
public:
    cVendedor(string nombre, string _dni, string fechanac, string cod, float _sueldo, char _turno, bool _carisma);
    void CalcularComision();
    void AgregarElectrodomesticoVendido(cElectrodomesticos* electrodomestico);
    void EliminarYCrearNuevaLista();
    ~cVendedor();
};

