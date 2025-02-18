#include "Medico.h"
#include "Archivos.h"
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>

Medico::Medico()
	: nombre(""), id(0), especialidad("") {
}
Medico::Medico(std::string nombre, int id, std::string especialidad)
    : nombre(nombre), id(id), especialidad(especialidad) {
}

void Medico::altaMedico(std::vector<Medico>& medicos, std::string nombre, int id, std::string especialidad) {
    int nuevoID = Archivos::obtenerUltimoIDMedico() + 1;
    Medico nuevoMedico(nombre, nuevoID, especialidad);
    medicos.push_back(nuevoMedico);
	Archivos::guardarMedico(nuevoMedico);
}

void Medico::bajaMedico(std::vector<Medico>& medicos, int id) {
	Archivos::eliminarMedico(id);
    medicos.erase(std::remove_if(medicos.begin(), medicos.end(), [id](Medico& m) {
        return m.id == id;
        }), medicos.end());
}

void Medico::listarMedicosDesdeArchivo() {
    std::ifstream archivo("medicos.txt");
    if (archivo.is_open()) { 
        std::string linea; 
        while (std::getline(archivo, linea)) { 
            std::istringstream iss(linea);
            std::string id, nombre, especialidad;
            std::getline(iss, id, ',');
            std::getline(iss, nombre, ',');
            std::getline(iss, especialidad, ',');
            std::cout << "ID: " << id << ", Nombre: " << nombre << ", Especialidad: " << especialidad << std::endl;
        }
        archivo.close(); 
    }
    else {
        std::cerr << "No se pudo abrir el archivo para leer los datos de los médicos.\n";
    }
}

void Medico::guardarEnArchivo() const {
	Archivos::guardarMedico(*this);
}

void Medico::mostrarInformacion() const {
	std::cout << "Información del médico:\n";  
	std::cout << "ID: " << id << "\n";
	std::cout << "Nombre: " << nombre << "\n";
	std::cout << "Especialidad: " << especialidad << "\n";
}

std::string Medico::toString() const {
	std::stringstream ss;
	ss << id << "," << nombre << "," << especialidad;
	return ss.str();
}

void::Medico::fromString(const std::string& str) {
	std::istringstream iss(str);
	std::string idStr, nombre, especialidad;
	std::getline(iss, idStr, ',');
	std::getline(iss, nombre, ',');
	std::getline(iss, especialidad, ',');
	std::stringstream ss(idStr);
	ss >> id;
	this->nombre = nombre;
	this->especialidad = especialidad;
}
