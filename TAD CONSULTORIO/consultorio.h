#include "lista_enla.h"
#include "cola_enla.h"

struct Medico{
	int cod_med;
	Cola<Paciente> pac;
};

struct Paciente{
	int dni;
	string nombre;
};

class Consultorio{
public:
	Consultorio();
	bool existe_med(const Medico& m);	//Función auxiliar
	void alta_medico(const Medico& m);
	void annadir_paciente(const Paciente& paciente, const Medico& m);
	Paciente turno_paciente(const Medico& m);
	void atender(const Paciente& p);
	bool cola_pacientes(const Medico& m);
	~Consultorio();
private:
	Lista<Medico> l;
	typename Lista<Medico>::posicion pos_med = -1;
};



inline Consultorio::Consultorio(){}

inline bool Consultorio::existe_med(const Medico& m)
{
	typename Lista<Medico>::posicion p = l.primera();
	bool encontrado = false;

	while(p != l.fin())
	{
		if(l.elemento(p).cod_med == m.cod_med && !encontrado)
		{
			encontrado = true;
		}	
		p = l.siguiente(p);
	}
	if(encontrado)
		pos_med = p;

	return encontrado;
}

inline void Consultorio::alta_medico(const Medico& m)
{
	if(!existe_med(m))
		l.insertar(m, l.fin());	
}

inline void Consultorio::annadir_paciente(const Paciente& paciente, const Medico& m)
{
	typename Cola<Paciente>::posicion x = l.elemento(p).pac.primera();

	if(existe_med(m))
		l.elemento(pos_med).pac.push(paciente));		
}

inline bool Consultorio::cola_pacientes(const Medico& m)
{
	bool existe = false;

	if(existe_med(m))
		if(!l.elemento(pos_med).pac.vacia())
			existe = true;

	return existe;
}

inline Paciente Consultorio::turno_paciente(const Medico& m)
{	
	if(existe_med(m))
		if(cola_pacientes(m))		
			return l.elemento(pos_med).pac.frente();
}

inline void Consultorio::atender(const Medico& m)
{
	Paciente p;

	if(existe_med(m))
		p = turno_paciente(m);

	if(p == l.elemento(pos_med).pac.frente())
		l.elemento(pos_med).pac.pop();
}



Consultorio::~Consultorio(){}
