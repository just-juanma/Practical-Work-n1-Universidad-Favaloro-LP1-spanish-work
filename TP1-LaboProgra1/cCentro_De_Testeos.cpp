#include "glb.h"
#include "cCentro_De_Testeos.h"
cCentroDeTesteos::cCentroDeTesteos(string _IDCentro, string _comuna, string _nombre, cPacientes* _paciente, cLaboratorios* _laboratorio, int _completo) {
	this->IDCentro = _IDCentro;
	this->comuna = _comuna;
	this->nombre = _nombre;
	this->completo = false;
}
cCentroDeTesteos::~cCentroDeTesteos() {}
void cCentroDeTesteos::asociarLaboratorio(cLaboratorios* _laboratorio) { this->laboratorio = _laboratorio; }
bool cCentroDeTesteos::altaPaciente(cPacientes* _paciente) {
	if (this->completo < 2) {
		this->completo++;
		this->paciente = _paciente;
		return true;
	}
	cout << "El paciente" << nombre << " no puede ser asignado a ningun centro de testeos\nRazon: estan los centros llenos" << endl;
	return this->completo = false;
}
bool cCentroDeTesteos::mandarTesteo() {
	if(true == laboratorio->recibirMuestra(paciente)) return true;
	return false;
}

void cCentroDeTesteos::asociarLaboratorio(cLaboratorios* _laboratorio) {
	this->laboratorio = _laboratorio;
}

bool cCentroDeTesteos::altaPaciente(cPacientes* _paciente) {
	string error = "ninguno";//incluir try and catch 
	if (this->completo != true) {
		this->paciente = _paciente;
	}//luego del catch se ajusta el error 
	if (error != "ninguno") {
		this->imprimir(error);
	}
}
void cCentroDeTesteos::bajaPaciente() {
	if (this->paciente->resultadoTesteo != sin_resultado) {
		this->paciente = NULL; // No tiene sentido, deber
	}
}