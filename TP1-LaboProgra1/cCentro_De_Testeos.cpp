#include "glb.h"
#include "cCentro_De_Testeos.h"
cCentroDeTesteos::cCentroDeTesteos(string _IDCentro, string _comuna, string _nombre) {
	this->IDCentro = _IDCentro;
	this->comuna = _comuna;
	this->nombre = _nombre;
	this->completo = false;
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

void cCentroDeTesteos::bajaPaciente() {
	if (this->paciente1->resultadoTesteo != sin_resultado) {
		this->paciente1 = NULL; // No tiene sentido, deber
	}
	if (this->paciente2->resultadoTesteo != sin_resultado) {
		this->paciente2 = NULL; // No tiene sentido, deber
	}
}

string cCentroDeTesteos::to_string() {
	stringstream stc;
	stc << "ID:" << IDCentro; 
	stc << "Comuna:" << comuna; 
	stc << "Nombre:" << nombre; 
	stc << "Completo:" << std::to_string(completo); 
	stc << "Paciente 1:" << paciente1->getNombre(); 
	stc << "Paciente 2:" << paciente2->getNombre(); 
	stc << "Laboratorio:" << laboratorio->getNombre();
	stc << endl;
	return stc.str();
}
string cCentroDeTesteos::imprimir()
{
	cout << to_string();
}