#include <iostream>
using namespace std;

struct Elemento
{
    string codigo;
    string nombre;
    int longitud;
    float cargas[3];
    float capmax;
    float factor_utilizacion;
    bool estado_seguridad;
};