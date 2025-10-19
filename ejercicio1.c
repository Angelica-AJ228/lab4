#include <stdio.h>

#define numFil 3
#define numCol 3

int main() {
	int matriz[numFil][numCol] = {
		{12, 2, 4},
		{9, 1, 7},
		{10, 1, 5}

	};

	int arreglo[numFil * numCol];
	int *matriz = &matriz[0][0];
	int *arreglo = arreglo;

	for (int i = 0; i < numFil * numCol; i++) {
		*(arreglo + i) = *(matriz + i);
	}


	for (int i = 0; i < numFil * numCol -1; i++) {
		for (int j = 0; j < numFil * numCol - i - 1; j++) {
			if (*(arreglo + j) < *(arreglo + j + 1)) {
				int aux = *(arreglo + j);
				*(arreglo + j) = *(arreglo + j + 1);
				*(arreglo + j + 1) = aux;
			}
		}
	}

	for (int = 0; i < numFil * numCol; i++) {
		*(matriz + i) = (arreglo + i);
	}

	printf("Matriz de tamano %dx%d:\n", numFil, numCol);
	for (int i = 0; i < numFil; i++) {
		for (int j = 0; j < numCol; j++) {
			print("%d ", matriz[i][j]);
		}
		printf("\n");
	}

	return 0;
}	
