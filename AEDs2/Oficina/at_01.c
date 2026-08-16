#include <stdio.h>
#include <stdlib.h>

void insertValues(char* nome_arquivo, int length, int* valores){
	FILE* arquivo = fopen(nome_arquivo,"at");
	for(int i = 0; i < length; i = i + 1){
		fprintf(arquivo,"%d ",valores[i]);
	}
	fprintf(arquivo,"\n");	
	fclose(arquivo);
}

int main(){
	int length = 0;
	int index = 0;
	char lixo[100];
	FILE* arquivo_ler = fopen("input.txt","rt");

	while(!feof(arquivo_ler)){
		if(!fscanf(arquivo_ler,"%d",&length)){
			fgets(lixo,100,arquivo_ler);
		} else {
			int* values = (int*) malloc(sizeof(int)*length);
			int valorAtual = 0;
			for(int i = 0; i < length; i = i + 1){
				if(!fscanf(arquivo_ler,"%d",&valorAtual)){
					fgets(lixo,100,arquivo_ler);
				}else values[i] = valorAtual;
				index = index + 1;
			}
			insertValues("output.txt",length,values);
			free(values);
		}
		index = index + 1;
	}

	return 1;
}
