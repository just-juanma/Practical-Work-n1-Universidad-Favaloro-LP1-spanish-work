#include "cCentro_de_testeos.h"
cCentro_de_testeos::cCentro_de_testeos(string _ID_Centro, string _comuna, string _nombre, bool _completo, cPacientes* _pacientes, cLaboratorios* _laboratorios) {
	this->ID_Centro = _ID_Centro;
	this->comuna = _comuna;
	this->nombre = _nombre;
	this->completo = _completo;
	this->paciente = _pacientes;
	this->laboratorio = _laboratorios;
}
cCentro_de_testeos::~cCentro_de_testeos() {}
void cCentro_de_testeos::asociar_laboratorio(cLaboratorios* _laboratorio) { this->laboratorio = _laboratorio; }
bool cCentro_de_testeos::alta_paciente() {
	if (completo == false) {
		completo = true;
		return true;
	}
	return false;
}
