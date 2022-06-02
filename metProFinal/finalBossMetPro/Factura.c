#include <stdio.h>
#include "datos.h"

float calcularTotal(float precio, int cantidad)
{
    return precio * cantidad;
}

float calcularAlquiler(float precio, int dias)
{

    return precio * dias;
}

float calcularIva(float total)
{
    return total * 0.15;
}

float calcularMonto(float total, float iva)
{
    return total + iva;
}

void llenarDatosFactAlquiler()
{
    int i = 0;

    Factura fac;
    printf("ID factura: ");
    scanf("%i", &fac.id);
    printf("Fecha: ");
    scanf(" %[^\n]", fac.fecha);
    printf("Cliente: ");
    scanf(" %[^\n]", fac.cliente);

    printf("Producto: ");
    scanf(" %[^\n]", fac.detalle[i].libro);
    printf("Precio: ");
    scanf("%f", &fac.detalle[i].precio);
    printf("Dias: ");
    scanf("%i", &fac.detalle[i].dias);

    mostrarFactAlquiler(fac, i);
}

void LlenarDatosFact()
{
    Factura fac;
    printf("ID factura: ");
    scanf("%i", &fac.id);
    printf("Fecha: ");
    scanf(" %[^\n]", fac.fecha);
    printf("Cliente: ");
    scanf(" %[^\n]", fac.cliente);

    int op, i = 0;

    do
    {
        printf("Producto: ");
        scanf(" %[^\n]", fac.detalle[i].libro);
        printf("Precio: ");
        scanf("%f", &fac.detalle[i].precio);
        printf("Cantidad: ");
        scanf("%i", &fac.detalle[i].cant);
        i++;
        printf("Desea registrar otro producto? 1.Si o 2.No ");
        scanf("%i", &op);
        if (i == 10)
        {
            printf("Error: no puede agregar mas de 10 productos");
            op = 2;
        }

    } while (op != 2);
    printf("Desea mostrar la factura? 1.Si o 2.No ");
    scanf("%i", &op);
    if (op == 1)
    {
        mostrarFactura(fac, i);
    }
}

void mostrarFactura(Factura fac, int filas)
{
    printf("ID %i \n", fac.id);
    printf("Fecha  %s\n", fac.fecha);
    printf("Cliente %s\n", fac.cliente);
    printf("-----------------------------------------------------\n");
    float subTotal = 0;
    for (int i = 0; i < filas; i++)
    {
        float total = calcularTotal(fac.detalle[i].precio, fac.detalle[i].cant);
        subTotal += total;
        printf("%s\t %.2f\t %i\t %.2f \n", fac.detalle[i].libro, fac.detalle[i].precio, fac.detalle[i].cant, total);
    }
    float iva = calcularIva(subTotal);
    float monto = calcularMonto(subTotal, iva);
    printf("Sub Total: %.2f\n", subTotal);
    printf("IVA: %.2f\n", iva);
    printf("Monto: %.2f\n", monto);
}

void mostrarFactAlquiler(Factura fac, int filas)
{
    int i=0;
    
    printf("ID %i \n", fac.id);
    printf("Fecha  %s\n", fac.fecha);
    printf("Cliente %s\n", fac.cliente);
    printf("-----------------------------------------------------\n");
    float subTotal = 0;

    float total = calcularAlquiler(fac.detalle[i].precio, fac.detalle[i].dias);
    subTotal += total;
    printf("%s\t %.2f\t %i\t %.2f \n", fac.detalle[i].libro, fac.detalle[i].precio, fac.detalle[i].dias, total);

    float iva = calcularIva(subTotal);
    float monto = calcularMonto(subTotal, iva);
    printf("Sub Total: %.2f\n", subTotal);
    printf("IVA: %.2f\n", iva);
    printf("Monto: %.2f\n", monto);
}
