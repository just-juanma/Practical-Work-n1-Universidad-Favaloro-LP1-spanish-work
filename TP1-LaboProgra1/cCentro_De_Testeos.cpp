#include "glb.h"
#include "cCentro_De_Testeos.h"
cCentroDeTesteos::cCentroDeTesteos(string _IDCentro, string _comuna, string _nombre) {
	this->IDCentro = _IDCentro;
	this->comuna = _comuna;
	this->nombre = _nombre;
	this->completo = 0;
	this->paciente1 = NULL;
	this->paciente2 = NULL;
	this->laboratorio = NULL;
}
cCentroDeTesteos::~cCentroDeTesteos() {}
void cCentroDeTesteos::asociarLaboratorio(cLaboratorios* _laboratorio) { this->laboratorio = _laboratorio; }
bool cCentroDeTesteos::altaPaciente(cPacientes* _paciente) {
	if (completo < 2) {
		completo++;
		if (paciente1 != NULL) this->paciente2 = _paciente;
		else this->paciente1 = _paciente;
		return true;
	}
	cout << "El paciente no puede ser asignado al centro de testeos " << nombre << "\nRazon: esta el centro lleno" << endl;
	return false;
}
bool cCentroDeTesteos::mandarTesteo() {
	if(true == laboratorio->recibirMuestra(paciente1, paciente2)) return true;
	return false;
}
