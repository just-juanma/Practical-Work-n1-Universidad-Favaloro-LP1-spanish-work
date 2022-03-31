#include "glb.h"
#include "cLaboratorios.h"
#include "cPacientes.h"
cLaboratorios::cLaboratorios(string _IDLaboratorio, string _comuna, string _nombre, int _completo) {
	this->IDLaboratorio = _IDLaboratorio;
	this->nombre = _nombre;
	this->comuna = _comuna;
}
cLaboratorios::~cLaboratorios() {}
bool cLaboratorios::recibirMuestra(cPacientes* _paciente1, cPacientes* _paciente2) {
	if (completo < 2) {
		completo++;
		if (paciente1 != NULL) this->paciente2 = _paciente2;
		else this->paciente1 = _paciente1;
		return true;
	}
	cout << "El paciente no puede ser asignado al laboratorio "<< nombre << "\nRazon: estan los laboratorios llenos" << endl;
	return false;
}
resultados cLaboratorios::analisisDeMuestra(int nSintomas) {
	if (nSintomas > 2) return positivo;
	return negativo;
}
void cLaboratorios::avisarPacientes(resultados muestra) {
	if (muestra == positivo)
		cout << "Hola, desde" << nombre << " te informamos que el resultado de la muestra fue: POSITIVO.\nRecuerde que debera realizar el aislamiento obligatorio de 10 dias como minimo" << endl;
	cout << "Hola, desde" << nombre << " te informamos que el resultado de la muestra fue: NEGATIVO." << endl;
	completo = false;
}

string cLaboratorios::toString() {
	return "Datos - ID" + IDLaboratorio + "Nombre:" + nombre + "Comuna:" + comuna;;
}