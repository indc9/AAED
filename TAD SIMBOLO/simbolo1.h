#ifndef SIMBOLO_H
#define SIMBOLO_H
#include "pila_enla.h"

typedef char trazo;

class Simbolo{
public:
    Simbolo();
    void annadir(const trazo& t);
    void deshacer(int n);
    Simbolo simetriaX();
    Simbolo simetriaY();
    Simbolo simetriaXY();
    ~Simbolo();
private:
    Pila<trazo> p1;
};

inline Simbolo::Simbolo(){}

inline void simbolo::annadir(const trazo& t)
{
    p1.push(t);
}

inline void simbolo::deshacer(int n)
{
    int i = 0;

    while(i<n && !p1.vacia()){
        p1.pop();
        i++;
    }
}

inline Simbolo Simbolo::simetriaX()
{
    simbolo s;
    Pila<trazo> p2;
    pila<trazo> p3;

    p3=p1;

    while(!p3.vacia())
    {
        if(p3.tope() == 'S')
            p2.push('B');
        else if(p3.tope() == 'B')
            p2.push('S');
            else{
                p2.push(p3.tope());
                p3.pop();
            }
    }
    while(!p2.vacia())
    {
        s.annadir(p2.tope());
        p2.pop();
    }
    return s;
}

inline Simbolo Simbolo::simetriaX()
{
    simbolo s;
    Pila<trazo> p2;
    pila<trazo> p3;

    p3=p1;

    while(!p3.vacia())
    {
        if(p3.tope() == 'I')
            p2.push('D');
        else if(p3.tope() == 'D')
            p2.push('I');
            else{
                p2.push(p3.tope());
                p3.pop();
            }
    }
    while(!p2.vacia())
    {
        s.annadir(p2.tope());
        p2.pop();
    }
    return s;
}

inline Simbolo Simbolo::simetriaXY()
{
    simbolo s;
    Pila<trazo> p2;
    pila<trazo> p3;

    p3=p1;

    while(!p3.vacia())
    {
        if(p3.tope() == 'I'){
            p2.push('D');
            p3.pop();
        }
        else if(p3.tope() == 'D'){
            p2.push('I');
            p3.pop();
        }
            else if(p3.tope() == 'S'){
                p2.push('B');
                p3.pop();
            }
                else if(p3.tope() == 'B'){
                    p2.push('S');
                    p3.pop();
                }
                    else{
                        p2.push(p3.tope());
                        p3.pop();
                    }
    }
    while(!p2.vacia())
    {
        s.annadir(p2.tope());
        p2.pop();
    }
    return s;
}

Simbolo::~Simbolo(){}


#endif // SIMBOLO_H
