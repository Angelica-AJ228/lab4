#include <stdio.h>
#include <string.h>

#define max 256

char convertir_minus(char c) {
	if (c >= 'A' && c <= 'Z') return c + 32;
	return c;
}

int comparar(const char *a, const char *b) {
	int i = 0;
	while (a[i] != '\0' && b[i] != '\0') {
		if (convertir_minus(a[i]) != convertir_minus(b[i])) return 0;
		i++;
	}
	return (a[i] == '\0' && b[i] == '\0');
}

int puntuacion(char c) {
	return (c == '.' || c == ',' || c == ';' || c == ':' || c == '!' || c == '?' || c == '"' || c == '\' || c == '(' || c == ')' || c == '[' || c == ']' || c == '{' || c == '}' || c == '¿' || c == '¡');



int main(int argumento, char *argu[]) {
	if (argumento != 4) {
		printf("Uso: %s <archivo_entrada> <palabra_buscar> <reemplazo>\n", argu[0]);
		return 0;
	}

	FILE *entra = fopen(argu[1], "r");
	if (entra == NULL) {
		printf("Error: no se puedo abrir.\n");
		fclose(entra)
		return 0;
	}


	FILE *sal = fopen("reemplazo.txt", "w");
	if (sal == NULL) {
		printf("Error: no se pudo crear el archivo.\n");
		fclose(sal);
		return 0;	
	}

	char wrd[max];
	char limpiar[max];
	char *buscar = argu[2];
	char *reemplazo = argu[3];
	char core[max];

	while (fscanf(entra, "%s", wrd) == 1) {
		int len = strlen(wrd);
		int inicio = 0;
		int fin = len - 1;


		while (inicio < len && puntuacion(wrd[inicio])) {
			inicio++;
		}

		while (inicio >= 0 && puntuacion(wrd[fin])) {
			fin--;
		}

		if (fin < inicio) {
			fprintf(sal, "%s ", wrd);
			continue;
		}

		int j = 0;
		for (int i = inicio; i <= fin && j < max - 1; i++) {
			core[j++] = wrd[i];
		}

		core[i] = '\0';

		if (comparar(core, buscar)) {
			for (int i = 0; i < inicio; i++) {
				fputc(wrd[i], sal);
			}

	fclose(entra);
	fclose(sal);

	printf("Palabra reemplazada exitosamente en archivo: reemplazo.txt\n");
	return 0;

}
