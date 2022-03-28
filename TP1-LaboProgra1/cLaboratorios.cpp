#include "cLaboratorios.h"
cLaboratorios::cLaboratorios(string _ID_Laboratorio, string _nombre, string _comuna, cPacientes* _pacientes, bool _completo) {
	this->ID_Laboratorio = _ID_Laboratorio;
	this->nombre = _nombre;
	this->comuna = _comuna;
	this->pacientes = _pacientes;
	this->completo = _completo;
}
cLaboratorios::~cLaboratorios() {}