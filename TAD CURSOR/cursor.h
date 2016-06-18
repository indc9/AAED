#include "pila_enla.h"

class Cursor{
public:
    Cursor();
    void avanzar() const;
    void retroceder() const;
    void fin() const;
    void principio() const;
    void suprimir();
    void borrar_anterior();
    void insertar(char);
    void sobreescribir(char);
private:
    Pila<char> p1;
    Pila<char> p2;
    char cursor = p1.tope();
};

inline Cursor::Cursor(){}

inline void Cursor::avanzar() const
{
    if(!p2.vacia())
    {
        p1.push(p2.tope());
        p2.pop();
    }
}

inline void Cursor::retroceder() const
{
    if(!p1.vacia())
    {
        p2.push(p1.tope())
        p1.pop();
    }
}

inline void Cursor::fin() const
{
    while(!p2.vacia())
        avanzar();
}

inline void Cursor::principio() const
{
    while(!p1.vacia())
        retroceder();
}

inline void Cursor::suprimir()
{
    if(!p1.vacia())
        p1.pop();
}
inline void borrar_anterior()
{
    assert(!p1.vacia())

    p2.push(p1.tope())
    p1.pop();
    if(!p1.vacia()){
        p1.pop();
        p1.push(p2.tope());
    }
    else{
        p1.push(p2.tope());
        std::cout << "Error: no existe caracter anterior" << endl;
    }
}

inline void Cursor::insertar(char c)
{
    p1.push(c);
}

inline void Cursor::sobreescribir(char c)
{
    if(!p1.vacia())
    {
        p1.pop();
        p1.push(c):
    }
}
