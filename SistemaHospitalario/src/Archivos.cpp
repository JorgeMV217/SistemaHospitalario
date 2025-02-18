#include "Archivos.h"
#include <fstream>
#include <sstream>
#include <iostream>

// Paciente
void Archivos::guardarPaciente(const Paciente& paciente) {
    std::ofstream archivo("pacientes.txt", std::ios::app);
    if (archivo.is_open()) {
        archivo << paciente.toString() << "\n";
        archivo.close();
    }
    else {
        std::cerr << "No se pudo abrir el archivo para guardar los datos del paciente.\n";
    }
}

void Archivos::eliminarPaciente(int id) {
    std::ifstream archivoEntrada("pacientes.txt");
    std::ofstream archivoTemporal("pacientes_temp.txt");

    if (archivoEntrada.is_open() && archivoTemporal.is_open()) {
        std::string linea;
        while (std::getline(archivoEntrada, linea)) {
            std::istringstream iss(linea);
            std::string idStr;
            std::getline(iss, idStr, ',');
            int idPaciente = std::stoi(idStr);

            if (idPaciente != id) {
                archivoTemporal << linea << "\n";
            }
        }
        archivoEntrada.close();
        archivoTemporal.close();

        std::remove("pacientes.txt");
        std::rename("pacientes_temp.txt", "pacientes.txt");
    }
    else {
        std::cerr << "No se pudo abrir el archivo para modificar los datos del paciente.\n";
    }
}

std::vector<Paciente> Archivos::listarPacientes() {
    std::vector<Paciente> pacientes;
    std::ifstream archivo("pacientes.txt");
    if (archivo.is_open()) {
        std::string linea;
        while (std::getline(archivo, linea)) {
            Paciente paciente;
            paciente.fromString(linea);
            pacientes.push_back(paciente);
        }
        archivo.close();
    }
    else {
        std::cerr << "No se pudo abrir el archivo para leer los datos de los pacientes.\n";
    }
    return pacientes;
}

int Archivos::obtenerUltimoIDPaciente() {
    std::ifstream archivo("pacientes.txt");
    int ultimoID = 0;
    if (archivo.is_open()) {
        std::string linea;
        while (std::getline(archivo, linea)) {
            std::istringstream iss(linea);
            std::string idStr;
            std::getline(iss, idStr, ',');
            int idPaciente = std::stoi(idStr);
            ultimoID = idPaciente;
        }
        archivo.close();
    }
    else {
        std::cerr << "No se pudo abrir el archivo para leer los datos de los pacientes.\n";
    }
    return ultimoID;
}

// Medico
void Archivos::guardarMedico(const Medico& medico) {
    std::ofstream archivo("medicos.txt", std::ios::app);
    if (archivo.is_open()) {
        archivo << medico.toString() << "\n";
        archivo.close();
    }
    else {
        std::cerr << "No se pudo abrir el archivo para guardar los datos del medico.\n";
    }
}

void Archivos::eliminarMedico(int id) {
    std::ifstream archivoEntrada("medicos.txt");
    std::ofstream archivoTemporal("medicos_temp.txt");

    if (archivoEntrada.is_open() && archivoTemporal.is_open()) {
        std::string linea;
        while (std::getline(archivoEntrada, linea)) {
            std::istringstream iss(linea);
            std::string idStr;
            std::getline(iss, idStr, ',');
            int idMedico = std::stoi(idStr);

            if (idMedico != id) {
                archivoTemporal << linea << "\n";
            }
        }
        archivoEntrada.close();
        archivoTemporal.close();

        std::remove("medicos.txt");
        std::rename("medicos_temp.txt", "medicos.txt");
    }
    else {
        std::cerr << "No se pudo abrir el archivo para modificar los datos del medico.\n";
    }
}

std::vector<Medico> Archivos::listarMedicos() {
    std::vector<Medico> medicos;
    std::ifstream archivo("medicos.txt");
    if (archivo.is_open()) {
        std::string linea;
        while (std::getline(archivo, linea)) {
            Medico medico;
            medico.fromString(linea);
            medicos.push_back(medico);
        }
        archivo.close();
    }
    else {
        std::cerr << "No se pudo abrir el archivo para leer los datos de los medicos.\n";
    }
    return medicos;
}

int Archivos::obtenerUltimoIDMedico() {
    std::ifstream archivo("medicos.txt");
    int ultimoID = 0;
    if (archivo.is_open()) {
        std::string linea;
        while (std::getline(archivo, linea)) {
            std::istringstream iss(linea);
            std::string idStr;
            std::getline(iss, idStr, ',');
            int idMedico = std::stoi(idStr);
            ultimoID = idMedico;
        }
        archivo.close();
    }
    else {
        std::cerr << "No se pudo abrir el archivo para leer los datos de los medicos.\n";
    }
    return ultimoID;
}

// CitaMedica
void Archivos::guardarCita(const CitaMedica& cita) {
    std::ofstream archivo("citas.txt", std::ios::app);
    if (archivo.is_open()) {
        archivo << cita.toString() << "\n";
        archivo.close();
    }
    else {
        std::cerr << "No se pudo abrir el archivo para guardar los datos de la cita.\n";
    }
}

void Archivos::eliminarCita(int idCita) {
    std::ifstream archivoEntrada("citas.txt");
    std::ofstream archivoTemporal("citas_temp.txt");

    if (archivoEntrada.is_open() && archivoTemporal.is_open()) {
        std::string linea;
        while (std::getline(archivoEntrada, linea)) {
            std::istringstream iss(linea);
            std::string idStr;
            std::getline(iss, idStr, ',');
            int idCitaArchivo = std::stoi(idStr);

            if (idCitaArchivo != idCita) {
                archivoTemporal << linea << "\n";
            }
        }
        archivoEntrada.close();
        archivoTemporal.close();

        std::remove("citas.txt");
        std::rename("citas_temp.txt", "citas.txt");
    }
    else {
        std::cerr << "No se pudo abrir el archivo para modificar los datos de la cita.\n";
    }
}

std::vector<CitaMedica> Archivos::listarCitas() {
    std::vector<CitaMedica> citas;
    std::ifstream archivo("citas.txt");
    if (archivo.is_open()) {
        std::string linea;
        while (std::getline(archivo, linea)) {
            CitaMedica cita;
            cita.fromString(linea);
            citas.push_back(cita);
        }
        archivo.close();
    }
    else {
        std::cerr << "No se pudo abrir el archivo para leer los datos de las citas.\n";
    }
    return citas;
}

int Archivos::obtenerUltimoIDCita() {
    std::ifstream archivo("citas.txt");
    int ultimoID = 0;
    if (archivo.is_open()) {
        std::string linea;
        while (std::getline(archivo, linea)) {
            std::istringstream iss(linea);
            std::string idStr;
            std::getline(iss, idStr, ',');
            int idCita = std::stoi(idStr);
            ultimoID = idCita;
        }
        archivo.close();
    }
    else {
        std::cerr << "No se pudo abrir el archivo para leer los datos de las citas.\n";
    }
    return ultimoID;
}
