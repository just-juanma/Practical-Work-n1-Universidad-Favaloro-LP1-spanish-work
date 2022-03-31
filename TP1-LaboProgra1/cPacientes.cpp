#include "glb.h"
#include "cPacientes.h"
cPacientes::cPacientes(string _nombre, string _apellido, string _dni, string _telefono, int _fiebre, int _tos, int _mocos, int _contactoEstrecho,
int _dolorDeCabeza, int _dolorDeGarganta) {
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
int cPacientes::getSumaDolores() {
	return fiebre + tos + mocos + dolorDeCabeza + dolorDeGarganta;
}
string cPacientes::to_string() {
	stringstream stc;
	stc << "Nombre:" << nombre;
	stc << "Apellido:" << apellido;
	stc << "DNI:" << dni;
	stc << "Telefono:" << telefono;
	stc << "Fiebre:" << std::to_string(fiebre);
	stc << "Paciente 2:" << std::to_string(tos);
	stc << "Laboratorio:" << std::to_string(mocos);
	stc << "Laboratorio:" << std::to_string(contactoEstrecho);
	stc << "Laboratorio:" << std::to_string(dolorDeCabeza);
	stc << "Laboratorio:" << std::to_string(dolorDeGarganta);
	stc << endl;
	return stc.str();
}
string cPacientes::imprimir()
{
	cout << to_string();
}