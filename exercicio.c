#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "grafos.c"

int main(){
	
	setlocale(LC_ALL, "");
	nodetype *grafo = NULL;
	
	FILE * arquivo;
	int qt_cidade, origem, destino, i, ini, fim, tamanho;
	
	//abre arquivo em modo read
	arquivo = fopen("cidades.txt", "r");
	
	//lê primeira linha de quantidade de cidades
	fscanf(arquivo, "%d\n", &qt_cidade);
	
	//cria os nodes do grafo
	grafo = getnode(0);
	
	for(i = 1; i < qt_cidade; i++){
		addnode(grafo, i);
		//printf("%d\n", i);
	}
	
	//lê o resto do arquivo e monta as arestas dos vertices
	while(!feof(arquivo)){
		fscanf(arquivo, "%d %d\n", &origem, &destino);
		join(grafo, origem, destino);
	}
	//fecha o arquivo pós leitura
	fclose(arquivo);

	//Entrando com dados
	while(1){
		printf("Digite a cidade de origem (0-%d): ", (qt_cidade - 1));
		scanf("%d", &ini);
		
		printf("Digite a cidade de origem (0-%d): ", (qt_cidade - 1));
		scanf("%d", &fim);
		
		//Caminho mais curto
		if (shortpath(grafo, ini, fim, &tamanho))
			printf("O menor caminho tem tamanho: %i!\n\n", tamanho);
		else
			printf("Não existe um caminho!\n\n");
	}
	
	return 0;
}

