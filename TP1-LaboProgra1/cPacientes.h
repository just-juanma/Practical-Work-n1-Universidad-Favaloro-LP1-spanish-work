#pragma once
#include <string>
#include <iostream>
using namespace std;
enum resultados {sinresultado, negativo, positivo};
class cPacientes
{
public:
	cPacientes(int telefono,bool fiebre,bool tos,bool mocos,bool contacto_estrecho,bool dolor_de_cabeza,bool dolor_de_garganta,int resultado_Testeo);//resultaod de testeo 0 significa que todavia no hay testeo
	~cPacientes();
	int gettelefono(); 
	bool getfiebre(); 
	bool gettos();
	bool getmocos();
	bool getcontacto_estrecho();
	bool getdolor_de_cabeza();
	bool getdolor_de_gargnta();
	int getResultado_Testeo();
private:
	string nombre;
	string apellido;
	string dni;
	int telefono;
	bool fiebre;
	bool tos;
	bool mocos;
	bool contacto_estrecho;
	bool dolor_de_cabeza;
	bool dolor_de_garganta;
	int resultado_Testeo;
};
