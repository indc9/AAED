#include "lista_enla.h"
#include <cstring>

struct Traduccion{
	string inglesa;
	Lista<string> lista;
};

class Diccionario{
public:
	Diccionario(); 	//ctor
	void insertar(string español, string ingles);
	void eliminar(string español, string ingles);
	Lista<string>& consultar(string ingles);
	~Diccionario();
private:
	Lista<Traduccion> l;
};

inline Diccionario::Diccionario(){}

inline void Diccionario::insertar(string español, string ingles)
{
	typename Lista<Traduccion>::posicion p = l.primera();
	bool encontrado = false;
	//si encuentra la palabra
	while(p != l.fin() && !encontrado)
	{
		if(strcmp(ingles, l.elemento(p).inglesa) == 0){
			encontrado = true;
			l.elemento(p).lista.insertar(español, l.elemento(p).lista.fin())
		}
		p = l.siguiente(p);
	}
	//si no encuenta la palabra
	if(!encontrado){
		Traduccion t;
		strcpy(t.inglesa, ingles);
		t.lista.insertar(español, t.lista.fin());
		l.insertar(t, l.fin());
	}
}

inline void Diccionario::eliminar(string español, string ingles)
{
	typename Lista<Traduccion>::posicion p = l.primera();
	bool encontrado = false;
	//si encuentra la palabra
	while(p != l.fin() && !encontrado)
	{
		if(strcmp(ingles, l.elemento(p).inglesa) == 0){
			typename Lista<Traduccion>::posicion x = l.elemento(p).lista.buscar(español)
			encontrado = true;
			l.elemento(p).lista.eliminar(x);
		}
		p = l.siguiente(p);
	}
	//si no encuenta la palabra
	if(!encontrado)
		std::cout << "La palabra inglesa no se encuentra en el Diccionario" << std::endl;

}

Lista<string>& Diccionario::consultar(string ingles)
{
	typename Lista<Traduccion>::posicion p = l.primera();
	bool encontrado = false;
	//si encuentra la palabra
	while(p != l.fin() && !encontrado)
	{
		if(strcmp(ingles, l.elemento(p).inglesa) == 0){
			encontrado = true;
		}
		p = l.siguiente(p);
	}
	if(encontrado && p!= l.fin())
		return l.elemento(p).lista;
}

Diccionario::~Diccionario(){}