#include <iostream>
using namespace std;

struct Estacion
{
    string codigo;
    string ubicacion;
    float lecturas[3];
    float promedio_intensidad;
    string nivel_alerta;
};

void registrar_Estacion(Estacion &estacion)
{
    cout << endl;
    cout << "Ingrese el codigo de la Estacion: ";
    cin >> estacion.codigo;
    cout << endl;
    cout << "Ingrese la ubicacion de la Estacion: ";
    getline(cin, estacion.ubicacion);
    cout << endl;
    cout << "Ingrese la lectura 1 de la Estacion: ";
    cin >> estacion.lecturas[0];
    cout << endl;
    cout << "Ingrese la lectura 2 de la Estacion: ";
    cin >> estacion.lecturas[1];
    cout << endl;
    cout << "Ingrese la lectura 3 de la Estacion: ";
    cin >> estacion.lecturas[2];
    cout << endl;
};

float calcularPromedio(Estacion *estacion)
{
    float promedio = 0;
    float suma = 0;
    for (int i = 0; i < 3; i++)
    {
        suma += estacion->lecturas[i];
    }
    promedio = suma / 3;
    estacion->promedio_intensidad = promedio;
    return estacion->promedio_intensidad;
};

void evaluarAlerta(Estacion &estacion)
{

    if (estacion.promedio_intensidad >= 0.0 && estacion.promedio_intensidad <= 2.9)
    {
        estacion.nivel_alerta = " VERDE ";
    }
    else if (estacion.promedio_intensidad >= 3.0 && estacion.promedio_intensidad <= 5.9)
    {
        estacion.nivel_alerta = " AMARILLA ";
    }
    else if (estacion.promedio_intensidad >= 6.0 && estacion.promedio_intensidad <= 7.9)
    {
        estacion.nivel_alerta = " NARANJA ";
    }else if (estacion.promedio_intensidad >= 8.0 )
    {
        estacion.nivel_alerta = " ROJA ";
    }
    else
    {
        cout << " Alerta desconocido, niveles no identificados " << endl;
    }
    
};