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
	bool existe_sala(const Sala& s);
	bool existe_espectaculo(const Sala& s, int espect);
};

inline Cartelera::Cartelera(){}

inline bool Cartelera::existe_sala(const Sala& s)
{
	bool encontrado = false;
	typename Lista<Sala>::posicion p = l.primera();

	while(p != l.fin())
	{
		if(l.elemento(p).cod_sala == s.cod_sala && !encontrado)
			encontrado = true;			
		
		p = l.siguiente(p);
	}
	return encontrado;
}

inline bool Cartelera::existe_espectaculo(const Sala& s, int espect)
{
	bool encontrado = false;
	typename Lista<Sala>::posicion p;	
	typename Lista<int>::posicion x;

	if(existe_sala(s))
	{
		p = l.buscar(s) //buscamos la posicion de la sala en nuestra cartelera
		x = l.elemento(p).lis.buscar(espect);

		if(x != l.elemento(p).lis.fin()){	//si encuentra el espectaculo en la sala s entra en el if
			encontrado = true;
		else
			encontrado = false;
		}
	}

	return encontrado;
}

inline void Cartelera::añadir_sala(const Sala& s)
{
	if(!existe_sala)
		l.insertar(s, l.fin());
}

inline void Cartelera::añadir_espectaculo(const Sala& s, int espect)
{
	typename Lista<Sala>::posicion p;

	if(!existe_espectaculo(s,espect))
	{
		p = l.buscar(s);
		l.elemento(p).lis.insertar(espect, l.elemento(p).lis.fin());
	}
}

inline void Cartelera::eliminar_sala(const Sala& s)
{
	typename Lista<Sala>::posicion p;

	if(existe_sala(s))
	{
		p = l.buscar(s);
		l.eliminar(p);
	}
}

inline void Cartelera::eliminar_espectaculo(const Sala& s, int espect)
{
	typename Lista<Sala>::posicion p;
	typename Lista<int>::posicion x;

	if(existe_sala(s))
	{
		if(existe_espectaculo(s,espect))
		{
			p = l.buscar(s);
			x = l.elemento(p).lis.buscar(espect);
			l.elemento(p).lis.eliminar(x);
		}
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