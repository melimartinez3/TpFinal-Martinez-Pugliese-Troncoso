#pragma once
#include "cElectrodomesticos.h"

using namespace std;

class cMicroondas :
    public cElectrodomesticos
{
private:
    bool luz;
    bool modocalentamiento;
    int potencia;
    static int stockactual;
    time_t horaencendidio;
public:
    cMicroondas(int _potencia, string _marca, float _peso, float _precio, string _codigo, string _tipo, float _ancho, float _alto, float _profundidad);
    bool FuncionamientoCorrecto();
    void AbrirPuerta();
    void CerrarPuerta();
    void PotenciaMaxima();
    void ChequeoEncendidoPor1Min();
    ~cMicroondas();
    
    bool ge_tluz() {
        return this->luz;
    }
    bool get_modocalentamiento() {
        return this->modocalentamiento;
    }
    int get_potenciamaxima() {
        return this->potencia;
    }
};

