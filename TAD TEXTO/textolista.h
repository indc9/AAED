#include "lista_doble.h"

class Texto{
public:
	Texto();
	void MostrarTexto();
private:
	Lista<lista<char>> l;
};

inline void MostrarTexto()
{
	typename Lista<Lista<char>>::posicion p = l.primera();
	typename Lista<char>::posicion x = l.elemento(p).primera();
	bool encontrado = false;

	while(p != l.fin())
	{
		while(x != l.elemento(p).fin() && !encontrado)
		{
			if(l.elemento(p).elemento(x) == '#')
			{
				l.eliminar(p);
				encontrado = true;
			}
			else
			{
				if(l.elemento(p).elemento(x) == '@' && !encontrado)
				{
					l.elemento(p).eliminar(x);
				}
			}

			x = l.elemento(p).siguiente(x);
		}

		p = l.siguiente(p);
	}
}