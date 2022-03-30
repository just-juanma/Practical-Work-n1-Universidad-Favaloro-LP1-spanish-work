#include "glb.h"
#include "cCentro_De_Testeos.h"
#include "cLaboratorios.h"
#include"cPacientes.h"
void inputCleaning() { cin.ignore(numeric_limits<streamsize>::max(), '\n'); }
int main() {
	// definicion de variables auxiliares 
	int i = 0, j = 0, numPaciente = 0, consultarExit = 0, fiebre = 0, tos = 0, mocos = 0, dolorDeCabeza = 0, dolorDeGarganta = 0, contactoEstrecho = 0;
	bool exit = false, ingresado = false;
	string nombre, apellido, dni, telefono;
	
	/* 
	definicion de los objetos; 
		- Se asginan 2 centros
		- A c/ centro, se le asigna 1 laboratorio 
		- A c/ centro, se le asignan 2 pacientes. Nos da un total de 4 pacientes
	*/
	cCentroDeTesteos* centro = new cCentroDeTesteos[2]{ {"001", "Comuna 1", "Coronel Rosales"}, {"002", "Comuna 2", "Coronel Dorrego"} };
	cLaboratorios* laboratorio = new cLaboratorios[2]{ {"A01","Comuna A", "Laboratorios Obarro"}, {"B01", "Comuna B", "Laboratorios Ferrini"} };
	for (i = 0; i < 2; i++)
		centro[i].asociarLaboratorio(&laboratorio[i]);
	cPacientes* paciente = new cPacientes[4];

	// presentacion
	cout << "El Gobierno de la Ciudad te da la bienvenida al sistema" << endl;
	cout << "Primeramente, le solicitaremos datos personales a fin de poder ingresarlo" << endl;
	cout << "Seguidamente, le haremos algunas preguntas sobre sus sintomas, y si fue contacto estrecho (responda 1 por verdadero y 0 por falso)" << endl;
	
	// el bucle terminara cuando ya no se puedan ingresar pacientes, o bien el usuario decida terminar de ingresar
	while (exit == false) {
		i = 0;
		
		
		// primer paso: ingresar el paciente al sistema
		cout << "Ingrese su nombre: " << endl;
		getline(cin, nombre); // lectura hasta salto de linea (sin delimitador se asigna '\n' por default)
		cout << "Ingrese su apellido: " << endl;
		getline(cin, apellido);
		cout << "Ingrese su DNI: " << endl;
		getline(cin, dni);
		cout << "Ingrese su telefono: " << endl;
		getline(cin, telefono);
		system("cls");
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
		system("cls"); 

		// registro datos
		cPacientes* ingresoPaciente = new cPacientes(nombre, apellido, dni, telefono, fiebre, tos, mocos, dolorDeCabeza, dolorDeGarganta, contactoEstrecho);
		if (numPaciente == 4) exit = true;
		else paciente[numPaciente] = *ingresoPaciente;

		// segundo paso: darle alta al paciente en algun centro de testeos (en caso de presentar lugar)
		while (false == centro[i].altaPaciente(&paciente[numPaciente])) {
			i++;
			if (i == 2) break;
		}
		if(i != 2)
		cout << "El paciente " << nombre << " fue asginado correctamente al centro de testeos " << centro[i].getNombre() << endl;
		delete ingresoPaciente;
		numPaciente++;

		// si no alcance el tope de pacientes, pregunto por seguir agregando
		if (exit == false) {
			cout << "Desea seguir cargando pacientes al sistema? (1 por si, 0 por no)" << endl;
			cin >> consultarExit;
			if (consultarExit == 0) exit = true;
		}
		inputCleaning();
		system("cls");

	}
	for (i = 0; i < numPaciente; i++) {
		centro[i].mandarTesteo();
	}
	i = 0;
	

	
	// elimino los objetos generados
	delete[] centro;
	delete[] laboratorio;
	delete[] paciente;
	return 0;
}