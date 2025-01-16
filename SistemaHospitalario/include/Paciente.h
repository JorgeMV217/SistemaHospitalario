#ifndef PACIENTE_H
#define PACIENTE_H

#include <string>
#include <vector>

class Paciente {
public:
    std::string nombre;
    int id;
    std::string fechaIngreso;

    Paciente(std::string nombre, int id, std::string fechaIngreso);

    static void altaPaciente(std::vector<Paciente>& pacientes, std::string nombre, int id, std::string fechaIngreso);
    static void bajaPaciente(std::vector<Paciente>& pacientes, int id);
    static void listarPacientesDesdeArchivo();
    static void guardarPacienteEnArchivo(const Paciente& paciente);
    static int obtenerUltimoID();

};

#endif

