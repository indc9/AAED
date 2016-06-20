#include "lista_enla"

struct Sala{
	Lista<int> espectaculo;	
	int sala;
};

class Cartelera{
public:
	Cartelera();
	void annadir_sala(const Sala& s);
	void annadir_espectaculo(cosnt Sala& s, int espect);
	void eliminar_sala(const Sala& s);
	void eliminar_espectaculo(const Sala& s, int espect);
	void mostrar_sala();	//Lo mostramos sin ordenar
	void mostrar_espectaculo(const Sala& s);	//Lo mostramos sin ordenar
	~Cartelera();
private:	
	Lista<sala> l;	
};

inline Cartelera::Cartelera(){}

inline void Cartelera::annadir_sala(const Sala& s)
{
	typename Lista<Sala>::posicion p = l.primera();
	bool encontrado = false;

	while(p != l.fin())
	{
		if(l.elemento(p).sala == s.sala && !encontrado)
			encontrado = true;
		else if(!encontrado)
		{
			l.insertar(s, l.fin());
		}
	}	
}

inline void annadir_espectaculo(const Sala& s, int espect)
{
	typename Lista<Sala>::posicion p = l.primera();
	typename Lista<int>::posicion x = l.elemento(p).espectaculo.primera();
	bool encontrado_sala = false;
	bool encontrado_espect = false;

	while(p != l.fin())
	{
		if(l.elemento(p).sala == s.sala && !encontrado_sala)
		{
			encontrado_sala = true;
			while(x != l.elemento(p).espectaculo.fin() && !encontrado_espect)
			{
			 	if(l.elemento(p).espectaculo.elemento(x) == espect && !encontrado_espect)
			 		encontrado_espect = true;

			 	x = l.elemento(p).espectaculo.siguiente(x);
			}			
			if(!encontrado_espect)
			 		l.elemento(p).espectaculo.insertar(espect, x);
		}
		p = l.elemento(p).espectaculo.siguiente(p);
	}	
}

inline void Cartelera::eliminar_sala(const Sala& s)
{
	typename Lista<Sala>::posicion p = l.primera();
	bool encontrado = false;

	while(p != l.fin())
	{
		if(l.elemento(p).sala == s.sala && !encontrado)
		{
			encontrado = true;
			l.eliminar(p);
		}
	}
}

inline void Cartelera::eliminar_espectaculo(const Sala& s, int espect)
{
	typename Lista<Sala>::posicion p = l.primera();
	typename Lista<int>::posicion x = l.elemento(p).espectaculo.primera();
	bool encontrado_sala = false;
	bool encontrado_espect = false;

	while(p != l.fin())
	{
		if(l.elemento(p).sala == s.sala && !encontrado_sala)
		{
			encontrado_sala = true;
			while(x != l.elemento(p).espectaculo.fin() && !encontrado_espect)
			{
			 	if(l.elemento(p).espectaculo.elemento(x) == espect && !encontrado_espect)
			 	{
			 		encontrado_espect = true;
			 		l.elemento(p).espectaculo.eliminar(x);
			 	}
			 	x = l.elemento(p).espectaculo.siguiente(x);
			}			
		}
		p = l.elemento(p).espectaculo.siguiente(p);
	}
}

inline void Cartelera::mostrar_sala()
{
	typename Lista<Sala>::posicion p = l.primera();
	bool encontrado = false;

	while(p != l.fin())
	{
		std::cout << l.elemento(p).sala << std::endl;
	}
}

inline void Cartelera::mostrar_espectaculo(const Sala& s)
{
	typename Lista<Sala>::posicion p = l.primera();
	typename Lista<int>::posicion x = l.elemento(p).espectaculo.primera();
	bool encontrado_sala = false;

	while(p != l.fin())
	{
		if(l.elemento(p).sala == s.sala && !encontrado_sala)
		{
			encontrado_sala = true;
			while(x != l.elemento(p).espectaculo.fin())
			{
			 	std::cout << l.elemento(p).espectaculo.elemento(x) << endl;

			 	x = l.elemento(p).espectaculo.siguiente(x);
			}			
		}
		p = l.elemento(p).siguiente(p);
	}	
}

inline Cartelera::~Cartelera(){}