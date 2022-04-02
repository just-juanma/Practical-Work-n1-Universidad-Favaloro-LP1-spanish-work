# TPS-LaboProgra1
Repositorio para los trabajos practicos de Laboratorio de Programacion I

TP 1:

Explicacion de las relaciones del UML: 

cPacientes (agregacion) cCentroDeTesteos:

En un principio pensamos en establecer asociacion, ya que el paciente puede optar por ir al centro, o no. Sin embargo planteamos dos consideraciones:
1. Cada centro MINIMAMENTE tendra 1 paciente, siguiendo la logica de nuestro programa. Por lo tanto, no hay posibilidad de que no haya pacientes en el centro
2. Un paciente que no va al centro NO se consideraria paciente, por lo que se pierde la logica de la clase

Sin embargo, proponer que la existencia del paciente depende del centro no tiene sentido. Por eso se opta por AGREGACION

cLaboratorios (agregacion) cCentroDeTesteos:

Se plantea al laboratorio como UNICAMENTE util para el centro asignado. Cada laboratorio tiene asignado un centro. Sin centro, el laboratorio carece de sentido, porque pierde su utilidad. Hemos elegido COMPOSICION

Los laboratorios se van asociando de a uno (1) hacia un centro de testeos (1). Siempre se asignara 1 laboratorio a 1 centro, porque asi fue codeado el programa
