#pragma once
#include "glb.h"
class cPacientes
{
	string nombre;
	string apellido;
	string dni;
	string telefono;
	int fiebre;
	int tos;
	int mocos;
	int contactoEstrecho;
	int dolorDeCabeza;
	int dolorDeGarganta;
public:
	cPacientes(string _nombre = "", string _apellido = "", string _dni = "", string _telefono = "", int _fiebre = 0, int _tos = 0, 
	int _mocos = 0, int _contactoEstrecho = 0, int _dolorDeCabeza = 0, int _dolorDeGarganta = 0);
	~cPacientes();
	string getNombre() { return nombre; }
	string getTelefono() { return telefono; }
	int getSumaSintomas();
	
};
