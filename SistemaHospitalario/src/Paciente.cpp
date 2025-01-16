#include "Paciente.h"
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>


Paciente::Paciente(std::string nombre, int id, std::string fechaIngreso)
    : nombre(nombre), id(id), fechaIngreso(fechaIngreso) {
}

void Paciente::modificarDatos(std::string nuevoNombre) {
    nombre = nuevoNombre;
}


void Paciente::altaPaciente(std::vector<Paciente>& pacientes, std::string nombre, int id, std::string fechaIngreso) {
    int nuevoID = obtenerUltimoID() + 1;
    Paciente nuevoPaciente(nombre, nuevoID, fechaIngreso);
    pacientes.push_back(nuevoPaciente);
    guardarPacienteEnArchivo(nuevoPaciente);
}

void Paciente::bajaPaciente(std::vector<Paciente>& pacientes, int id) {
    pacientes.erase(std::remove_if(pacientes.begin(), pacientes.end(), [id](Paciente& p) {
        return p.id == id;
        }), pacientes.end());

    std::ifstream archivoEntrada("pacientes.txt");
    std::ofstream archivoTemporal("pacientes_temp.txt");

    if (archivoEntrada.is_open() && archivoTemporal.is_open()) {
        std::string linea;
        while (std::getline(archivoEntrada, linea)) {
            std::istringstream iss(linea);
            std::string pacienteId;

            std::getline(iss, pacienteId, ',');
            
            int idPaciente;
            std::stringstream ss(pacienteId);
            ss >> idPaciente;
            if (idPaciente != id) { 
                archivoTemporal << linea << "\n"; 
            }

        }
        archivoEntrada.close();
        archivoTemporal.close();

        std::remove("pacientes.txt");
        std::rename("pacientes_temp.txt","pacientes.txt");
    }
    else {
        std::cerr << "No se pudo abrir el archivo para modificar los datos de los pacientes.\n";
    }
   

}

void Paciente::listarPacientesDesdeArchivo() {
    std::ifstream archivo("pacientes.txt");
    if (archivo.is_open()) { 
        std::string linea;
        while (std::getline(archivo, linea)){
            std::istringstream iss(linea); 
            std::string id, nombre, fechaIngreso;
            std::getline(iss, id, ','); 
            std::getline(iss, nombre, ','); 
            std::getline(iss, fechaIngreso, ','); 
            std::cout << "ID: " << id << ", Nombre: " << nombre << ", Fecha de Ingreso: " << fechaIngreso << std::endl; } archivo.close();
    }
    else { std::cerr << "No se pudo abrir el archivo para leer los datos de los pacientes.\n"; }
}

void Paciente::guardarPacienteEnArchivo(const Paciente& paciente) {
    std::ofstream archivo("pacientes.txt", std::ios::app); // Abre el archivo en modo "append" para añadir sin borrar
    if (archivo.is_open()) {
        archivo << paciente.id << "," << paciente.nombre << "," << paciente.fechaIngreso << "\n";
        archivo.close();
    }
    else {
        std::cerr << "No se pudo abrir el archivo para guardar los datos del paciente.\n";
    }
}

int Paciente::obtenerUltimoID() {
    std::ifstream archivo("pacientes.txt");
    int ultimoID = 0;
    if (archivo.is_open()) {
        std::string linea;
        while (std::getline(archivo, linea)) {
            std::istringstream iss(linea);
            std::string idStr;
            std::getline(iss, idStr, ',');

            int idPaciente;
            std::stringstream ss(idStr);
            ss >> idPaciente;
            ultimoID = idPaciente;

        }
        archivo.close();
    }
    return ultimoID;
}

