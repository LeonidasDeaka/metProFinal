#include<stdio.h>
#include"RegLibro.c"

int Menu();

int main(int argc, char const *argv[])
{
	int opcion;
	do
	{	
		opcion = Menu();
	} while (opcion!=0);
	
	return 0;
}


