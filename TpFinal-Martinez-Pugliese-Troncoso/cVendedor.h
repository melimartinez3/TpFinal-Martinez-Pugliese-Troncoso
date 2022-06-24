#pragma once
#include "cEmpleado.h"


class cVendedor :
    public cEmpleado
{
    float comision;// remuneracion por venta
    int vendidos;
    cLista<cElectrodomesticos>* listaelectro;
public:
    cVendedor(string nombre_, string dni_, float sueldo_, char turno_);
    void CalcularComision();
    void AgregarElectrodomesticoVendido(cElectrodomesticos* electrodomestico);
    void EliminarYCrearNuevaLista();
    cLista<cElectrodomesticos>* BuscarProducto(string detalle, cMusimundo* musimundo);
    ~cVendedor();

};

