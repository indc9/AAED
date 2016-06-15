#include "pila_enla.h"


template <typename Vagon>
class Tren{
public:
    Tren(); //ctor;
    void despIzq();
    void despDer();
    void eliminar();
    void insertar(const Vagon&);
    Vagon comprobar() const;
    bool vacio() const;
private:
    Pila<Vagon> p1;
    Pila<Vagon> p2;
    Vagon activo;
};

inline Tren::Tren(): activo(p1.tope()){}

inline void Tren::despIzq()
{
    if(!p1.vacia()){
        p2.push(p1.tope());
        p1.pop();
        Vagon activo = p1.tope();
    }
    else
        vacio();

}

inline void Tren::despDer()
{
    if(!p2.vacia()){
        p1.push(p2.tope());
        p2.pop();
        Vagon activo = p1.tope();
    }
    else
        vacio();
}

inline void Tren::eliminar()
{
    assert(!p1.vacia());

    if(!p2.vacia()){
        p1.pop();
        p1.push(p2.tope());
        p2.pop();

        Vagon activo = p1.tope();
    }
    else
        vacio();
}

inline void Tren::insertar(const Vagon& v)
{
    despDer();
    p1.push(v);

    Vagon activo = p1.tope();
}

inline Vagon& Tren::comprobar() const
{
    assert(!p1.vacia());
    return p1.tope();
}

inline bool Tren::vacio() const
{
    return p1.vacia();
}
