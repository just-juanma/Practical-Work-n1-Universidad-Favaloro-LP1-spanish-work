#include "glb.h"
#include "cPacientes.h"
class cLaboratorios
{
	string ID_Laboratorio;
	string nombre;
	string comuna;
	cPacientes* paciente;
	bool completo;
public:
	cLaboratorios(string _ID_Laboratorio, string _nombre, string _comuna, cPacientes* _paciente, bool _completo);
	~cLaboratorios();
	bool recibir_muestra(cPacientes _paciente, bool _completo) {
		if (completo == false) return true;
		return false;
	}
	resultados analisis_de_muestra(int nSintomas) {
		if (nSintomas > 2) return positivo;
		return negativo;
	}
	void avisar_pacientes(resultados muestra, bool _completo) {
		if (muestra == positivo) 
			cout << "Hola, desde" << nombre << " te informamos que el resultado de la muestra fue: POSITIVO.\nRecuerde que debera realizar el aislamiento obligatorio de 10 dias como minimo" << endl;
		cout << "Hola, desde" << nombre << " te informamos que el resultado de la muestra fue: NEGATIVO." << endl;
		_completo = false;
	}
};

