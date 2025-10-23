#include <stdio.h>
#include <string.h>

int main(int argumento, char *argu[]) {
	if (argumento != 4) {
		printf("Uso: %s <archivo_entrada> <palabra_buscar> <reemplazo>\n", argu[0]);
		return 1;
	}

	FILE *entra = fopen(argu[1], "r");
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
	char *buscar = argu[2];
	char *reemplazo = argu[3];

	while (fscanf(entra, "%s", wrd) == 1) {
		int j = 0;
		for (int i = 0; wrd[i] != '\0'; i++) {
			if (wrd[i] != '.' && wrd[i] != ',' && wrd[i] != '!' && wrd[i] != '?') {
				limpiar[j] = wrd[i];
				j++;
			}

		}

		limpiar[j] = '\0';

		if (strcmp(limpiar, buscar) == 0) {
			fprintf(sal, "%s ", reemplazo);
		} else {
			fprintf(sal, "%s ", wrd);
		}

	}

	fclose(entra);
	fclose(sal);

	printf("Palabra reemplazada exitosamente en archivo: reemplazo.txt\n");
	return 0;

}
