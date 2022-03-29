#pragma once
#include "glb.h"
#include "cPacientes.h"
class cLaboratorios
{
	string IDLaboratorio;
	string nombre;
	string comuna;
	cPacientes* paciente;
	int completo;
public:
	cLaboratorios(string _IDLaboratorio, string _comuna, string _nombre, int _completo = 0);
	~cLaboratorios();
	bool recibirMuestra(cPacientes* _paciente);
	resultados analisisDeMuestra(int nSintomas);
	void avisarPacientes(resultados muestra);
	string getNombre() { return nombre; }
};

