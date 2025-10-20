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
	int *punt_matr = &matriz[0][0];
	int *punt_arre = arreglo;
	
	printf("Matriz original:\n");
	for (int i = 0; i < numFil; i++) {
		for (int j = 0; j < numCol; j++) {
			printf("%d ", matriz[i][j]);
		}
		
		printf("\n");
	}
	
	printf("\n");

	for (int i = 0; i < numFil * numCol; i++) {
		*(punt_arre + i) = *(punt_matr + i);
	}


	for (int i = 0; i < numFil * numCol -1; i++) {
		for (int j = 0; j < numFil * numCol - i - 1; j++) {
			if (*(punt_arre + j) > *(punt_arre + j + 1)) { //estaba comparando mal, corregir usando > en lugar de <
				int aux = *(punt_arre + j);
				*(punt_arre + j) = *(punt_arre + j + 1);
				*(punt_arre + j + 1) = aux;
			}
		}
	}

	for (int i = 0; i < numFil * numCol; i++) {
		*(punt_matr + i) = *(punt_arre + i);
	}

	printf("Matriz ordenada de tamano %dx%d:\n", numFil, numCol);
	for (int i = 0; i < numFil; i++) {
		for (int j = 0; j < numCol; j++) {
			printf("%d ", matriz[i][j]);
		}
		printf("\n");
	}

	return 0;
}
