#include "lista_vec.h"

struct Mueble{
    Mueble(int posicion = -1, double anchura = 0.0):
        posicion(posicion),anchura(anchura){}
    int posicion;
    double anchura;
};

class Cocina{
public:
    Cocina(double anchura): anchura_(anchura){} //ctor.
    bool comprobar(const Mueble&, int pos) const;
    void añadir_mueble(const Mueble&, int pos);
    Mueble devolver(int pos) const;
    void eliminar(int pos);
    void mover_mueble(int pos);
private:
    Lista<Mueble> l;
   	double anchura_ = 0.0;
};

//Implementación de métodos


inline bool Cocina::comprobar(const Mueble& m, int pos) //habría que comprobar que haya un mueble en esa posicion ya?
{
	if(m.anchura+pos > anchura_)
        return false;
    else
        return true;
}

void Cocina::añadir_mueble(const Mueble& m, int pos)
{
    typename Lista<Mueble>::posicion x = l.primera();

    if(comprobar(m,pos))
    {
       l.insertar(m,pos);
       m.posicion = pos;
    }
}

Mueble Mueble::devolver(int pos)
{
    Mueble m;

	if(pos < anchura_)
	{
		typename Lista<Mueble>::posicion x = l.primera();
		int i=0;

		while(i < pos)
		{
			x = l.siguiente(x);
			i++;
		}
		return l.elemento(x);
	}
	else{   //no hay mueble en esa posicion
        m.posicion=-1;
        return m;
	}
}

void Cocina::eliminar(int pos)
{
    int i=0;

    if(pos < anchura_)
    {
        typename Lista<Mueble>::posicion x = l.primera();

        while(i < pos)
        {
            x = l.siguiente(x);
            i++;
        }
        anchura_--;
        l.eliminar(x);
    }
}

void mover_mueble(const Mueble& m)
{
    int i=0;

    if(pos < anchura_)
    {
        typename Lista<Mueble>::posicion x = l.primera();

        while(i < pos)
        {
            x = l.siguiente(x);
            i++;
        }

        if(x == l.primera())
            l.elemento(x).posicion = 0;
        else
            l.elemento(x).posicion = l.elemento(l.anterior(x)).anchura + l.elemento(l.anterior(x)).posicion;
    }
}
