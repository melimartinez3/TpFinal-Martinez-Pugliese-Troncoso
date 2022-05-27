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
    time_t horaencufado;
public:
    cHeladera(int temperatura, string _marca, float _peso, float _precio, string _codigo, string _tipo, float ancho, float dalto, float profundidad);
    bool FuncionamientoCorrecto();
    void EnchufarHeladera();
    bool VerificacionLuz();
    bool VerificacionTemperatura();

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
        return this->horaencufado;
    }

};

