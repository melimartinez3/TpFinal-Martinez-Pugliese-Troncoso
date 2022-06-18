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
     int canal;
    static int stockactual;
public:
    cTelevisor(int _volumen, string _marca, float _peso, float _precio, string _codigo, string _tipo, float ancho, float dalto, float profundidad);
    cTelevisor(const cTelevisor& televisar);
    bool FuncionamientoIncorrecto();
    bool Falla_EncenderTelevisor();
    string to_string();
    void imprimir();
    ~cTelevisor();

    // declaracion de gets
    int get_volumen() {
        return this->volumen;
    }
   
    static void set_stock(int stock)
    {
        stockactual = stock;
    }

    static int get_stock()
    {
        return stockactual;
    }

};

