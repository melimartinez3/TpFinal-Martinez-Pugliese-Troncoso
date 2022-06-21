#pragma once
#include "cElectrodomesticos.h"

using namespace std;

enum Modo_Calentamiento{descongelar,calentar,cocinar};
typedef enum Modo_Calentamiento modo_cal;

enum Microondas{teclado,ventilador,puerta,calentamiento,enchufe,temporizador};
typedef enum Microondas microondas;

class cMicroondas :
    public cElectrodomesticos
{
private:
    bool luz;
    bool modocalentamiento;
    int potencia;
   const int potencia_max;
    static int stockactual;
    time_t horaencendido;
    bool fallas[6] = { false, false, false, false, false,false };
    bool fallas_calentamiento[3] = { false,false,false };

public:
    cMicroondas(int _potencia, string _marca, float _peso, float _precio, string _codigo, string _tipo, float _ancho, float _alto, float _profundidad);
    cMicroondas(const cMicroondas& heladera);
    bool FuncionamientoIncorrecto();
    void Modificar_fallas_calentamientos();
    void EnchufarMicroondas();
    void AjustePotenciaMaxima();
    bool ChequeoEncendidoPor1Min();
    string tostring();
    void imprimir();
    ~cMicroondas();
    
    bool get_luz() {
        return this->luz;
    }

    bool get_modocalentamiento() {
        return this->modocalentamiento;
    }

    int get_potenciamaxima() {
        return this->potencia;
    }

    void set_luz(bool x) {
        this->luz = x;
    }

    void set_horaenchufado(time_t hora) {
        this->horaencendido = hora;
    }

    void set_potencia(int pot) {
        this->potencia = pot;
    }

    int get_potenciamax()const {
        return this->potencia_max;
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

