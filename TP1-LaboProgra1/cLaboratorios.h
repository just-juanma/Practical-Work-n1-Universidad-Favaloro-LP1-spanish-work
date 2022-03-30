#pragma once
#include "glb.h"
#include "cPacientes.h"
class cLaboratorios
{
	string IDLaboratorio;
	string nombre;
	string comuna;
	cPacientes* paciente; /* considero que segun la consigna el puntero tienen que ser doble ya que 
						  la consiga mensiona que "Punteros a Pacientes 
						  que son null (...)" punteros en plural por lo que obiamente y tiene sentido, se debería trabajar con 
						  mas de uno. Los quiero mucho adri:) 
						  
						  PD no quise tocar esto directamente porque siento que el main explotaba todo (no me deja correrlo 
						  por el error MSB8020 que es un error de mi visual studio */
	int completo;
public:
	cLaboratorios(string _IDLaboratorio, string _comuna, string _nombre, int _completo = 0);
	~cLaboratorios();
	bool recibirMuestra(cPacientes* _paciente);
	resultados analisisDeMuestra(int nSintomas);
	void avisarPacientes(resultados muestra);
	string getNombre() { return nombre; }
};

