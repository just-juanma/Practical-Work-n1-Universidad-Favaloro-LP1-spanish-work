#pragma once
#include "glb.h"
#include"cPacientes.h"
#include "cLaboratorios.h"
class cCentroDeTesteos
{
	int completo;
	string IDCentro;
	string comuna;
	string nombre;
	cPacientes* paciente1;
	cPacientes* paciente2;
	cLaboratorios* laboratorio;
public:
	cCentroDeTesteos(string _IDCentro, string _comuna, string _nombre);
	~cCentroDeTesteos();
	void asociarLaboratorio(cLaboratorios* _laboratorio);
	bool altaPaciente(cPacientes* _paciente);
	string getNombre() { return nombre; }
	bool mandarTesteo();
	void bajaPaciente();
};

