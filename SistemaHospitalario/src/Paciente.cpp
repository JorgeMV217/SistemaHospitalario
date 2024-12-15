#include "Paciente.h"
#include <iostream>
#include <algorithm>
#include <fstream>

Paciente::Paciente(std::string nombre, int id, std::string fechaIngreso)
    : nombre(nombre), id(id), fechaIngreso(fechaIngreso) {
}

void Paciente::modificarDatos(std::string nuevoNombre) {
    nombre = nuevoNombre;
}

void Paciente::registrarHistorial(std::string historial) {
    historialClinico = historial;
}

void Paciente::altaPaciente(std::vector<Paciente>& pacientes, std::string nombre, int id, std::string fechaIngreso) {
    Paciente nuevoPaciente(nombre, id, fechaIngreso);
    pacientes.push_back(nuevoPaciente);
    guardarPacienteEnArchivo(nuevoPaciente);
}

void Paciente::bajaPaciente(std::vector<Paciente>& pacientes, int id) {
    pacientes.erase(std::remove_if(pacientes.begin(), pacientes.end(), [id](Paciente& p) { return p.id == id; }), pacientes.end());
}

void Paciente::listarPacientes(const std::vector<Paciente>& pacientes) {
    for (const auto& paciente : pacientes) {
        std::cout << "Nombre: " << paciente.nombre << ", ID: " << paciente.id << ", Fecha de Ingreso: " << paciente.fechaIngreso << std::endl;
    }
}

void Paciente::guardarPacienteEnArchivo(const Paciente& paciente) {
    std::ofstream archivo("data/pacientes.txt", std::ios::app); // Abre el archivo en modo "append" para añadir sin borrar
    if (archivo.is_open()) {
        archivo << paciente.nombre << "," << paciente.id << "," << paciente.fechaIngreso << "," << paciente.historialClinico << "\n";
        archivo.close();
    }
    else {
        std::cerr << "No se pudo abrir el archivo para guardar los datos del paciente.\n";
    }
}
