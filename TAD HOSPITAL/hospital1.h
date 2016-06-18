#include "lista_vec.h"

struct Paciente{
    int cod_paciente;
    int gravedad;
};


class Hospital{
public:
    Hospital(int uci, int planta): uci(uci),planta(planta){}
    void ingreso(const Paciente& p);
    void alta();
    void muerte();
    int n_uci() const;
    int n_planta() const;
    int gravedad(int gravedad) const;
    ~Hospital();
private:
    Lista<Paciente> l_uci(uci);
    Lista<Paciente> l_planta(planta);
    const int planta,uci;
    typename Lista<Paciente>::posicion mas_sano(int zona);
    typename Lista<Paciente>::posicion mas_grave();
};

typename Lista<Paciente>::posicion Hospital::mas_sano(int zona)
{
    int mas_sano = 0;
    typename Lista<Paciente>::posicion paux;

    if(zona==0)
    {
        typename Lista<Paciente>::posicion u = l_uci.primera();

        while(u != l_uci.fin())
        {
            if(l_uci.elemento(u).gravedad > mas_sano)
            {
                mas_sano = l_uci.elemento(u).gravedad;
                paux = u;
            }
            u = l_uci.siguiente(u);
        }
    }
    else
    {
        typename Lista<Paciente>::posicion p = l_planta.primera();

        while(u != l_planta.fin())
        {
            if(l_planta.elemento(u).gravedad > mas_sano)
            {
                mas_sano = l_planta.elemento(u).gravedad;
                paux = u;
            }
            u = l_planta.siguiente(u);
        }
    }
    return paux;
}

typename Lista<Paciente>::posicion Hospital::mas_grave()
{
    int mas_grave = 5;
    typename Lista<Paciente>::posicion paux;
    typename Lista<Paciente>::posicion u = l_planta.primera();

    while(u != l_planta.fin())
    {
        if(l_planta.elemento(u).gravedad <= 5 && l_planta.elemento(u).gravedad < mas_grave)
        {
            mas_grave = l_planta.elemento(u).gravedad;
            paux = u;
        }
        u = l_planta.siguiente(u);
    }
    return paux;
}

void Hospital::ingreso(const Paciente& p)
{
    typename Lista<Paciente>::posicion x;

    if(p.gravedad >= 1 && p.gravedad <= 5){
        if(n_uci() == uci){
            x = mas_sano(0);

            if(n_planta() == planta){
                alta();
                l_planta.insertar(p, x);
            }
            else
                l_planta.insertar(p, x);
        }
        else
            l_uci.insertar(p, l_uci.fin());
    }
    else{
        if(p.gravedad >= 6 && p.gravedad <= 9)
        {
            if(n_planta() == planta){
                alta();
                l_planta.insertar(p, l_planta.fin());
            }else{
                l_uci.insertar(p, l_planta.fin());
                if(n_uci() != uci)
                {
                    typename Lista<Paciente>::posicion w;
                    w = mas_grave();
                    if(l_planta.elemento(w).gravedad <= 5)
                        l_uci.insertar(l_planta.elemento(w), l_uci.fin());
                }
            }
        }
    }
    if(l_planta.elemento())
}

void Hospital::alta()
{
    l_planta.eliminar(mas_sano(1));
}

void Hospital::muerte(const Paciente& p)
{
    typename Lista<Paciente>::posicion m;
    if(p.gravedad == 0){
        m = l_uci.buscar(p);
        l_uci.eliminar(m);
    }
}

int Hospital::n_uci() const
{
    int cont = 0;
    typename Lista<Paciente>::posicion p = l_uci.primera();

    while(p != l_uci.fin())
    {
        if(l_uci.elemento(p) != NULL)
        {
            p = l_uci.siguiente(p);
            cont++;
        }
    }
    return cont;
}

int Hospital::n_planta() const
{
    int cont = 0;
    typename Lista<Paciente>::posicion p = l_planta.primera();

    while(p != l_planta.fin())
    {
        if(l_planta.elemento(p) != NULL)
        {
            p = l_planta.siguiente(p);
            cont++;
        }
    }
    return cont;
}

int Hospital::gravedad(int gravedad) const
{
    typename Lista<Paciente>::posicion u = l_uci.primera();
    typename Lista<Paciente>::posicion p = l_planta.primera();
    int cont = 0;

    while(u != l_uci.fin())
    {
        if(!l_uci.elemento(p).gravedad == gravedad)
            cont++;
        u = l_uci.siguiente(u);
    }
    while(u < l_planta.fin())
    {
        if(!l_planta.elemento(p).gravedad == gravedad)
            cont++;
        u = l_planta.siguiente(u);
    }
    return cont;
}

Hospital::~Hospital(){}
