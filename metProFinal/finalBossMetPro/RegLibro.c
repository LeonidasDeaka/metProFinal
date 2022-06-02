#include <stdio.h>
#include <string.h>
#include "datos.h"

int Menu()
{
    int op;
    printf("1. Agregar\n");
    printf(" Opcion: ");
    scanf("%i", &op);
    switch (op)
    {
    case 0:
        printf("Adios...\n");
        break;
    case 1:
        /* code */
        guardarLibro();
        system("pause");
        break;

    default:
        break;
    }
    return op;
}

int guardarLibro()
{
    Libro regLibro;
    printf("Codigo: ");
    scanf(" %[^\n]", regLibro.isbn);
    printf("Nombre: ");
    scanf(" %[^\n]", regLibro.titulo);
    printf("Autor: ");
    scanf(" %[^\n]", regLibro.autor);
    printf("Precio: ");
    scanf("%f", &regLibro.precio);
    printf("Existencia: ");
    scanf("%i", &regLibro.cantidad);

    FILE *LibroFile;

    LibroFile = fopen("Libros.bin", "a");

    fwrite(&regLibro, sizeof(Libro), 1, LibroFile);
    fclose(LibroFile);

    return 1;
}

