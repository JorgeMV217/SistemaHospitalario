#include "Medico.h"
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>


Medico::Medico(std::string nombre, int id, std::string especialidad)
    : nombre(nombre), id(id), especialidad(especialidad) {
}

void Medico::altaMedico(std::vector<Medico>& medicos, std::string nombre, int id, std::string especialidad) {
    Medico nuevoMedico(nombre, id, especialidad);
    medicos.push_back(nuevoMedico);
    guardarMedicoEnArchivo(nuevoMedico);
}

void Medico::bajaMedico(std::vector<Medico>& medicos, int id) {
    medicos.erase(std::remove_if(medicos.begin(), medicos.end(), [id](Medico& m) { return m.id == id; }), medicos.end());
}

void Medico::listarMedicosDesdeArchivo() {
    std::ifstream archivo("../SistemaHospitalario/data/medicos.txt"); if (archivo.is_open()) { std::string linea; while (std::getline(archivo, linea)) { std::istringstream iss(linea); std::string nombre, id, especialidad; std::getline(iss, nombre, ','); std::getline(iss, id, ','); std::getline(iss, especialidad, ','); std::cout << "Nombre: " << nombre << ", ID: " << id << ", Especialidad: " << especialidad << std::endl; } archivo.close(); }
    else {
        std::cerr << "No se pudo abrir el archivo para leer los datos de los médicos.\n";
    }
}

void Medico::guardarMedicoEnArchivo(const Medico& medico) {
    std::ofstream archivo("medicos.txt", std::ios::app); // Abre el archivo en modo "append" para añadir sin borrar
    if (archivo.is_open()) {
        archivo << medico.nombre << "," << medico.id << "," << medico.especialidad << "\n";
        archivo.close();
    }
    else {
        std::cerr << "No se pudo abrir el archivo para guardar los datos del médico.\n";
    }
}
