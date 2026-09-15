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


void registrar_Estacion(Estacion &estacion){
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