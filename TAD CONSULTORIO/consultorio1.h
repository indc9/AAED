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
	void añadir_paciente(const Medico& m, const Paciente& p);
	Paciente& turno_paciente(const Medico& m) const;
	void atender_paciente(const Medico& m);
	bool cola_vacia(const Medico& m) const;
private:
	Lista<Medico> l;
};

//Sobrecargamos el operador de comparacion  y diferencia para poder comparar 2 medicos
bool operator ==(const Medico& m1, const Medico& m2)
{
	return (m1.cod_mec == m2.cod_mec);
}

bool operator !=(const Medico& m1, const Medico& m2)
{
	return (m1.cod_mec != m2.cod_mec);
}

inline Consultorio::Consultorio(){}

inline void Consultorio::alta_medico(const Medico& m)
{
	typename Lista<Medico>::posicion p = l.buscar(m);

	if(p == l.fin())
		l.insertar(m, l.fin());
}

inline void Consultorio::añadir_paciente(const Medico& m, const Paciente& p)
{
	typename Lista<Medico>::posicion p = l.buscar(m);

	if(p != l.fin())
		l.elemento(p).pac.push(p);	
}

inline Paciente& Consultorio::turno_paciente(const Medico& m) const
{
	typename Lista<Medico>::posicion p = l.buscar(m);

	if(p != l.fin())
	{
		if(!l.elemento(p).pac.vacia())
			return l.elemento(p).pac.frente();
	}
}

inline void Consultorio::atender_paciente(const Medico& m)
{
	typename Lista<Medico>::posicion p = l.buscar(m);

	if(p != l.fin())
	{
		if(!l.elemento(p).pac.vacia())
			l.elemento(p).pac.pop();
	}
}

inline bool Consultorio::cola_vacia(const Medico& m) const
{
	typename Lista<Medico>::posicion p = l.buscar(m);
	bool encontrado = false;

	if(p != l.fin())
	{
		if(!l.elemento(p).pac.vacia())
			encontrado = true;
	}
	return encontrado;
}