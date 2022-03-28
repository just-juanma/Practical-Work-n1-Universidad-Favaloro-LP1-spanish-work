#include "cLaboratorios.h"
cLaboratorios::cLaboratorios(string _ID_Laboratorio, string _nombre, string _comuna, cPacientes* _paciente, bool _completo) {
	this->ID_Laboratorio = _ID_Laboratorio;
	this->nombre = _nombre;
	this->comuna = _comuna;
	this->paciente = _paciente;
	this->completo = _completo;
}
cLaboratorios::~cLaboratorios() {}
bool cLaboratorios::recibir_muestra() {
	if (completo == false) return true;
	return false;
}
resultados cLaboratorios::analisis_de_muestra(int nSintomas) {
	if (nSintomas > 2) return positivo;
	return negativo;
}
void cLaboratorios::avisar_pacientes(resultados muestra) {
	if (muestra == positivo)
		cout << "Hola, desde" << nombre << " te informamos que el resultado de la muestra fue: POSITIVO.\nRecuerde que debera realizar el aislamiento obligatorio de 10 dias como minimo" << endl;
	cout << "Hola, desde" << nombre << " te informamos que el resultado de la muestra fue: NEGATIVO." << endl;
	completo = false;
}