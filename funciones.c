#include <stdio.h>
#include "funciones.h"
#include "string.h"

int leerCantidad(int i){ 
  int cant;
    printf("Cuantos productos va a ingresar?(escriba un numero del 1-10)\n>>");
    scanf("%d",&cant);
    if (cant<=0 || cant>10){
        printf("Debe ingresar un numero entre 1 a 10 productos\n>>");
        scanf("%d",&cant);
    }
    return cant;
}

char leerNombre(int num, int i, char producto[10][50]){
    printf ("Ingrese el nombre del producto %d:\n>>",num);
    fflush(stdin);
    fgets(producto[i],50, stdin);
    return producto[i][50];
}

float leerPrecio(int num, int i, float precio[10]){
    do{
    printf("Ingrese el precio del producto %d:\n>>",num);
    scanf("%f",&precio[i]);
    if (precio[i]<0){
        printf("El precio no puede ser negativo, por favor ingrese un precio valido \n>>");
        scanf("%f",&precio[i]);
    }
  }while (precio[i]==0);
  return precio[i];
}

void buscar(int cant, char producto [10][50], float precio[10], char buscarProducto[50]){
    int validar=0;
    int opc;
    do
    {
        printf("¿De que producto desea buscar el precio?\n>>");
        fflush(stdin);
        fgets(buscarProducto,50, stdin);
        for (int i = 0; i < cant; i++){
        if (strcmp(producto[i], buscarProducto)==0){
            printf("El precio del producto %s es: %.2f\n", buscarProducto, precio[i]);
            printf("Desea buscar el precio de otro producto?\n1.Si\n2.No\n>>");
            scanf("%d",&opc);
            validar=1;
        }  
    }
    if (validar==0){
        printf("Este producto no existe\n");
    }
    } while (opc==1);  
}

float sumaTotal(int cant, float precio[10]){
    float suma;
    int i=0;
    int cont=cant+1;
    for (int i = 0; i < cont; i++){
        suma += precio[i];
    }
    printf("La suma total de precios de todos los productos es: \n>>%.2f\n",suma);
    return suma;
}

float promedio(int cant, float suma){
    float prom;
    prom = suma/cant;
    printf("El promedio de precios de todos los productos es: \n>>%.2f\n",prom);
    return prom;
}
void mayor(int cant, char producto [10][50], float precio[10]){
    float max;
    int b;
    max=precio[0];
    b=0;
    int cont=cant+1;
    for (int i = 1; i < cont; i++){
        if (precio[i]>max)
        {
            max = precio[i];
            b=i;
        }
    }
    printf("El producto con mayor valor es %s Con un precio de %.2f.\n", producto[b],max);
}
void menor(int cant, char producto [10][50], float precio[10], int i){
    int min=0;
    for (int i = 0; i < cant; i++)
    {
        if(precio[i]< precio[min]){
            min=i;
        }
    }
    printf("El producto con menor valor es %s Con un precio de %.2f.\n",producto[min],precio[min]);
}