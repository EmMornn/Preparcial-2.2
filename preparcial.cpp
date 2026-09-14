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
    string estado_seguridad;
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

void determinarSeguridad(Elemento &elemento)
{
    if (elemento.factor_utilizacion >= 0.00 && elemento.factor_utilizacion < 0.50)
    {
        cout << "Estado: SEGURO" << endl;
        elemento.estado_seguridad == "Seguro";
    }
    else if (elemento.factor_utilizacion >= 0.50 && elemento.factor_utilizacion < 0.80)
    {
        cout << "Estado: PRECAUCION" << endl;
        elemento.estado_seguridad == "Precaucion";
    }
    else if (elemento.factor_utilizacion >= 0.80 && elemento.factor_utilizacion < 1.00)
    {
        cout << "Estado: RIESGO" << endl;
        elemento.estado_seguridad == "Riesgo";
    }
    else if (elemento.factor_utilizacion >= 1.00)
    {
        cout << "Estado: SOBRECARGA" << endl;
        elemento.estado_seguridad == "Sobrecarga";
    }
    else
    {
        cout << "Valor no identificado" << endl;
    }
};

Elemento *obtenerElementoCritico(Elemento elementos[], int cantidad)
{
    Elemento *critico = &elementos[0];
    for (int i = 1; i < cantidad - 1; i++)
    {
        if (elementos[i].factor_utilizacion > critico->factor_utilizacion)
        {
            critico = &elementos[i];
        }
    }
    return critico;
};

void aumentarCargas(
    Elemento &elemento, float porcentaje)
{
    float nCarga = 0;
    for (int i = 0; i < 3; i++)
    {
        elemento.cargas[i] = elemento.cargas[i] * (1.0 + porcentaje / 100.0);
    }
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
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << endl;
        cout << "Registrando elemento " << i + 1 << ": " << endl;
        registrarElementos(elementos[i]);

        calcularFactor(&elementos[i]);

        determinarSeguridad(elementos[i]);
    };

    Elemento *masCritico = obtenerElementoCritico(elementos, n);

    cout << endl;
    cout << "Elemento de mayor factor de Utilizacion: " << endl;
    cout << endl;
    cout << "Codigo: " << masCritico->codigo << endl;
    cout << "Nombre: " << masCritico->nombre << endl;
    cout << "Longitud: " << masCritico->longitud << endl;
    cout << "Carga 1: " << masCritico->cargas[0] << endl;
    cout << "Carga 2: " << masCritico->cargas[1] << endl;
    cout << "Carga 3: " << masCritico->cargas[2] << endl;
    cout << "Capacidad Maxima: " << masCritico->capmax << endl;
    cout << "Factor de Utilizacion: " << masCritico->factor_utilizacion << endl;
    cout << "Estado de Seguridad: " << masCritico->estado_seguridad << endl;

    float porcentaje;
    cout << endl;
    cout << "Simulacion de Aumento de las Cargas " << endl;
    cout << endl;
    do
    {
        cout << "Ingrese el porcentaje deseado de incremento para el elemento critico: ";
        cin >> porcentaje;
        if (porcentaje < 0.00)
        {
            cout << "Porcentaje no valido, intente nuevamente" << endl;
        }
    } while (porcentaje < 0.00);

    aumentarCargas(*masCritico, porcentaje);

    calcularFactor(masCritico);
    determinarSeguridad(*masCritico);

    cout << endl;
    cout << "Resultados actualizados el elemento: " << endl;
    cout << endl;
    cout << "Codigo: " << masCritico->codigo << endl;
    cout << "Nombre: " << masCritico->nombre << endl;
    cout << "Longitud: " << masCritico->longitud << endl;
    cout << "Carga 1: " << masCritico->cargas[0] << endl;
    cout << "Carga 2: " << masCritico->cargas[1] << endl;
    cout << "Carga 3: " << masCritico->cargas[2] << endl;
    cout << "Capacidad Maxima: " << masCritico->capmax << endl;
    cout << "Factor de Utilizacion: " << masCritico->factor_utilizacion << endl;
    cout << "Estado de Seguridad: " << masCritico->estado_seguridad << endl;

    return 0;
}
