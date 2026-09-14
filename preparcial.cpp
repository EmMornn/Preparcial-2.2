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

float calcularFactor(Elemento *elemento)
{
    float suma = 0;
    float promedio = 0;
    float f_utilizacion = 0;
    for (int i = 0; i < 3; i++)
    {
        suma = suma + elemento->cargas[i];
    }
    promedio = suma / 3;
    f_utilizacion = promedio / elemento->capmax;
    elemento->factor_utilizacion = f_utilizacion;
    return elemento->factor_utilizacion;
};

int main()
{
    Elemento elementos[10];
    int n;
    cout << endl;
    do
    {
        cout << "Ingrese la cantidad de elementos que desea registrar (1-10):";
        cin >> n;
        if (n < 1 || n > 10)
        {
            cout << "Cantidad de elementos ingresados no valida, intente nuevamente" << endl;
        }

    } while (n < 1 || n > 10);

    cout << "Cantidad registrada de : " << n << " elementos" << endl;

    return 0;
}
