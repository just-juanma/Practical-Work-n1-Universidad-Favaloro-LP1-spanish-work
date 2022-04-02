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
void cCentroDeTesteos::altaPaciente(cPacientes* _paciente) {
	if (completo < 2) {
		completo++;
		if (paciente1 == NULL)
			this->paciente1 = _paciente;
		else this->paciente2 = _paciente;
	} else
	cout << "El paciente " << _paciente->getNombre() << " no puede ser asignado al centro de testeos " << nombre << "\nRazon: esta el centro lleno" << endl;
}
void cCentroDeTesteos::mandarTesteo() {
	if(paciente1 != NULL) laboratorio->recibirMuestra(paciente1);
	if(paciente2 != NULL) laboratorio->recibirMuestra(paciente2);
}
void cCentroDeTesteos::bajaPaciente(resultados* resultadoTesteo) {
	if (*resultadoTesteo != sinResultado && paciente1 != NULL)  this->paciente1 = NULL;
	else if (*resultadoTesteo != sinResultado && paciente2 != NULL) this->paciente2 = NULL;
}
string cCentroDeTesteos::to_string() {
	stringstream stc;
	stc << "ID: " << IDCentro; 
	stc << "\nComuna: " << comuna; 
	stc << "\nNombre: " << nombre; 
	stc << "\nCompleto: " << std::to_string(completo);
	if (paciente1 != NULL)
	stc << "\nPaciente 1: " << paciente1->getNombre(); 
	if(paciente2 != NULL)
	stc << "\nPaciente 2: " << paciente2->getNombre(); 
	stc << "\nLaboratorio: " << laboratorio->getNombre();
	stc << endl;
	return stc.str();
}