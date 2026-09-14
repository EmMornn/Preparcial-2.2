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

void registrarElementos(Elemento &elementos)
{
    string nombre;
    cout << "Ingrese el codigo del elemento: ";
    cin >> elementos.codigo;
    cout << endl;
    cout << "Ingrese el nombre del elemento: ";
    cin >> elementos.nombre;
    cout << endl;
    cout << "Ingrese la longitud del elemento: ";
    cin >> elementos.longitud;
    cout << "Ingrese la Carga 1 del elemento: ";
    cin >> elementos.cargas[0];
    cout << endl;
    cout << "Ingrese la Carga 2 del elemento: ";
    cin >> elementos.cargas[1];
    cout << endl;
    cout << "Ingrese la Carga 3 del elemento: ";
    cin >> elementos.cargas[2];
    cout << endl;
    cout << "Ingrese la capacidad maxima del elemento: ";
    cin >> elementos.capmax;
    cout << endl;
};