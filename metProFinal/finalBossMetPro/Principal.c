#include<stdio.h>
#include "Factura.c"


void LlenarDatosFact();

int main(int argc, char const *argv[])
{
	int op;

	do
	{
		printf("Elija la opcion que desee\n ");
		printf(" 1. Realizar venta\n 2. Realizar Alquiler\n 3. Salir\n");
		scanf("%i", &op);

		switch (op)
		{
		case 1:
			LlenarDatosFact();
			break;
		case 2:
			llenarDatosFactAlquiler();
			break;
		case 3:
			printf("");
			break;
		default:
			printf("Ingrese una opcion valida");
			break;
		}
	} while (op!=3);
	
	
	return 0;
}


