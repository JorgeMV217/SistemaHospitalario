# Simulador de Gestión Hospitalaria
## Descripción
Este proyecto es un simulador de gestión hospitalaria que permite gestionar pacientes, médicos y citas médicas. Proporciona funcionalidades para agregar, eliminar y buscar registros, así como listar la información almacenada en archivos de texto.

## Funcionalidades
### Gestión de pacientes:
- Alta de pacientes
- Baja de pacientes
- Listado de pacientes desde archivo
- Búsqueda de Pacientes

### Gestión de médicos:
- Alta de médicos
- Baja de médicos
- Listado de médicos desde archivo
- Búsqueda de médicos


### Gestión de citas médicas:
- Asignar citas médicas
- Cancelar citas médicas
- Listado de citas desde archivo
- Búsqueda de citas

## Requisitos
- C++17 o superior
- Compilador compatible con C++ (por ejemplo, g++, cl)
- CMake (opcional, para facilitar la construcción del proyecto)

## Instalación
### Usando CMake
1. Clona el repositorio:
```
git clone https://github.com/tuusuario/simulador-gestion-hospitalaria.git
cd simulador-gestion-hospitalaria
```
2. Crea un directorio de compilación y navega a él:
```
mkdir build
cd build
```
3. Genera los archivos de compilación y construye el proyecto:
```
cmake ..
cmake --build .
```
4. Ejecuta el programa:

```
./SimuladorGestionHospitalaria
```
## Compilación Manual (sin CMake)
1. Clona el repositorio:
```
git clone https://github.com/tuusuario/simulador-gestion-hospitalaria.git
cd simulador-gestion-hospitalaria
```
2. Compila los archivos fuente:
```
g++ -std=c++17 -o SimuladorGestionHospitalaria main.cpp Paciente.cpp Medico.cpp CitaMedica.cpp Utilidades.cpp
```
3. Ejecuta el programa:
```
./SimuladorGestionHospitalaria
```
## Uso
El programa presenta un menú interactivo que permite gestionar pacientes, médicos y citas médicas. Simplemente ejecuta el programa y sigue las instrucciones en pantalla.

### Menús principales
- Gestión de Pacientes
- Gestión de Médicos
- Gestión de Citas Médicas
