#include "glb.h"
class cPacientes
{
	string nombre;
	string apellido;
	string dni;
	string telefono;
	int fiebre;
	int tos;
	int mocos;
	bool contacto_estrecho;
	int dolor_de_cabeza;
	int dolor_de_garganta;
	resultados resultado_testeo;
public:
	cPacientes(string _nombre, string _apellido, string _dni, string _telefono, bool _fiebre, bool _tos, bool _mocos, bool _contacto_estrecho, bool _dolor_de_cabeza, bool _dolor_de_garganta, resultados _resultado_testeo); //resultado de testeo 0 significa que todavia no hay testeo
	~cPacientes();
	int getSumaDolores();
};
