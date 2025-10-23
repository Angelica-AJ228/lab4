#include <stdio.h>
#include <string.h>

int main(int argumento, char *argumento[]) {
	if (argumento != 4) {
		printf("Uso: %s <archivo_entrada> <palabra_buscar> <reemplazo>\n", argumento[0]);
		return 1;
	}

	FILE *entra = fopen(argumento[1], "r");
	if (!entra) {
		printf("Error: no se puedo abrir.\n");
		return 1;
	}


	FILE *sal = fopen("reemplazo.txt", "w");
	if (!sal) {
		printf("Error: no se pudo crear el archivo.\n");
		fclose(entra);
		return 1;	
	}

	char wrd[100];
	char limpiar[100];
	char *buscar = argumento[2];
	char *reemplazo = argumento[3];

	while (fscanf(entra, "%s", wrd) == 1) {
		strcpy(limpiar, wrd);
		int len = strlen(limpiar);
		if (limpiar[len - 1] == '.' || limpiar[len - 1] == ',') {
			limpiar[len - 1] = '/0';
		}

