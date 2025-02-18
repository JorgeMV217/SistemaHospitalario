#include "Cita.h"
#include "Archivos.h"
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>

CitaMedica::CitaMedica()
	: idCita(0), idPaciente(0), idMedico(0), fecha(""), esUrgente(false) {
}
CitaMedica::CitaMedica(int idCita, int idPaciente, int idMedico, std::string fecha, bool esUrgente)
    : idCita(idCita), idPaciente(idPaciente), idMedico(idMedico), fecha(fecha), esUrgente(esUrgente) {
}

void CitaMedica::asignarCita(std::vector<CitaMedica>& citas, int idCita, int idPaciente, int idMedico, std::string fecha, bool esUrgente) {
    int nuevoIDCita = Archivos::obtenerUltimoIDCita() + 1;
    CitaMedica nuevaCita(nuevoIDCita, idPaciente, idMedico, fecha, esUrgente);
    citas.push_back(nuevaCita);
	Archivos::guardarCita(nuevaCita);
}

void CitaMedica::cancelarCita(std::vector<CitaMedica>& citas, int idCita) {
	Archivos::eliminarCita(idCita);
    citas.erase(std::remove_if(citas.begin(), citas.end(), [idCita](CitaMedica& c) {
        return c.idCita == idCita;
        }), citas.end());
    
}

void CitaMedica::listarCitasDesdeArchivo() {
	std::vector<CitaMedica> citas = Archivos::listarCitas();
	for (const CitaMedica& cita : citas) {
		cita.mostrarInformacionCita(cita.idCita);
	}
}

void CitaMedica::guardarEnArchivo() const {
	Archivos::guardarCita(*this);
}

void CitaMedica::mostrarInformacionCita(int idCita) const{
	std::cout << "Información de la cita:\n";
	std::cout << "ID Cita: " << idCita << "\n";
	std::cout << "ID Paciente: " << idPaciente << "\n";
	std::cout << "ID Médico: " << idMedico << "\n";
	std::cout << "Fecha: " << fecha << "\n";
	std::cout << "Urgente: " << (esUrgente ? "Sí" : "No") << "\n";
}

std::string CitaMedica::toString() const {
	std::stringstream ss;
	ss << idCita << "," << idPaciente << "," << idMedico << "," << fecha << "," << esUrgente;
	return ss.str();
}

void CitaMedica::fromString(const std::string& str) {
	std::istringstream iss(str);
	std::string idCitaStr, idPacienteStr, idMedicoStr, fecha, esUrgenteStr;
	std::getline(iss, idCitaStr, ',');
	std::getline(iss, idPacienteStr, ',');
	std::getline(iss, idMedicoStr, ',');
	std::getline(iss, fecha, ',');
	std::getline(iss, esUrgenteStr, ',');
	std::stringstream ss(idCitaStr);
	ss >> idCita;
	std::stringstream ss2(idPacienteStr);
	ss2 >> idPaciente;
	std::stringstream ss3(idMedicoStr);
	ss3 >> idMedico;
	this->fecha = fecha;
	std::stringstream ss4(esUrgenteStr);
	ss4 >> esUrgente;
}

