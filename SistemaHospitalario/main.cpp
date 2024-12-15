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
        cout << "\nGestión de Pacientes\n";
        cout << "1. Alta de paciente\n";
        cout << "2. Baja de paciente\n";
        cout << "3. Listar pacientes\n";
        cout << "4. Volver al menú principal\n";
        cout << "Seleccione una opción: ";
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
            cout << "Opción no válida.\n";
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
        cout << "\nGestión de Médicos\n";
        cout << "1. Alta de médico\n";
        cout << "2. Baja de médico\n";
        cout << "3. Listar médicos\n";
        cout << "4. Volver al menú principal\n";
        cout << "Seleccione una opción: ";
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
            cout << "ID del médico a dar de baja: ";
            cin >> id;
            Medico::bajaMedico(medicos, id);
            break;
        case 3:
            Medico::listarMedicos(medicos);
            break;
        case 4:
            return;
        default:
            cout << "Opción no válida.\n";
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
        cout << "\nGestión de Citas\n";
        cout << "1. Asignar cita\n";
        cout << "2. Cancelar cita\n";
        cout << "3. Listar citas\n";
        cout << "4. Volver al menú principal\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            cout << "ID del Paciente: ";
            cin >> idPaciente;
            cout << "ID del Médico: ";
            cin >> idMedico;
            cout << "Fecha (YYYY-MM-DD): ";
            cin >> fecha;
            cout << "Es urgente? (1 para sí, 0 para no): ";
            cin >> esUrgente;
            CitaMedica::asignarCita(citas, idPaciente, idMedico, fecha, esUrgente);
            break;
        case 2:
            cout << "ID del Paciente: ";
            cin >> idPaciente;
            cout << "ID del Médico: ";
            cin >> idMedico;
            CitaMedica::cancelarCita(citas, idPaciente, idMedico);
            break;
        case 3:
            CitaMedica::listarCitas(citas);
            break;
        case 4:
            return;
        default:
            cout << "Opción no válida.\n";
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
        cout << "\nMenú Principal\n";
        cout << "1. Gestionar Pacientes\n";
        cout << "2. Gestionar Médicos\n";
        cout << "3. Gestionar Citas\n";
        cout << "4. Salir\n";
        cout << "Seleccione una opción: ";
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
            cout << "Opción no válida.\n";
            break;
        }
    } while (opcion != 4);

    return 0;
}
