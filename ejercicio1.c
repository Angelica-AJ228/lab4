#include <stdio.h>

#define numFil 3
#define numCol 3

int main() {
	int matriz[numFil][numCol] = {
		{12, 2, 4},
		{9, 3, 7},
		{10, 1, 5}

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
