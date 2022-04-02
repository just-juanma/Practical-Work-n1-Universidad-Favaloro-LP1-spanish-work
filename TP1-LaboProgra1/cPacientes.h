#pragma once
#include "glb.h"
class cPacientes
{
public:
	cPacientes(string _nombre = "", string _apellido = "", string _dni = "", string _telefono = "", int _fiebre = 0, int _tos = 0, 
	int _mocos = 0, int _contactoEstrecho = 0, int _dolorDeCabeza = 0, int _dolorDeGarganta = 0, resultados _resultado = sinResultado);
	~cPacientes();
	int getSumaSintomas(){ return fiebre + tos + mocos + dolorDeCabeza + dolorDeGarganta; }
	string getNombre() { return nombre; }
	resultados getResul() { return resultado; }
	void setResul(resultados _resultado) { this->resultado = _resultado; }
	string to_string();
	void imprimir() { cout << to_string(); }
private:
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
	 /*
		se decidio agregar este atributo para poder setear el resultado de cada paciente, y de esa forma despues poder
		darle de baja segun el mismo
	 */
	resultados resultado;
};
