#include "glb.h"
#include "cCentro_De_Testeos.h"
#include "cLaboratorios.h"
#include"cPacientes.h"
int main() {
	// definicion de variables auxiliares 
	int i = 0, numPaciente = 0, fiebre = 0, tos = 0, mocos = 0, dolorDeCabeza = 0, dolorDeGarganta = 0, contactoEstrecho = 0;
	bool exit = false, ingresado = false;
	string nombre, apellido, dni, telefono;
	
	/* 
	definicion de los objetos; 
		- Se asginan 2 centros
		- A cada centro, se le asigna 1 laboratorio 
		- Pueden haber hasta 2 pacientes en c/ centro y 2 muestras en c/ laboratorio. Nos da un total de 8 pacientes 
	*/
	cCentroDeTesteos* centro = new cCentroDeTesteos[2]{ {"001", "Comuna 1", "Coronel Rosales"}, {"002", "Comuna 2", "Coronel Dorrego" } };
	cLaboratorios* laboratorio = new cLaboratorios[2]{ {"A01","Comuna A", "Laboratorios Obarro"}, {"B01", "Comuna B", "Laboratorios Ferrini"} };
	centro->asociarLaboratorio(&(*laboratorio)); centro[1].asociarLaboratorio(&laboratorio[1]);
	cPacientes* paciente = new cPacientes[8];
	
	// el usuario nos avisara cuando quiere dejar de ingresar pacientes
	while (exit == false) {
		
		// primer paso: ingresar el paciente al sistema
		cout << "El Gobierno de la Ciudad te da la bienvenida al sistema" << endl;
		cout << "Primeramente, le solicitaremos datos personales a fin de poder ingresarlo" << endl;
		cout << "Ingrese su nombre: " << endl;
		getline(cin, nombre); // lectura hasta salto de linea (sin delimitador se asigna '\n' por default)
		cout << "Ingrese su apellido: " << endl;
		getline(cin, apellido);
		cout << "Ingrese su DNI: " << endl;
		getline(cin, dni);
		cout << "Ingrese su telefono: " << endl;
		getline(cin, telefono);
		system("cls");
		cout << "Seguidamente, le haremos algunas preguntas sobre sus sintomas, y si fue contacto estrecho (responda 1 por verdadero y 0 por falso)" << endl;
		cout << "Padece fiebre?" << endl;
		cin >> fiebre;
		cout << "Padece tos?" << endl;
		cin >> tos;
		cout << "Padece mucosidad?" << endl;
		cin >> mocos;
		cout << "Padece dolor de cabeza?" << endl;
		cin >> dolorDeCabeza;
		cout << "Padece dolor de garganta?" << endl;
		cin >> dolorDeGarganta;
		cout << "Es contacto estrecho?" << endl;
		cin >> contactoEstrecho;

		// registro datos
		cPacientes* ingresoPaciente = new cPacientes(nombre, apellido, dni, telefono, fiebre, tos, mocos, dolorDeCabeza, dolorDeGarganta, contactoEstrecho);
		
		// segundo paso: darle alta al paciente en algun centro de testeos (en caso de presentar lugar)
		while (ingresado == false) {
			if (true == centro[i].altaPaciente(ingresoPaciente)) {

				// ingreso al paciente al array de objetos original
				paciente[numPaciente] = *ingresoPaciente;
				numPaciente++;
				ingresado = true;

			}

			// si no llegue al limite de centros, sigo buscando alguno
			else if (i < 2) i++;

			// si no encontro, termina el programa (no lo puedo ingresar)
			else exit = true;
		}

		// elimino la copia
		delete ingresoPaciente;
	}


	
	// elimino los objetos generados
	delete[] centro;
	delete[] laboratorio;
	delete[] paciente;
	return 0;
}