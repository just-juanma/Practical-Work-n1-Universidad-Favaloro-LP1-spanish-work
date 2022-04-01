#include "glb.h"
#include "cCentro_De_Testeos.h"
#include "cLaboratorios.h"
#include"cPacientes.h"

/*
Si se escribe "cin.ignore(numeric_limits::max(),'\n');" después de la sentencia "cin" se descarta todo el flujo de entrada, incluida
la nueva línea. 
*/ 
void inputCleaning() { cin.ignore(numeric_limits<streamsize>::max(), '\n'); }
void  validarSintomas(int& var) { while (var != 0 && var != 1) { cout << "Ingrese 1(SI)/0(NO) segun posea o no el sintoma indicado" << endl; } }

int main() {

	// definicion de variables auxiliares 
	int i = 0, j = 0, k = 0, idx = 1, numPaciente = 0, consultarExit = 0, fiebre = 0, tos = 0, mocos = 0, dolorDeCabeza = 0, dolorDeGarganta = 0, contactoEstrecho = 0;
	bool exit = false, ingresado = false;
	string nombre, apellido, dni, telefono;
	resultados* resul = NULL;

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
	cout << "El Gobierno de la Ciudad te da la bienvenida al sistema de flujo de testeos de COVID" << endl;
	cout << "Primeramente, le solicitaremos datos personales a fin de poder ingresarlo" << endl;
	cout << "Seguidamente, le haremos algunas preguntas sobre sus sintomas, y si fue contacto estrecho (responda 1 por verdadero y 0 por falso)" << endl;
	
	// el bucle terminara cuando ya no se puedan ingresar pacientes, o bien el usuario decida terminar de ingresar
	while (exit == false) {
		i = 0;

		// primer paso: ingresar el paciente al sistema
		cout << "Ingrese su nombre: " << endl;
		getline(cin, nombre); // lectura hasta salto de linea (sin delimitador se asigna '\n' por default)
	/*	cout << "Ingrese su apellido: " << endl;
		getline(cin, apellido);
		cout << "Ingrese su DNI: " << endl;
		getline(cin, dni);
		cout << "Ingrese su telefono: " << endl;
		getline(cin, telefono);
		system("cls");
		
		cout << "Padece fiebre?" << endl;
		validarSintomas(fiebre);
		cout << "Padece tos?" << endl;
		validarSintomas(tos);
		cout << "Padece mucosidad?" << endl;
		validarSintomas(mocos);
		cout << "Padece dolor de cabeza?" << endl;
		validarSintomas(dolorDeCabeza);
		cout << "Padece dolor de garganta?" << endl;
		validarSintomas(dolorDeGarganta);
		cout << "Es contacto estrecho?" << endl;
		validarSintomas(contactoEstrecho);
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
		if (i != 2) {
			cout << "El paciente " << nombre << " fue asginado correctamente al centro de testeos " << centro[i].getNombre() << endl;
			numPaciente++;
		}
		else i--;
		delete ingresoPaciente;

		// si no alcance el tope de pacientes, pregunto por seguir agregando
		if (exit == false) {
			cout << "Desea seguir cargando pacientes al sistema? (1 por si, 0 por no)" << endl;
			cin >> consultarExit;
			if (consultarExit == 0) exit = true;
			inputCleaning();
			system("cls");
		}

	}

	/* tercer paso : enviar testeo. dado que en este punto del programa no habran mas de 4 pacientes, cada laboratorio no se podra llenar
	   y por ende este paso nunca va a ser propenso a error
	*/
	if (numPaciente != 4) {
		for (j = 0; j < i + 1; j++) 
			for (k = 0; k < numPaciente - idx + 2; k++) {
				centro[j].mandarTesteo(&paciente[idx - 1]);
				idx++;
			}
	}
	else {
		for (j = 0; j < i + 1; j++)
			for (k = 0; k < i + 1; k++) {
				centro[j].mandarTesteo(&paciente[idx - 1]);
				idx++;
			}
	}

	// cuarto paso: analizar las muestras de el/los laboratorio/s
	for (i = 0; i < 2; i++) {
		resul = laboratorio[i].analisisDeMuestra();
		for (j = 0; j < 2; j++)
			if (resul[j] != sinResultado) {
				// consultar ayudante porq despues de imprimir, se cambia el valor de resul (todos sus elementos)
				//cout << "Acaba de ser enviado un mensaje al telefono " << paciente[j].getTelefono() << " correspondiente al paciente de nombre " << paciente[j].getNombre() << endl;
				laboratorio[i].avisarPacientes(&resul[j]);
			}
	}
	
	// quinto y ultimo paso: darle baja a los pacientes
	for (i = 0; i < 2; i++)
		centro[i].bajaPaciente(&resul[i]);
	

	
	// elimino los objetos generados
	delete[] centro;
	delete[] laboratorio;
	delete[] paciente;
	return 0;
}