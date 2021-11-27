#include <stdio.h>
#include <stdlib.h>


int main(int argc, char* argv[]) {

    int i, j, nr, nc;
    int** matrix;
    FILE * input = fopen(argv[1], "r");;
    FILE * output = fopen(argv[2], "w");;
    
    if(input == NULL) {
        printf("File cannot be opened.\n");
        exit(1);
    }
	
    //Načtení dvou čísel: řádek a sloupec
    fscanf(input, "%d%d", &nr, &nc);
    //Přehození hodnot řádku a sloupce
    fprintf(output, "%d %d\n", nc, nr);

    //Dynamické pole pro řádek
    matrix = (int**)malloc(sizeof(int*) * nr);
    for(int i = 0; i < nr; i++) {
        //Dynamické pole pro sloupec
        matrix[i] = (int*)malloc(sizeof(int) * nc);
    }

    //Načtení hodnot z matice
    for(i = 0; i < nr; i++) {
        for(j = 0; j < nc; j++) {
            fscanf(input, "%d", &matrix[i][j]);
        }
    }
	
    //Vypsání transpozice
    for(j = 0; j < nc; j++) {
        for(i = 0; i < nr; i++) {
            fprintf(output, "%d ", matrix[i][j]);
        }
        fprintf(output, "\n");
    }

    //Uvolnění paměti dynamického pole
    for(int i = 0; i < nr; i++) {
        free(matrix[i]);
    }
    free(matrix);
    matrix = NULL;
    
    return 0;
}