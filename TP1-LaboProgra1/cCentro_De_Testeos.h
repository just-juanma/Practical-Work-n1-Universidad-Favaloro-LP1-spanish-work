#pragma once
#include "glb.h"
#include"cPacientes.h"
#include "cLaboratorios.h"
class cCentroDeTesteos
{
	bool completo;
	string IDCentro;
	string comuna;
	string nombre;
	cPacientes* paciente1;
	cPacientes* paciente2;
	cLaboratorios* laboratorio;
	string cadena;
public:
	cCentroDeTesteos(string _IDCentro, string _comuna, string _nombre);
	~cCentroDeTesteos();
	void asociarLaboratorio(cLaboratorios* _laboratorio);
	bool altaPaciente(cPacientes* _paciente);
	string getNombre() { return nombre; }
	bool mandarTesteo();
	void bajaPaciente();
	void imprimir(string texto);
	string to_string();
	string imprimir();

};


