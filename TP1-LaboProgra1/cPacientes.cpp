#include "cPacientes.h"

cPacientes::cPacientes(int _telefono, bool _fiebre, bool _tos, bool _mocos, bool _contacto_estrecho, bool _dolor_de_cabeza, bool _dolor_de_garganta, int _resultado){
	this->telefono = _telefono; 
	this->fiebre = _fiebre; 
	this->tos = _tos; 
	this->mocos = _mocos; 
	this->contacto_estrecho = _contacto_estrecho; 
	this->dolor_de_cabeza = _dolor_de_cabeza; 
	this->dolor_de_garganta = _dolor_de_garganta; 
	this->dolor_de_garganta = sinresultado;
}

cPacientes::~cPacientes()
{
}