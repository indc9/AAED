#include "lista_enla.h"
#include "pila_enla.h"

class Texto{
public:
	Texto(const Lista<Pila<char>>& texto);
	void MostrarTexto();
private:
	Lista<Pila<char>> l;
};

inline MostrarTexto()
{
	typename Lista<Pila<char>>::posicion p = l.primera();
	typename Pila<char>::posicion x = l.elemento(p).tope();

	Pila<char> p2;
	bool encontrado = false;

	while(p != l.fin())
	{
		while(x != l.elemento(p).vacia())
		{
			if(l.elemento(p).tope() == '#' && !encontrado)
			{
				l.elemento(p).pop();
				encontrado = true;
			}
			else 
			{
				if(l.elemento(p).tope() == '@' && !encontrado)
				{
					l.elemento(p).pop();
					p2.push(l.elemento(p).tope());
				}
				else
				{
					p2.push(l.elemento(p).tope());
					l.elemento(p).pop();
				}

			}
		}
		if(!encontrado)
		{
			p = l.primera();
			x = l.elemento(p).tope()

			while(p != l.fin())
			{
				while(x != l.elemento(p).vacia())
				{
					l.elemento(p).push(p2.tope());
					p2.pop();
					std::cout << l.elemento(p).tope();
				}
				std::endl;
				p = l.siguiente(p);
			}
		}
		p = l.siguiente(p);		
	}
}
