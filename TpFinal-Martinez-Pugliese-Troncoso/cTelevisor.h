#pragma once
#include "cElectrodomesticos.h"

class cTelevisor :
    public cElectrodomesticos
{
private:
    int volumen;
    bool veoprogramacion;
    static int stockactual;
    bool cable;
public:
    cTelevisor(int _volumen, bool _veoprogramacion, string _marca, float _peso, float _precio, string _codigo, string _tipo, float ancho, float dalto, float profundidad);
    // declarar los static
    bool FuncionamientoCorrecto();
    void Encender();
    void Apagar();
    void VerificarVolumen();
    void ConectarCable();
    ~cTelevisor();
    // declaracion de gets
    bool get_veoprogramacion() {
        return this->veoprogramacion;
    }
    int get_volumen() {
        return this->volumen;
    }
    // declaracion sets
    void set_volumen(int _volumen) {
        this->volumen = _volumen;
    }
};

