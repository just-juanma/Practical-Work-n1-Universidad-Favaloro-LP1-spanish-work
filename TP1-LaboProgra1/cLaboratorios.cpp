#include "glb.h"
#include "cLaboratorios.h"
#include "cPacientes.h"
cLaboratorios::cLaboratorios(string _IDLaboratorio, string _comuna, string _nombre) {
	this->IDLaboratorio = _IDLaboratorio;
	this->nombre = _nombre;
	this->comuna = _comuna;
	this->completo = 0;
	this->paciente1 = NULL;
	this->paciente2 = NULL;
}
cLaboratorios::~cLaboratorios() {}
bool cLaboratorios::recibirMuestra(cPacientes* _paciente) {
	if (completo < 2) {
		completo++;
		if (paciente1 != NULL) this->paciente2 = _paciente;
		else this->paciente1 = _paciente;
		return true;
	}
	cout << "El paciente no puede ser asignado al laboratorio " << nombre << "\nRazon: esta el laboratorio lleno" << endl;
	return false;
}
resultados* cLaboratorios::analisisDeMuestra() {
	resultados resultPaciente[2];
	if (paciente1 != NULL) {
		if (paciente1->getSumaSintomas() > 2) *resultPaciente = positivo;
		else *resultPaciente = negativo;

	}
	else *resultPaciente = sinResultado;
	if (paciente2 != NULL) {
		if (paciente2->getSumaSintomas() > 2) resultPaciente[1] = positivo;
		else resultPaciente[1] = negativo;
	}
	else resultPaciente[1] = sinResultado;
	return resultPaciente;
}
void cLaboratorios::avisarPacientes(resultados* muestra) {
	if (*muestra == positivo)
		cout << "Hola, desde " << nombre << " te informamos que el resultado de la muestra fue: POSITIVO.\nRecuerde que debera realizar el aislamiento obligatorio de 10 dias como minimo" << endl;
	else if(*muestra == negativo)
	cout << "Hola, desde" << nombre << " te informamos que el resultado de la muestra fue: NEGATIVO." << endl;
	completo = false;
}