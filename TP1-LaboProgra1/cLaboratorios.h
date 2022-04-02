#pragma once
#include "glb.h"
#include "cPacientes.h"
class cLaboratorios
{
public:
	cLaboratorios(string _IDLaboratorio, string _comuna, string _nombre);
	~cLaboratorios();
	void recibirMuestra(cPacientes* _paciente);
	void analisisDeMuestra(cPacientes* _paciente);
	void avisarPacientes(resultados muestra, cPacientes* _paciente);
	string getNombre() { return nombre; }
	string to_string();
	void imprimir() { cout << to_string(); }
private:
	int completo;
	string IDLaboratorio;
	string nombre;
	string comuna;
	cPacientes* paciente1;
	cPacientes* paciente2;
};

