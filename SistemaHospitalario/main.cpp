#include <iostream>
#include <vector>
#include "Paciente.h"
#include "Medico.h"
#include "Cita.h"

using namespace std;

void gestionarPacientes(vector<Paciente>& pacientes) {
    int opcion;
    string nombre;
    int id;
    string fechaIngreso;

    do {
        cout << "\nGesti�n de Pacientes\n";
        cout << "1. Alta de paciente\n";
        cout << "2. Baja de paciente\n";
        cout << "3. Listar pacientes\n";
        cout << "4. Volver al men� principal\n";
        cout << "Seleccione una opci�n: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            cout << "Nombre: ";
            cin >> nombre;
            cout << "ID: ";
            cin >> id;
            cout << "Fecha de Ingreso: ";
            cin >> fechaIngreso;
            Paciente::altaPaciente(pacientes, nombre, id, fechaIngreso);
            break;
        case 2:
            cout << "ID del paciente a dar de baja: ";
            cin >> id;
            Paciente::bajaPaciente(pacientes, id);
            break;
        case 3:
            Paciente::listarPacientes(pacientes);
            break;
        case 4:
            return;
        default:
            cout << "Opci�n no v�lida.\n";
            break;
        }
    } while (opcion != 4);
}

void gestionarMedicos(vector<Medico>& medicos) {
    int opcion;
    string nombre;
    int id;
    string especialidad;

    do {
        cout << "\nGesti�n de M�dicos\n";
        cout << "1. Alta de m�dico\n";
        cout << "2. Baja de m�dico\n";
        cout << "3. Listar m�dicos\n";
        cout << "4. Volver al men� principal\n";
        cout << "Seleccione una opci�n: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            cout << "Nombre: ";
            cin >> nombre;
            cout << "ID: ";
            cin >> id;
            cout << "Especialidad: ";
            cin >> especialidad;
            Medico::altaMedico(medicos, nombre, id, especialidad);
            break;
        case 2:
            cout << "ID del m�dico a dar de baja: ";
            cin >> id;
            Medico::bajaMedico(medicos, id);
            break;
        case 3:
            Medico::listarMedicos(medicos);
            break;
        case 4:
            return;
        default:
            cout << "Opci�n no v�lida.\n";
            break;
        }
    } while (opcion != 4);
}

void gestionarCitas(vector<CitaMedica>& citas, const vector<Paciente>& pacientes, const vector<Medico>& medicos) {
    int opcion;
    int idPaciente;
    int idMedico;
    string fecha;
    bool esUrgente;

    do {
        cout << "\nGesti�n de Citas\n";
        cout << "1. Asignar cita\n";
        cout << "2. Cancelar cita\n";
        cout << "3. Listar citas\n";
        cout << "4. Volver al men� principal\n";
        cout << "Seleccione una opci�n: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            cout << "ID del Paciente: ";
            cin >> idPaciente;
            cout << "ID del M�dico: ";
            cin >> idMedico;
            cout << "Fecha (YYYY-MM-DD): ";
            cin >> fecha;
            cout << "Es urgente? (1 para s�, 0 para no): ";
            cin >> esUrgente;
            CitaMedica::asignarCita(citas, idPaciente, idMedico, fecha, esUrgente);
            break;
        case 2:
            cout << "ID del Paciente: ";
            cin >> idPaciente;
            cout << "ID del M�dico: ";
            cin >> idMedico;
            CitaMedica::cancelarCita(citas, idPaciente, idMedico);
            break;
        case 3:
            CitaMedica::listarCitas(citas);
            break;
        case 4:
            return;
        default:
            cout << "Opci�n no v�lida.\n";
            break;
        }
    } while (opcion != 4);
}

int main() {
    vector<Paciente> pacientes;
    vector<Medico> medicos;
    vector<CitaMedica> citas;

    int opcion;

    do {
        cout << "\nMen� Principal\n";
        cout << "1. Gestionar Pacientes\n";
        cout << "2. Gestionar M�dicos\n";
        cout << "3. Gestionar Citas\n";
        cout << "4. Salir\n";
        cout << "Seleccione una opci�n: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            gestionarPacientes(pacientes);
            break;
        case 2:
            gestionarMedicos(medicos);
            break;
        case 3:
            gestionarCitas(citas, pacientes, medicos);
            break;
        case 4:
            cout << "Saliendo del programa...\n";
            break;
        default:
            cout << "Opci�n no v�lida.\n";
            break;
        }
    } while (opcion != 4);

    return 0;
}
