#pragma once
#include <iostream>
#include <string>
using namespace std;
class cCentro_de_testeos
{
private:
	string ID_Centro;
	string comuna;
	string nombre;
	string completo;
	//pacientes* paciente;
	//laboratorios* laboratorio;
public:
	cCentro_de_testeos(string _ID_Centro, string _comuna, string _nombre, string _completo); // agregar los atributos comentados
	~cCentro_de_testeos();
	//void asociar_laboratorio(laboratorios _laboratorio)
	//void alta_paciente(pacientes _paciente)
	void mandar_testeo();
	void baja_paciente();
};

