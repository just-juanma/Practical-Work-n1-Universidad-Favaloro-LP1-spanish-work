#include "cCentro_de_testeos.h"
cCentro_de_testeos::cCentro_de_testeos(string _ID_Centro, string _comuna, string _nombre, string _completo, cPacientes* _pacientes, cLaboratorios* _laboratorios) {
	this->ID_Centro = _ID_Centro;
	this->comuna = _comuna;
	this->nombre = _nombre;
	this->completo = _completo;
	this->pacientes = _pacientes;
	this->laboratorios = _laboratorios;
}
cCentro_de_testeos::~cCentro_de_testeos() {}