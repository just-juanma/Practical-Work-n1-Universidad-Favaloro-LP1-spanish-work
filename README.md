# TP1-LaboProgra1

Explicacion de las relaciones del UML: 

cPacientes (agregacion) cCentroDeTesteos:

En un principio pensamos en establecer asociacion, ya que el paciente puede optar por ir al centro, o no. Sin embargo planteamos dos consideraciones:
1. Cada centro MINIMAMENTE tendra 1 paciente, siguiendo la logica de nuestro programa. Por lo tanto, no hay posibilidad de que no haya pacientes en el centro
2. Un paciente que no va al centro NO se consideraria paciente, por lo que se pierde la logica de la clase. Por eso se opta por COMPOSICION

cLaboratorios (agregacion) cCentroDeTesteos:

Se plantea al laboratorio como de utilidad para cualquier centro que se le asigne, y funcionara dependendiente a el. Por eso se opta por AGREGACION

Los laboratorios se van asociando de a uno (1) hacia un centro de testeos (1). Siempre se asignara 1 laboratorio a 1 centro, porque asi fue codeado el programa

Este trabajo fue valuado finalmente con 6.25/10
