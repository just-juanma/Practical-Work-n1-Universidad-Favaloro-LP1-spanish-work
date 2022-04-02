# TPS-LaboProgra1
Repositorio para los trabajos practicos de Laboratorio de Programacion I

TP 1:

Explicacion de las relaciones del UML: 

cPacientes (agregacion) cCentroDeTesteos:
- Si deja de existir el centro, no necesariamente deberia dejar de existir el paciente (no es composicion)
- Se requiere crear otras clases (en este caso el centro de testeos) a partir de la clase paciente (no es asociacion)
- Sin esta conexion la clase paciente deja de ser un paciente, pero sigue teniendo sentido (indice de que es agregacion)

Los pacientes se van enviando de a uno (1), pero los centros reciben hasta 2 pacientes (1..2). Si o si se van a enviar al menos un paciente y se recibira uno, porque asi fue codeado el programa.

cLaboratorios (agregacion) cCentroDeTesteos:
- Si deja de existir el centro, no necesariamente deberia dejar de existir el laboratorio (no es composicion)
- Se requiere crear otras clases (en este caso el centro de testeos) a partir de la clase laboratorio (no es asociacion)
- Se considera el centro de testeos como resultado de agregar un laboratorio, donde si surge una desconexion entre ambos, siguen teniendo sentido (indice de que es agregacion)

Los laboratorios se van asociando de a uno (1) hacia un centro de testeos (1). Siempre se asignara 1 laboratorio a 1 centro, porque asi fue codeado el programa
