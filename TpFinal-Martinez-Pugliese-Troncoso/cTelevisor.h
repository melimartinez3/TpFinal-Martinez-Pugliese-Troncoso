#pragma once
#include "cElectrodomesticos.h"

enum Televisor { smart, sonido, cable, control, display, cambiocanal, saltovoltaje };
typedef enum Televisor televisor;

class cTelevisor :
    public cElectrodomesticos
{
private:
    int volumen;
    bool fallas[7] = {false, false,false,false,false,false,false };
    static int canal;
    static int stockactual;
public:
    cTelevisor(int _volumen, string _marca, float _peso, float _precio, string _codigo, string _tipo, float ancho, float dalto, float profundidad);

    bool FuncionamientoIncorrecto();
    void EnchufarTelevisor();
    string to_string();
    void imprimir();
    ~cTelevisor();

    // declaracion de gets
    int get_volumen() {
        return this->volumen;
    }

   
};

