#pragma once
#include "cElectrodomesticos.h"

enum Heladera{ luzinterior, termostato, obstruccionhielo, sellomagnetico, saltodevoltaje, perdidarefrigerante};
typedef enum Heladera heladera;

class cHeladera :
    public cElectrodomesticos
{
private:
    int temperatura;// esta es la temp ideal que tendria que tener la heladera
    static int stockactual;
    bool fallas[6] = { false, false, false, false, false,false };
    time_t horaenchufado;
public:
    cHeladera(int _temperatura, string _marca, float _peso, float _precio, string _codigo, string _tipo, float _ancho, float _alto, float _profundidad);
    bool FuncionamientoInorrecto();
    void EnchufarHeladera();
    string to_string();
    void imprimir();
    //declarar static
    ~cHeladera();

    //declaracion de gets
    int get_temperatura() {
        return this->temperatura;
    }
    time_t get_hora() {
        return this->horaenchufado;
    }
    // declaracion setters
    void set_horaenchufado(time_t _horaenchufado)
    {
        this->horaenchufado = _horaenchufado;
    }
};

