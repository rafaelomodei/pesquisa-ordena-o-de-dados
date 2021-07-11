#include <stdio.h>
#include <stdlib.h>

#include "file.h"
#include "../style/styles.h"

int createFile(){

    FILE* fileOrderly, *fileInverted, *fileRandom;
    int sizeArray = 0, i=0;

    fileOrderly = fopen(inputFileOrderly,"w");
    fileInverted = fopen(inputfileInverted,"w");
    fileRandom = fopen(inputfileRandom,"w");

    if(fileOrderly == NULL || fileInverted == NULL || fileRandom == NULL){
        printf("  ERRO AO OPERAR OS ARQUIVOS!\n");
        return 1;
    }

    
    printf("\n");
    printf("%s Quantos elemento deseja criar ? \n", MARGIN);
    printf("%s Exemplo: 1000000 \n", MARGIN);
    printf("\n > ");
    scanf("%d", &sizeArray);

    while(i< sizeArray){
       fprintf(fileOrderly, "%d ", i);
       i++;
    }
    i--;
    while(i>=0){
       fprintf(fileInverted, "%d ", i);
       i--;
    }
    i++;
    while(i< sizeArray){
       fprintf(fileRandom, "%d ", rand() % sizeArray);
       i++;
    }

    fclose(fileOrderly);
    fclose(fileInverted);
    fclose(fileRandom);

    return sizeArray;
}


int* readFile(int sizeArray, char fileName[]){

    FILE* file;

    file = fopen(fileName, "r");
    if(file == NULL){
        printf("Erro, nao foi possivel abrir o arquivo\n");
    }

    int *array;
    array = (int *) malloc (sizeArray * sizeof(int));
    int i =0;

    while((fscanf(file,"%d ",&array[i]))!= EOF){
        i++;
    }

    fclose(file);

    return array;
}

int writeFile(int *array, int sizeArray ,char fileName[]){

    int i;
    FILE* file;
    file = fopen(fileName,"w");
    for(i = 0; i<sizeArray; i++ ){
        fprintf(file, "%d ", array[i]);
    }
    fclose(file);

    return 0;
}