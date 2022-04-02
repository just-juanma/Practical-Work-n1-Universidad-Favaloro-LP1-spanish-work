#pragma once
#include "glb.h"
#include"cPacientes.h"
#include "cLaboratorios.h"
class cCentroDeTesteos
{
public:
	cCentroDeTesteos(string _IDCentro, string _comuna, string _nombre);
	~cCentroDeTesteos();
	void asociarLaboratorio(cLaboratorios* _laboratorio) { this->laboratorio = _laboratorio; }
	void desasociarLaboratorio(cLaboratorios* _laboratorio) { this->laboratorio = NULL; }
	void altaPaciente(cPacientes* _paciente);
	void mandarTesteo();
	string getNombre() { return nombre; }
	int getCompleto() { return completo; }
	string to_string();
	void imprimir() { cout << to_string(); }
	void bajaPaciente(resultados* resultadoTesteo);
private:
	int completo;
	string IDCentro;
	string comuna;
	string nombre;
	cLaboratorios* laboratorio;
	cPacientes* paciente1;
	cPacientes* paciente2;
};


