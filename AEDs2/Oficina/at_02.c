#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Pessoa{
	char nome[50];
	int idade;
} Pessoa;  

Pessoa* create_Pessoa(char n[50],int i){
	Pessoa* p = (Pessoa*) malloc(sizeof(Pessoa));
	strcpy(p->nome,n);
	if(i > 0) p->idade = i; else p->idade = 0;
	return p;
}

Pessoa* ler_Pessoa(){
	char nome[50];
	int idade = 0;
	Pessoa* p;

	if(scanf("%s",nome)){
		if(scanf("%d",&idade)){
			p = create_Pessoa(nome,idade);
		}
	}
	return p;
}

int main(){
	int length = 0;

	while(scanf("%d",&length) != EOF){
		Pessoa** p = (Pessoa**) malloc(sizeof(Pessoa*)*length);
		int menor = 0;
		Pessoa* temp;
		for(int i = 0; i < length; i = i + 1){
			p[i] = ler_Pessoa();
		}
		for(int i = 0; i < length - 1; i = i + 1){
			menor = i;
			for(int j = i + 1; j < length; j = j + 1){
				if(p[j]->idade < p[menor]->idade){
					menor = j;
				}
			}
			temp = p[i];
			p[i] = p[menor];
			p[menor] = temp;
		}
		for(int i = 0; i < length; i = i + 1){
			printf("%s\n", p[i]->nome);
		}
	}
	
	return 1;
}
