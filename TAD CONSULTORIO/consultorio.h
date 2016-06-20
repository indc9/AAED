#include "lista_enla.h"
#include "cola_enla.h"

struct Medico{
	int cod_med;
	Cola<Paciente> p;
};

struct Paciente{
	int dni;
	string nombre;
};

class Consultorio{
public:
	Consultorio();
	void alta_medico(const Medico& m);
	void annadir_paciente(const Paciente& paciente);
	Paciente turno_paciente(const Medico& m);
	void atender(const Paciente& p);
	bool cola_pacientes(const Medico& m);
private:
	Lista<Medico> l;
};