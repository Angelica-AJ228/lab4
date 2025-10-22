#include <stdio.h>

#define numFil 5
#define numCol 5

int main() {
	int matriz[numFil][numCol] = {
		{123, 21, 24, 89, 78},
		{91, 13, 17, 12, 1},
		{20, 11, 54, 67, 3},
		{34, 8, 22, 45, 14},
		{9, 30, 100, 4, 87}

	};

	int *punt_matr = &matriz[0][0]; //empieza en el primer elemento
	
	printf("Matriz original:\n");
	for (int i = 0; i < numFil; i++) {
		for (int j = 0; j < numCol; j++) {
			printf("%d ", matriz[i][j]);
		}
		
		printf("\n");
	}
	
	printf("\n");


	for (int i = 0; i < numFil * numCol -1; i++) {
		for (int j = 0; j < numFil * numCol - i - 1; j++) {
			if (*(punt_matr + j) > *(punt_matr + j + 1)) { //estaba comparando mal, corregir usando > en lugar de <
				int aux = *(punt_matr + j);
				*(punt_matr + j) = *(punt_matr + j + 1);
				*(punt_matr + j + 1) = aux;
			}
		}
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
