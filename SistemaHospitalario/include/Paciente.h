#ifndef PACIENTE_H
#define PACIENTE_H

#include <string>
#include <vector>

class Paciente {
public:
    std::string nombre;
    int id;
    std::string fechaIngreso;
    std::string historialClinico;

    Paciente(std::string nombre, int id, std::string fechaIngreso);
    void modificarDatos(std::string nuevoNombre);
    void registrarHistorial(std::string historial);

    static void altaPaciente(std::vector<Paciente>& pacientes, std::string nombre, int id, std::string fechaIngreso);
    static void bajaPaciente(std::vector<Paciente>& pacientes, int id);
    static void listarPacientes(const std::vector<Paciente>& pacientes);
};

#endif

