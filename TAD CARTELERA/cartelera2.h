struct Sala{
	int cod_sala
	Lista<int> lis;
};

class Cartelera{
public:
	Cartelera();
	void añadir_sala(const Sala& s);
	void añadir_espectaculo(const Sala& s, int espect);
	void eliminar_sala(const Sala& s);
	void eliminar_espectaculo(const Sala& s, int espect);
	void mostrar_salas() const;
	void mostrar_espectaculos(const Sala& s) const;
private:
	Lista<Sala> l;
};

bool operator ==(const Sala& s1, const Sala& s2)	//sobrecargamos el operador para utilizar buscar() sin problemas
{
	return (s1.cod_sala == s2.cod_sala);
}


inline Cartelera::Cartelera(){}


inline void Cartelera::añadir_sala(const Sala& s)
{
	typename Lista<Sala>::posicion p = l.buscar(s);

	if(p == l.fin())
		l.insertar(s, l.fin());
}

inline void Cartelera::añadir_espectaculo(const Sala& s, int espect)
{
	typename Lista<Sala>::posicion p = l.buscar(s);

	if(p != l.fin())
	{
		typename Lista<int>::posicion x = l.elemento(p).lis.buscar(espect);

		if(x == l.elemento(p).lis.fin())
			l.elemento(p).lis.insertar(espect, l.elemento(p).lis.fin());
	}
	
}

inline void Cartelera::eliminar_sala(const Sala& s)
{
	typename Lista<Sala>::posicion p = l.buscar(s);

	if(p != l.fin())
		l.eliminar(p);
}

inline void Cartelera::eliminar_espectaculo(const Sala& s, int espect)
{
	typename Lista<Sala>::posicion p = l.buscar(s);

	if(p != l.fin())
	{
		typename Lista<int>::posicion x = l.elemento(p).lis.buscar(espect);

		if(x != l.elemento(p).lis.fin())
			l.elemento(p).lis.eliminar(x);
	}
}

inline void Cartelera::mostrar_salas() const
{
	typename Lista<Sala>::posicion p = l.primera();

	while(p != l.fin())
	{
		std::cout << l.elemento(p).cod_sala << std::endl;
		p = l.siguiente(p);
	}
}

inline void Cartelera::mostrar_espectaculos(const Sala& s)
{
	typename Lista<Sala>::posicion p = l.primera();
	typename Lista<int>::posicion x = l.elemento(p).lis.primera();

	while(p != l.fin())
	{
		while(x != l.elemento(p).lis.fin())
		{
			std::cout << l.elemento(p).lis.elemento(x) << std::endl;

			x = l.elemento(p).lis.siguiente(x);
		}
		p = l.siguiente(p);
	}
}