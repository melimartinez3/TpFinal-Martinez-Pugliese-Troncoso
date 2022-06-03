#include "cTelevisor.h"

cTelevisor::cTelevisor(int _volumen, string _marca, float _peso, float _precio, string _codigo, string _tipo, float ancho, float dalto, float profundidad) :cElectrodomesticos(_marca, _peso, _precio, _codigo, _tipo, ancho, dalto, profundidad)
{
	this->volumen = _volumen;
}

int cTelevisor::stockactual = 6;
int cTelevisor::canal = 0;

bool cTelevisor::FuncionamientoIncorrecto() {
	for (int i = 0; i < 8; i++) {
		if (fallas[i] == true)
			return true;// no funciona correctamente
		else
			return false; // funciona como corresponde
	}
}
void cTelevisor::EnchufarTelevisor() {
	// consideramos que el televisor siempre va a encender
	int randomfallado = (rand() % 10) < 1;
	int random_carasteristicafallada = rand() % 6;// determinamos cada valor de falla segun el enum
	
	// switch para determinar que caracteristica fallo y modifarlo en el array
	switch (random_carasteristicafallada) {
	case smart: {fallas[smart] = true;
		           break;
	            }
	case sonido: {fallas[sonido] = true;
		break;
	}
	case cable: {fallas[cable] = true;
		break;
	}
	case control: {fallas[control] = true;
		break;
	}
	case display: {fallas[display] = true;
		break;
	}
	case cambiocanal: {fallas[cambiocanal] = true;
		break;
	}
	case saltovoltaje: {fallas[saltovoltaje] = true;
		break;
	}

	}


}

string cTelevisor::to_string() {
	string dato;
	string volumen_string, stockactual_string, precio_string;

	stringstream sstream;
	sstream << volumen;
	volumen_string = sstream.str();

	sstream << stockactual_string;
	stockactual_string = sstream.str();

	sstream << precio_string;
	precio_string = sstream.str();
	dato = "\nTelevisor: Marca: "+ marca+ " Precio: "+ precio_string+ " Codigo: "+ codigo+ " Tipo: "+ tipo+ " Volumen : " + volumen_string + " Stock actual : " + stockactual_string;
	return dato;
}
void cTelevisor::imprimir() {
	string dato = to_string();
	cout << dato;
}
cTelevisor::~cTelevisor()
{

}
