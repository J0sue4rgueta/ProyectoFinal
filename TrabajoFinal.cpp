#include "iostream"
#include "string"
#include "iomanip" //Para tener dos decimales en los precios

const int longCad = 20;

using namespace std;

struct Articulo
{
    char nombreArticulo[longCad + 1];
    int cant;
    float prec;
    float cost;
    float ttl;
    
};

void DefinirArreglo(string [ ], float [ ], int [ ], int);
void DefinirPrecio(float [ ], float [ ], int [ ], int);
void ImprimirArreglo(string [ ], float [ ], int [ ], float [ ], int);
void DefinirTotal(float [], float [], int);

int main(void)
{
    string producto[100];
    int n = 0, cantidad[100];
    float valor[100], precio[100], total[1];

    cout << "\n-----CAJA REGISTRADORA-----\n\n";
    
    cout << "Introduzca la cantidad de productos vendidos: ";
    cin >> n;
    cout << endl;

    DefinirArreglo(producto, valor, cantidad, n);
    cout << "---------------------------\n";

    DefinirPrecio(precio, valor, cantidad, n);
    system("cls"); //Borra todo el proceso anterior para mostrar el resto en limpio (estetico)

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////

    cout << "\n-----CAJA REGISTRADORA-----\n";
    ImprimirArreglo(producto, valor, cantidad, precio, n);
    cout << "---------------------------\n";
    cout << endl;

    DefinirTotal(total, precio, n);
    /*Muestra el elemento almacenado en total que es el resultado de "DefinirTotal()"*/
    cout << "TOTAL A COBRAR: $ " << total[0] << "\n\n";
    cout << "GRACIAS POR SU COMPRA" << "\n\n";

    return 0;
}

/*Se encarga de asignarle los elementos a cada array*/
void DefinirArreglo(string x[ ], float y[], int z[], int n)
{   
    int i;

    for(i = 0; i < n; i++)
    {
        cout << "---------------------------\n";
        cout << "Introduzca nombre del producto: ";
        cin >> x[i];

        cout << "Introduzca el precio del producto: $ ";
        cin >> y[i];

        cout << "Introduzca la cantida: ";
        cin >> z[i];

        cout << endl;
    }
}

/*Multiplica el valor de los productos por la cantida que compra*/
void DefinirPrecio(float x[ ], float y[ ], int z[ ], int n)
{
    int i;

    for(i = 0; i < n; i++)
    x[i] = y[i] * z[i];
      
}

/*Muestra en formato ticket los elementos de los array*/
void ImprimirArreglo(string x[ ], float y[ ], int z[ ], float w[ ], int n)
{
    int i;

    for(i = 0; i < n; i++)
    {
        cout << "---------------------------\n";
        cout << "ARTICULO: " << x[i] << endl;   
        cout << "PRECIO: $ " << fixed << setprecision(2) << y[i] << endl; //setprecision y fixed para decimales
        cout << "UNIDADES: " << z[i] << endl;
        cout << endl;
        cout << "TOTAL: $ " << fixed << setprecision(2) << w[i];

        cout << endl;
    }
}

/*Suma los precios totales y le asigna el total a un array del total*/
void DefinirTotal(float x[], float y[], int n)
{
    int i;
    float z;

    for (i = 0; i < n; i++)
    z += y[i];
    
    x[0] = z;
}

