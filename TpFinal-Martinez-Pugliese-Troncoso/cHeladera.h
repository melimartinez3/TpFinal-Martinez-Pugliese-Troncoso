#pragma once
#include "cElectrodomesticos.h"

class cHeladera :
    public cElectrodomesticos
{
private:
    // son bool que chequean si la luz y la temperatura funcionan como se debe
    bool chequeoluzinterior;
    bool chequeotemperatura;
    int temperatura;// esta es la temp ideal que tendria que tener la heladera
    static int stockactual;
    time_t horaenchufado;
public:
    cHeladera(int _temperatura, string _marca, float _peso, float _precio, string _codigo, string _tipo, float _ancho, float _alto, float _profundidad);
    bool FuncionamientoCorrecto();
    void EnchufarHeladera();
    string to_string();
    void imprimir();
    //declarar static
    ~cHeladera();

    //declaracion de gets
    bool get_luzinterior() {
        return this->chequeoluzinterior;
    }
    int get_temperatura() {
        return this->temperatura;
    }
    time_t get_hora() {
        return this->horaenchufado;
    }

    void set_chequeotemperatura(bool _chequeotemperatura)
    {
        this->chequeotemperatura = _chequeotemperatura;
    }

    void set_chequeoluzinterior(bool _chequeoluzinterior)
    {
        this->chequeoluzinterior = _chequeoluzinterior;
    }

    void set_horaenchufado(time_t _horaenchufado)
    {
        this->horaenchufado = _horaenchufado;
    }
};

