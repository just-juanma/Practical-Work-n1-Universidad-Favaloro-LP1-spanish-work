#include "glb.h"
#include "cCentro_De_Testeos.h"
#include "cLaboratorios.h"
#include"cPacientes.h"

int main() {

	// definicion de variables auxiliares 
	int i = 0, j = 0, k = 0, idx = 1;
	resultados resul = sinResultado;

	/*
	definicion de los objetos, segun acordamos con los integrantes de nuestro grupo (parte arbitraria del TP);
		- Se asginan 2 centros (pedido del enunciado en el TP)
		- A c/ centro, se le asigna 1 laboratorio DISTINTO (arbitrario)
		- A c/ centro, se le asignan 2 pacientes. Nos da un total de 4 pacientes
	*/
	int nPacientes = 0, nCentros = 2;
	cCentroDeTesteos* centro = new cCentroDeTesteos[2]{ {"001", "Comuna 1", "Coronel Rosales"}, {"002", "Comuna 2", "Coronel Dorrego"} };
	cLaboratorios* laboratorio = new cLaboratorios[2]{ {"A01","Comuna A", "Laboratorios Obarro"}, {"B01", "Comuna B", "Laboratorios Ferrini"} };
	for (i = 0; i < nCentros; i++)
		centro[i].asociarLaboratorio(&laboratorio[i]);
	i = 0;

	// Prototipos armados: elegir el que desee

	nPacientes = 4;
	cPacientes* paciente = new cPacientes[4]{ {"Bautista", "Gonzalez", "33489599", "1549382745", 1, 1, 1, 1, 1, 1},
	{"Juan Manuel", "Levy", "63584734","1530495837", 0,0,0,0,0,0},{"Adriel", "Farfaglia", "45878263", "15394857263", 1,0,1,0,1,0},
	{"Jose", "Gutierrez", "34958345", "1594857304", 1,1,0,0,0,0} };

	/*nPacientes = 3;
	cPacientes* paciente = new cPacientes[3]{ {"Bautista", "Gonzalez", "33489599", "1549382745", 1, 1, 1, 1, 1, 1},
	{"Juan Manuel", "Levy", "63584734","1530495837", 0,0,0,0,0,0},{"Adriel", "Farfaglia", "45878263", "15394857263", 1,0,1,0,1,0} };*/

	/*nPacientes = 2;
	cPacientes* paciente = new cPacientes[3]{ {"Bautista", "Gonzalez", "33489599", "1549382745", 1, 1, 1, 1, 1, 1},
	{"Juan Manuel", "Levy", "63584734","1530495837", 0,0,0,0,0,0} };*/

	/*nPacientes = 1;
	cPacientes* paciente = new cPacientes[3]{ {"Bautista", "Gonzalez", "33489599", "1549382745", 1, 1, 1, 1, 1, 1} };*/


	if (nPacientes == 3) i++;

	// primer paso: darle alta al paciente en algun centro de testeos (en caso de presentar lugar)
	if (nPacientes != 4) {
		for (j = 0; j < i + 1; j++)
			for (k = 0; k < nPacientes - idx + 2; k++) {
				centro[j].altaPaciente(&paciente[idx - 1]);
				idx++;
			}
	}
	else {
		for (j = 0; j < 2; j++)
			for (k = 0; k < 2; k++) {
				centro[j].altaPaciente(&paciente[idx - 1]);
				idx++;
			}
	}

	// segundo paso: determinar el resultado del hisopado
	for (i = 0; i < 2; i++) 
		centro[i].mandarTesteo();
	
	/* 
	   tercer paso : mostrar en pantalla las clases, solicitado por el enunciado del TP (lo hago antes de darle baja a los pacientes,
	   asi puedo imprimir sus datos desde el centro)
	*/
	cout << endl;
	for (i = 0; i < 2; i++) {
		centro[i].imprimir();
		cout << endl;
		laboratorio[i].imprimir();
		cout << endl;
	}
	for (j = 0; j < nPacientes; j++) {
		paciente[j].imprimir();
		cout << endl;
	}

	// cuarto paso: dar de baja a los pacientes
	for (i = 0; i < 2; i++)
		for (j = 0; j < 2; j++) {
			resul = paciente[j].getResul();
			centro[i].bajaPaciente(&resul);
		}

	// elimino los objetos generados
	delete[] centro;
	delete[] laboratorio;
	delete[] paciente;
	return 0;
}