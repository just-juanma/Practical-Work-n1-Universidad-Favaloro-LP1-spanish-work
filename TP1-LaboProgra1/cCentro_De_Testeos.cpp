#include "cCentro_de_testeos.h"
using namespace std;
cCentro_de_testeos::cCentro_de_testeos(string _ID_Centro, string _comuna, string _nombre, string _completo) {
	this->ID_Centro = _ID_Centro;
	this->comuna = _comuna;
	this->nombre = _nombre;
	this->completo = _completo;
}