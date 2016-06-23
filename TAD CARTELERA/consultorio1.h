#ifndef CONSULTORIO_1_H
#define CONSULTORIO_1_H

#include "lista_enla.h"
#include "cola_enla.h"

struct Medico{
	int cod_mec;
	Cola<Paciente> pac;
};

struct Paciente{
	int cod_pac;
};

class Consultorio{
public:
	Consultorio();
	void alta_medico(const Medico& m);
	void añadir_paciente(Medico& m, const Paciente& p);
	Paciente turno_paciente(const Medico& m) const;
	void atender_paciente(Medico& m);
	bool cola_vacia(const Medico& m) const;
private:
	Lista<Medico> l;
};

//Sobrecargamos el operador de comparacion para poder comparar 2 medicos
bool operator ==(const Medico& m1, const Medico& m2)
{
	return (m1.cod_mec == m2.cod_mec);
}

inline Consultorio::Consultorio(){}

inline void Consultorio::alta_medico(const Medico& m)
{
	typename Lista<Medico>::posicion p = l.buscar(m);

	if(p == l.fin())
		l.insertar(m, l.fin());
}

inline void Consultorio::añadir_paciente(Medico& m, const Paciente& p)
{
	typename Lista<Medico>::posicion p1 = l.buscar(m);

	if(p1 != l.fin())
		m.pac.push(p);	
}

inline Paciente Consultorio::turno_paciente(const Medico& m) const
{
	typename Lista<Medico>::posicion p = l.buscar(m);

	if(p != l.fin())
	{
		if(!m.pac.vacia())
			return m.pac.frente();
	}
}

inline void Consultorio::atender_paciente(Medico& m)
{
	typename Lista<Medico>::posicion p = l.buscar(m);

	if(p != l.fin())
	{
		if(!m.pac.vacia())
			m.pac.pop();
	}
}

inline bool Consultorio::cola_vacia(const Medico& m) const
{
	typename Lista<Medico>::posicion p = l.buscar(m);

	if(p != l.fin())
		return(!m.pac.vacia());

}

#endif //CONSULTORIO_1_H