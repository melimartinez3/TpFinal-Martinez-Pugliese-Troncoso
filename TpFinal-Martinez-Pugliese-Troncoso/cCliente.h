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
    cCliente();
    void Comprar(cMusimundo* musimundo, int dia, int mes, int anio);
    cElectrodomesticos* ElegirProducto(cLista<cElectrodomesticos>* listaelectro);
    void IngresarTarjeta();
    void PedirDatosCliente();
    ~cCliente();
    float get_saldo() {
        return this->saldo;
    }
    void set_saldo(float nuevo) {
        this->saldo = nuevo;
    }

    friend ostream& operator<<(ostream& out, const cCliente& cliente);
    friend istream& operator>>(istream& in, cCliente& cliente);
};

