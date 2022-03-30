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
	cPacientes* paciente;
	cLaboratorios* laboratorio;
public:
	cCentroDeTesteos(string _IDCentro, string _comuna, string _nombre, cPacientes* _paciente = NULL, cLaboratorios* _laboratorio = NULL, int _completo = 0);
	~cCentroDeTesteos();
	void asociarLaboratorio(cLaboratorios* _laboratorio);
	bool altaPaciente(cPacientes* _paciente);
	bool mandarTesteo();
	void bajaPaciente();
	void imprimir(string texto);
};


