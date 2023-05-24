/*
* author: Gonçalo Malheiro
* brief: Ficheiro que engloba todas as funcões utilizadas
* descricao: Trabalho Prático Estruturas De Dados Avançadas, 2 Fase
* data: Maio de 2023
*/

#include "Estrutura.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#pragma warning(disable: 4996)

#pragma region funcoesclientes

/*
 * Entra o grafo,o nome do cliente, a localização do novo cliente e o numero de cliente do novo meio
 * A função insere o cliente na localização passado por parâmetro
 * Devolve 1 em caso de sucesso ou 0 caso contrário
*/

int inserirCliente(Grafo g, char nome[], char localizacaocliente[], int numcliente)
{
	while ((g != NULL) && (strcmp(g->vertice, localizacaocliente) != 0))
		g = g->seguinte;

	if (g == NULL)
		return(0);

	else {
		Cliente novo = malloc(sizeof(struct registoCliente));
		strcpy(novo->nome, nome);
		strcpy(novo->localizacao, localizacaocliente);
		novo->numcliente = numcliente;
		novo->seguinte = g->cliente;
		g->cliente = novo;
		return(1);
	}
}

/*
  *Entra o grafo e o geocodigo no qual iremos ver os clientes que exitem nessa localização
  *Lista os nomes dos clientes e o número de cliente dos clientes presente numa dada localização passada por parâmetro
 */

void listarClientes(Grafo g, char localização[])
{
	while ((g != NULL) && (strcmp(g->vertice, localização) != 0))
		g = g->seguinte;

	if (g != NULL)
	{
		Cliente aux = g->cliente;
		if (aux == NULL)
			printf("\nNa localizacao indicada nao existem clientes \n\n");

		else while (aux != NULL)
		{
			printf("\nNome cliente: %s\nNumero de Cliente: %d\n", aux->nome, aux->numcliente);
			aux = aux->seguinte;
		}
	}
	else printf("\nLocalizacaoo inexistente\n");
}

/*
  *Entra o grafo
  *A função guarda no ficheiro de texto os clientes na lista ligada
  *Devolve 1 caso guarde com sucesso e 0 caso haja algum erroS
 */

int guardarClientes(Grafo g) {

	FILE* fp = fopen("clientes2.txt", "w");
	if (fp == NULL) {
		return 0;
	}

	while (g != NULL) {
		Cliente aux = g->cliente;

		while (aux != NULL) {
			fprintf(fp, "%s;%s;%d;\n", aux->nome, aux->localizacao, aux->numcliente);
			aux = aux->seguinte;
		}

		g = g->seguinte;
	}

	fclose(fp);
	return 1;
}

/*
  *Entra o grafo
  *A função lê os clientes que se encontram guardados no ficheiro de texto e adiciona-os ao grafo
  *Devolve 1 caso consiga ler e 0 caso haja algum erro na leitura
 */

int lerClientes(Grafo g)
{
	FILE* fp;
	int numcliente;
	char nome[50], localizacao[50];
	fp = fopen("clientes2.txt", "r");
	if (fp != NULL)
	{
		while (fscanf(fp, "%[^;];%[^;];%d;\n", nome, localizacao, &numcliente) == 3)
		{
			inserirCliente(g, nome, localizacao, numcliente);
		}
		fclose(fp);
		return 1;
	}
	return 0;
}



#pragma endregion


#pragma region funcoesmeios

/*
   *Entra o grafo, o geocodigo do novo meio e o codigo do novo meio
   *A função insere o  meio de transporte na localização com geocódigo passado por parâmetro
   *Devolve 1 em caso de sucesso ou 0 caso contrário
 */

int inserirMeio(Grafo g, char tipotransporte[], char geocodigo[], int codigoMeio, float bateria)
{
	while ((g != NULL) && (strcmp(g->vertice, geocodigo) != 0))
		g = g->seguinte;

	if (g == NULL)
		return(0);

	else {
		Meio novo = malloc(sizeof(struct registoMeios));
		strcpy(novo->tipotransporte, tipotransporte);
		strcpy(novo->geocodigo, geocodigo);
		novo->codigo = codigoMeio;
		novo->bateria = bateria;
		novo->seguinte = g->meios;
		g->meios = novo;
		return(1);
	}
}

/*
   *Entra o grafo e o geocodigo no qual iremos ver quais meios que existem nessa determinada localização
   *Lista os códigos dos meios de transporte numa determinada localização passada por parâmetro
 */

void listarMeios(Grafo g, char geocodigo[])
{
	while ((g != NULL) && (strcmp(g->vertice, geocodigo) != 0))
		g = g->seguinte;
	if (g != NULL)
	{
		Meio aux = g->meios;
		if (aux == NULL) printf("\n\nSem meios de transporte\n");
		else while (aux != NULL)
		{
			printf("\nCodigo meio de transporte: %d \nTipo do meio de transporte: %s \nNivel de bateria: %.2f\n\n", aux->codigo, aux->tipotransporte, aux->bateria);
			aux = aux->seguinte;
			printf("========================================\n");
		}
	}
	else printf("\nEssa localizacao nao existe no grafo\n");
}

/*
  *Entra o grafo
  *A função guarda os meios na lista ligada
  *Devolve 1 em caso de sucesso e 0 caso haja algum erro
 */

int guardarMeios(Grafo g) {

	FILE* fp = fopen("meios2.txt", "w");

	if (fp == NULL) {
		return 0;
	}
	while (g != NULL) {
		Meio aux = g->meios;

		while (aux != NULL) {
			fprintf(fp, "%s,%s,%d,%.2f\n", aux->tipotransporte, aux->geocodigo, aux->codigo, aux->bateria);
			aux = aux->seguinte;
		}
		g = g->seguinte;
	}

	fclose(fp);
	return 1;
}

/*
   *Entra o grafo
   *A função lê os meios no ficheiro de texto de seguida insere os meios no grafo.
   *Devolve 1 em caso de sucesso e 0 caso contrario
 */

int lerMeios(Grafo g) {

	FILE* fp;
	int cod;
	char tipotransporte[50], geocodigo[50];
	float bateria;
	fp = fopen("meios2.txt", "r");

	if (fp != NULL)
	{
		while (!feof(fp))
		{
			fscanf(fp, "%[^;];%[^;];%d;%.2f;\n", tipotransporte, geocodigo, &cod, &bateria);
			inserirMeio(g, tipotransporte, geocodigo, cod, bateria);
		}
		fclose(fp);
		return (1);
	}
	return(0);
}

/*
   *Entra o grafo, a distancia maxima a que um meio pode estar do cliente e a localização do cliente
   *A função vê se a localização indicada existe no grafo, para isso compara os vertices existentes no grafo com a localização
   de seguida percore o grafo ate chegar ao vertice com a determinada localização, depois compara a distancia desse vertice com os adjacentes
   com a distancia indicada e se estiverem entre 0 e o maximo da distancia, os vertices dos meios seram listados
 */

void listarDistancia(Grafo g, float distancia, char localizacao[], char tipotranporte[])
{
	Meio aux3;
	Adjacentes aux2;
	Grafo vertice;
	int encontrado = 0;
	if (existeVertice(g, localizacao))
	{
		while (strcmp(g->vertice, localizacao) != 0)
		{
			g = g->seguinte;
		}
		vertice = g->vertice;
		aux3 = vertice->meios;
		aux2 = g->adjacentes;
		while (aux2 != NULL)
		{
			if (aux2->peso <= distancia && strcmp(aux3->tipotransporte, tipotranporte) == 0)
			{
				printf("\nNome do meio de transporte: %s \nNivel de bateria: %.2f \nLocalizacao: %s \n", aux3->tipotransporte, aux3->bateria, aux3->geocodigo);
				encontrado = encontrado + 1;
				aux2 = aux2->seguinte;
			}
			if (aux2 != NULL)
			{
				vertice = aux2->vertice;
				aux3 = vertice->meios;
			}
		}
		if (encontrado == 0)
		{
			printf("\nNao existem meios de transporte num raio de %.2f\n", distancia);
		}
	}
	else
	{
		printf("\nO vertice referido nao existe\n");
	}
}
#pragma endregion

#pragma region funcoeslocalizoes 

/*
  *Entra o endereço inicial do grafo e o nome do novo vertice
  *Um grafo auxiliar irá guardar o nome do novo vertice, os meios exitentes nesse vertice
   depois irá guardar no endereço seguinte o endereço inicial do grafo ja existente e o endereço inicial do grafo para o endereço inicial do novo vertice.
  * Devolve 1 em caso de sucesso ou 0 caso contrário
 */

int criarVertice(Grafo* g, char novoid[])
{
	Grafo novo = malloc(sizeof(struct registoGrafo));
	if (novo != NULL)
	{
		strcpy(novo->vertice, novoid);
		novo->meios = NULL;
		novo->cliente = NULL;
		novo->seguinte = *g;
		novo->adjacentes = NULL;
		*g = novo;
		return(1);
	}
	else return(0);
}

/*
  *Entra o grafo e o vertice que queremos procurar
  *A função irá comparar os vertices exitentes no grafo, com o que pretendemos
   *Devolve 1 se o vertice existe no grafo ou 0 caso contrário
 */

int existeVertice(Grafo g, char vertice[])
{
	while (g != NULL)
	{
		if (strcmp(g->vertice, vertice) == 0)
			return(1);
		else
			g = g->seguinte;
	}
	return(0);
}

/*
   *Entra o grafo, o vertice de origem e de destino da aresta que pretendemos e o peso da aresta
   *A função cria uma aresta,verifica se os vertices pedidos existem, caso existem cria uma aresta
   *Devolve 1 em caso de sucesso ou 0 caso contrário
 */

int criarAresta(Grafo g, char vOrigem[], char vDestino[], float peso)
{
	Adjacentes novo;
	if (existeVertice(g, vOrigem) && existeVertice(g, vDestino))
	{
		while (strcmp(g->vertice, vOrigem) != 0)
			g = g->seguinte;
		novo = malloc(sizeof(struct registoAdjacentes));
		if (novo != NULL)
		{
			strcpy(novo->vertice, vDestino);
			novo->peso = peso;
			novo->seguinte = g->adjacentes;
			g->adjacentes = novo;
			return(1);
		}
		else return(0);
	}
	else return(-1);
}

/*
   *Entra o grafo e o vertice no qual queremos ver os adjacenetes
   *A função verifica a existencia do vertice no grafo de seguida lista os adjacentes
 */

void listarAdjacentes(Grafo g, char vertice[])
{
	Adjacentes aux;
	if (existeVertice(g, vertice))
	{
		while (strcmp(g->vertice, vertice) != 0)
			g = g->seguinte;
		aux = g->adjacentes;
		if (aux == NULL)
		{
			printf("\nO vertice do grafo indicado nao contem adjacentes\n");
		}
		while (aux != NULL)
		{
			printf("\nAdjacente: %s , Peso: %.2f\n", aux->vertice, aux->peso);
			aux = aux->seguinte;
		}

	}
	else
	{
		printf("\nO vertice indicado nao existe\n\n");
	}
}

/*
	*Entra o grafo
	*A função guarda num ficheiro de texto os vertices do grafo e os adjacntes a esses vertices, e tambem o peso das arestas
	*Devolve 1 em caso de sucesso ou 0 caso contrario
 */

int guardarGrafo(Grafo g) {
	FILE* fp;
	fp = fopen("grafo.txt", "w");
	if (fp == NULL) {
		return 0;
	}
	while (g != NULL) {
		Adjacentes adj = g->adjacentes;

		while (adj != NULL) {
			fprintf(fp, "%s;%s;%.2f\n", g->vertice, adj->vertice, adj->peso);
			adj = adj->seguinte;
		}
		g = g->seguinte;
	}

	fclose(fp);
	return 1;
}

/*
	*Entra o apontador para o inicio do grafo e o conteudo do grafo
	*A função lê o conteudo do ficheiro e guarda os diferentes parametros em variaveis, de seguida cria os vertices no grafo
	e as arestas com os diferentes pesos entre os vertices
	*Retorna 1 em caso de sucesso e 0 em caso de erro
 */

int lerGrafo(Grafo* g, Grafo* g1) {

	FILE* fp;
	char vertice[50], verticeadjacente[50];
	float peso;

	fp = fopen("grafo.txt", "r");

	if (fp == NULL || g == NULL || g1 == NULL) {
		return 0;
	}

	while (fscanf(fp, "%49[^;];%49[^;];%d;%f;\n", vertice, verticeadjacente, &peso) == 4) {
		criarVertice(g1, vertice);
		criarAresta(g, vertice, verticeadjacente, peso);
	}

	fclose(fp);
	return 1;
}
#pragma endregion
