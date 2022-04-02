#include "glb.h"
#include "cPacientes.h"
cPacientes::cPacientes(string _nombre, string _apellido, string _dni, string _telefono, int _fiebre, int _tos, int _mocos, int _contactoEstrecho,
int _dolorDeCabeza, int _dolorDeGarganta, resultados _resultado) {
	this->nombre = _nombre;
	this->apellido = _apellido;
	this->dni = _dni;
	this->telefono = _telefono; 
	this->fiebre = _fiebre; 
	this->tos = _tos; 
	this->mocos = _mocos; 
	this->contactoEstrecho = _contactoEstrecho;
	this->dolorDeCabeza = _dolorDeCabeza;
	this->dolorDeGarganta = _dolorDeGarganta;
}
cPacientes::~cPacientes() {}
string cPacientes::to_string() {
	stringstream stc;
	stc << "Nombre: " << nombre;
	stc << "\nApellido: " << apellido;
	stc << "\nDNI: " << dni;
	stc << "\nTelefono: " << telefono;
	stc << "\nFiebre: " << std::to_string(fiebre);
	stc << "\nTos: " << std::to_string(tos);
	stc << "\nMocos: " << std::to_string(mocos);
	stc << "\nContacto estrecho: " << std::to_string(contactoEstrecho);
	stc << "\nDolor de cabeza: " << std::to_string(dolorDeCabeza);
	stc << "\nDolor de garganta: " << std::to_string(dolorDeGarganta);
	stc << "\nResultado (0 = sinResultado, 1 = negativo, 2 = positivo): " << std::to_string(resultado);
	stc << endl;
	return stc.str();
}