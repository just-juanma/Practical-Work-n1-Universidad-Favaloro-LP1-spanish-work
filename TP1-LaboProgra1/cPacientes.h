#pragma once
#include "glb.h"
class cPacientes
{
	int fiebre;
	int tos;
	int mocos;
	int contactoEstrecho;
	int dolorDeCabeza;
	int dolorDeGarganta;
	string nombre;
	string apellido;
	string dni;
	string telefono;
	resultados resultado;
public:
	cPacientes(string _nombre = "", string _apellido = "", string _dni = "", string _telefono = "", int _fiebre = 0, int _tos = 0, 
	int _mocos = 0, int _contactoEstrecho = 0, int _dolorDeCabeza = 0, int _dolorDeGarganta = 0, resultados _resultado = sinResultado);
	~cPacientes();
	int getSumaSintomas(){ return fiebre + tos + mocos + dolorDeCabeza + dolorDeGarganta; }
	string getNombre() { return nombre; }
	string getTelefono() { return telefono; }
	resultados getResul() { return resultado; }
	void setResul(resultados _resultado) { this->resultado = _resultado; }
	string to_string();
	void imprimir() { cout << to_string(); }
};
