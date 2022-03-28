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
	bool recibir_muestra();
	resultados analisis_de_muestra(int nSintomas);
	void avisar_pacientes(resultados muestra);
};

