# CMakeList.txt: proyecto de CMake para SistemaHospitalario, incluya el origen y defina
# la lógica específica del proyecto aquí.
#

project(SistemaHospitalario)
# Agregue un origen al ejecutable de este proyecto.



# TODO: Agregue pruebas y destinos de instalación si es necesario.
include_directories(include)

add_executable(SistemaHospitalario main.cpp src/Paciente.cpp src/Medico.cpp src/Cita.cpp)

