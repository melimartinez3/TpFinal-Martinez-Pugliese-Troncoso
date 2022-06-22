#pragma once
#include "cEmpleado.h"


class cVendedor :
    public cEmpleado
{
    float comision;// remuneracion por venta
    int vendidos;
    cLista<cElectrodomesticos>* listaelectro;
public:
    cVendedor();
    void CalcularComision();
    void AgregarElectrodomesticoVendido(cElectrodomesticos* electrodomestico);
    void EliminarYCrearNuevaLista();
    cLista<cElectrodomesticos>* BuscarProducto(string detalle, cMusimundo* musimundo);
    ~cVendedor();

};

