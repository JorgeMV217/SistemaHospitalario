#include "Paciente.h"
#include "Archivos.h"
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>

Paciente::Paciente() : Persona(), fechaIngreso("") {}
Paciente::Paciente(std::string nombre, int id, std::string fechaIngreso)
    : Persona(nombre, id), fechaIngreso(fechaIngreso) {}


void Paciente::altaPaciente(std::vector<Paciente>& pacientes, std::string nombre, int id, std::string fechaIngreso) {
    int nuevoID = Archivos::obtenerUltimoIDPaciente() + 1;
    Paciente nuevoPaciente(nombre, nuevoID, fechaIngreso);
    pacientes.push_back(nuevoPaciente);
	Archivos::guardarPaciente(nuevoPaciente);
}

void Paciente::bajaPaciente(std::vector<Paciente>& pacientes, int id) {
	Archivos::eliminarPaciente(id);
    pacientes.erase(std::remove_if(pacientes.begin(), pacientes.end(), [id](Paciente& p) {
        return p.id == id;
        }), pacientes.end());
}


void Paciente::listarPacientesDesdeArchivo() {
	std::vector<Paciente> pacientes = Archivos::listarPacientes();
	for (const Paciente& paciente : pacientes) {
		paciente.mostrarInformacion();
	}
}

void Paciente::guardarEnArchivo() const {
	Archivos::guardarPaciente(*this);
}

void Paciente::mostrarInformacion() const {
	std::cout << "Información del paciente:\n";
	std::cout << "ID: " << id << "\n";
	std::cout << "Nombre: " << nombre << "\n";
	std::cout << "Fecha de Ingreso: " << fechaIngreso << "\n";
}
std::string Paciente::toString() const {
	std::stringstream ss;
	ss << id << "," << nombre << "," << fechaIngreso;
	return ss.str();
}
void Paciente::fromString(const std::string& str) {
	std::istringstream iss(str);
	std::string idStr, nombre, fechaIngreso;
	std::getline(iss, idStr, ',');
	std::getline(iss, nombre, ',');
	std::getline(iss, fechaIngreso, ',');
	std::stringstream ss(idStr);
	ss >> id;
	this->nombre = nombre;
	this->fechaIngreso = fechaIngreso;
}