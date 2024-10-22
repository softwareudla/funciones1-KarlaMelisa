#include <stdio.h>
#include "funciones.h" 
#include "string.h"
int main (int argc, char *argv[]) {
    char producto [10][50];
    float precio[10];
    char buscarProducto [50];
    float suma, b;
    int cant;
    char a; 
    //Ingresamos los nombres de los productos y sus precios
    //leerCantidad(0);
    cant=leerCantidad(0);

    for (int i = 0; i < cant; i++){
        a=leerNombre(i+1, i, producto);
        producto[i][50]=a;
        b=leerPrecio(i+1, i, precio);
        precio[i]=b;
    }

    suma=sumaTotal(cant, precio);

    promedio(cant, suma);

    mayor(cant, producto, precio);

    menor(cant, producto, precio, 1);

    buscar(cant, producto, precio, buscarProducto);
    return 0;
}