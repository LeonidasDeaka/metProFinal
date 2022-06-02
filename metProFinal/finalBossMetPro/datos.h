typedef struct{
    char isbn[10];
    char titulo[50];
    char autor[30];
    float precio;
    int cantidad;
}Libro;

typedef struct{
    char libro[50];
    float precio;
    int cant;
    int dias;
}DetFact;

typedef struct{
    int id;
    char fecha[10]; //26/05/2022
    char cliente[100];
    DetFact detalle[10];
}Factura;