#include "glb.h"
class cPacientes
{
	string nombre;
	string apellido;
	string dni;
	string telefono;
	bool fiebre;
	bool tos;
	bool mocos;
	bool contacto_estrecho;
	bool dolor_de_cabeza;
	bool dolor_de_garganta;
	resultados resultado_testeo;
public:
	cPacientes(string _telefono, bool _fiebre, bool _tos, bool _mocos, bool _contacto_estrecho, bool _dolor_de_cabeza, bool _dolor_de_garganta, int _resultado_Testeo); //resultado de testeo 0 significa que todavia no hay testeo
	~cPacientes();
	/*int getTelefono(); 
	bool getFiebre(); 
	bool getTos();
	bool getMocos();
	bool getContacto_estrecho();
	bool getDolor_de_cabeza();
	bool getDolor_de_gargnta();
	int getResultado_Testeo(); plantear a adri*/
};
