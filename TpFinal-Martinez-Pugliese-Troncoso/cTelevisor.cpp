#include "cTelevisor.h"

cTelevisor::cTelevisor(int _volumen, bool _veoprogramacion, string _marca, float _peso, float _precio, string _codigo, string _tipo, float ancho, float dalto, float profundidad) :cElectrodomesticos(_marca, _peso, _precio, _codigo, _tipo, ancho, dalto, profundidad)
{
	this->volumen = _volumen;
	this->veoprogramacion = _veoprogramacion;
	this->cable = true;
}

int cTelevisor::stockactual = 6;

cTelevisor::~cTelevisor()
{

}
