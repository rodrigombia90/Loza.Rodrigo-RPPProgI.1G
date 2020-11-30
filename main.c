#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define TAM 4
typedef struct
{
    int id;
    char procesador[10];
    int precio;
    char marca[10];

} eNotebook;

void mostrarNotebooks(eNotebook lista[],int tam);
void mostrarNotebook(eNotebook lista);
float calcularIVA(float precio);
void ordenarNotebook(eNotebook lista[], int tam);
int reemplazarCaracter(char cadena[], char car,char carNuevo);

int main()
{
    int precio=75;
    char cadena[10]= {"antanio"};
    char caracterBusqueda= 'a';
    char caracterReemplazo= 'd';
    int reemplazo;

    eNotebook notebooks[5]= {
        {1,"intel",1500,"lenovo"},
        {2,"amd",3600,"asus"},
        {3,"celeron",2600,"bgh"},
        {4,"amd",2000,"asus"}, };

    printf("Ejercicio 1:\n");
    precio=calcularIVA(precio);
    printf("El valor del impuesto es: %d\n\n",precio);

    printf("Ejercicio 2:\n");
    reemplazo=reemplazarCaracter(cadena,caracterBusqueda,caracterReemplazo);

    printf("Cadena modificada: %s     cantidad de veces reemplazadas: %d",cadena,reemplazo);

    printf("\n\n");
    printf("Ejercicio 3:\n");
    printf("Datos sin ordenar: \n");
    mostrarNotebooks(notebooks,TAM);
    printf("\nDatos ordenados: ");
    ordenarNotebook(notebooks,TAM);
    printf("\n\n");
    mostrarNotebooks(notebooks,TAM);
     return 0;
}


float calcularIVA(float precioBruto)
{
    float rta=0;
    if(precioBruto>0)
    {
        rta=precioBruto*0.21;
    }

    return rta;
}



int reemplazarCaracter(char cadena[], char car,char carNuevo)
{
    int contador=0;
    int largo=strlen(cadena);
    for(int i=0; i<largo; i++)
    {

        if(cadena[i]==car)
        {
            cadena[i]=carNuevo;
            contador++;
        }
    }

    return contador;
}



void ordenarNotebook(eNotebook lista[], int tam)
{
    eNotebook aux;
    for(int i=0; i<tam-1; i++)
    {
        for(int j=i+1; j<tam; j++)
        {

            if(strcmp(lista[i].marca,lista[j].marca)>0)
            {
                aux=lista[i];
                lista[i]=lista[j];
                lista[j]=aux;
            }
            else if(!strcmp(lista[i].marca,lista[j].marca) && (lista[i].precio>lista[j].precio))
            {      //strcmp(lista[i].marca,lista[j].marca==0
                aux=lista[i];
                lista[i]=lista[j];
                lista[j]=aux;
            }
        }
    }
}


void mostrarNotebooks(eNotebook lista[],int tam)
{

    for(int i=0;i<tam;i++)
    {
        mostrarNotebook(lista[i]);
    }
}


void mostrarNotebook(eNotebook lista)
{
    printf("%d        %-10s    %-5d      %-8s   \n",lista.id,lista.procesador,lista.precio,lista.marca);
}
