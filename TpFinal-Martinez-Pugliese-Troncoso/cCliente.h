#pragma once
#include "cPersona.h"


enum MedioPago{efectivo, credito, debito, mercadopago};
typedef enum MedioPago eMedioPago;

class cCliente :
    public cPersona
{
private:
    eMedioPago mediodepago;
    int tarjeta;
    float saldo;
    int cantcompras;

public:
    cCliente(string nombre, string _dni, string fechanac, eMedioPago mediopago, float _saldo, int compras);
    void Comprar(cLista<cElectrodomesticos>* listaelectro, cMusimundo* musimundo);
    cElectrodomesticos* ElegirProducto(cLista<cElectrodomesticos>* listaelectro);
    void IngresarTarjeta();
    ~cCliente();

};

