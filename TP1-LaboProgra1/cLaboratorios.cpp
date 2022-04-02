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
void cLaboratorios::recibirMuestra(cPacientes* _paciente) {
	if (completo < 2) {
		completo++;
		if (paciente1 != NULL) this->paciente2 = _paciente;
		else this->paciente1 = _paciente;
		analisisDeMuestra(_paciente);
	} else
	cout << "El paciente " << _paciente->getNombre() << " no puede ser asignado al laboratorio " << nombre << "\nRazon: esta el laboratorio lleno" << endl;
}
void cLaboratorios::analisisDeMuestra(cPacientes* _paciente) {
	resultados resul;
	if (_paciente->getSumaSintomas() > 2) resul = positivo;
	else resul = negativo;
	avisarPacientes(resul, _paciente);
}
void cLaboratorios::avisarPacientes(resultados muestra, cPacientes* _paciente) {
	if (muestra == positivo) {
		cout << "Hola " << _paciente->getNombre() << ", desde " << nombre << " te informamos que el resultado de la muestra fue : POSITIVO.\nRecuerde que debera realizar el aislamiento obligatorio de 10 dias como minimo" << endl;
		_paciente->setResul(muestra);
	}
	else if (muestra == negativo) {
		cout << "Hola " << _paciente->getNombre() << ", desde " << nombre << " te informamos que el resultado de la muestra fue: NEGATIVO." << endl;
		_paciente->setResul(muestra);
	}
}
string cLaboratorios::to_string() {
	stringstream stc;
	stc << "ID: " << IDLaboratorio; 
	stc << "\nNombre: " << nombre; 
	stc << "\nComuna: " << comuna;
	stc << endl;
	return stc.str();
}