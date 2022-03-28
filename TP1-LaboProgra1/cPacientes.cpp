#include "cPacientes.h"
cPacientes::cPacientes(string _nombre, string _apellido, string _dni, string _telefono, bool _fiebre, bool _tos, bool _mocos, bool _contacto_estrecho, bool _dolor_de_cabeza, bool _dolor_de_garganta, resultados _resultado_testeo) {
	this->telefono = _telefono; 
	this->fiebre = _fiebre; 
	this->tos = _tos; 
	this->mocos = _mocos; 
	this->contacto_estrecho = _contacto_estrecho; 
	this->dolor_de_cabeza = _dolor_de_cabeza; 
	this->dolor_de_garganta = _dolor_de_garganta; 
	this->resultado_testeo = _resultado_testeo;
}
cPacientes::~cPacientes() {}
int cPacientes::getSumaDolores() {
	return fiebre + tos + mocos + dolor_de_cabeza + dolor_de_garganta + resultado_testeo;
}