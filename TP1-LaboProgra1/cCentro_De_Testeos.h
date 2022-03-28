#include "glb.h"
#include "cPacientes.h"
#include "cLaboratorios.h"
class cCentro_de_testeos
{
	string ID_Centro;
	string comuna;
	string nombre;
	bool completo;
	cPacientes* paciente;
	cLaboratorios* laboratorio;
public:
	cCentro_de_testeos(string _ID_Centro, string _comuna, string _nombre, bool _completo, cPacientes* _paciente, cLaboratorios* _laboratorio); // agregar los atributos comentados
	~cCentro_de_testeos();
	void asociar_laboratorio(cLaboratorios* laboratorio);
	bool alta_paciente();
	bool mandar_testeo(cPacientes _paciente);
	void baja_paciente();
};

