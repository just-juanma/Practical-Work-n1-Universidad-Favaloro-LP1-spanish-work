#pragma once
#include "glb.h"
#include "cPacientes.h"
class cLaboratorios
{
	string IDLaboratorio;
	string nombre;
	string comuna;
	cPacientes* paciente1;
	cPacientes* paciente2;
	int completo;
public:
	cLaboratorios(string _IDLaboratorio, string _comuna, string _nombre);
	~cLaboratorios();
	bool recibirMuestra(cPacientes* _paciente);
	resultados* analisisDeMuestra();
	void avisarPacientes(resultados* muestra);
	string getNombre() { return nombre; }
	string to_string();
	string imprimir();
};

