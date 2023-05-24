/*
* author: Gonçalo Malheiro
* brief: Ficheiro onde serão demonstradas todas as funcões utilizadas
* descricao: Trabalho Pratico Estruturas De Dados Avançadas, 2 Fase
* data: Maio de 2023
*/

#include "Estrutura.h"

#pragma region menusmartcity

int menuSmartCity() {

	int opcaoPrincipal;

	printf("\n=============================================\n\n");
	printf("1. Criar um novo vertice\n");
	printf("2. Criar uma nova aresta\n");
	printf("3. Listar os vertices adjacentes\n");
	printf("4. Inserir novo meio de transporte\n");
	printf("5. Listar os meios de transporte por uma dada localizacaoo\n");
	printf("6. Inserir um novo cliente\n");
	printf("7. Listar os clientes por uma dada localizacao\n");
	printf("8. Guardar os meios de transporte\n");
	printf("9. Ler os meios de transporte\n");
	printf("10. Guardar os clientes\n");
	printf("11. Ler os clientes\n");
	printf("12. Guardar o grafo\n");
	printf("13. Ler o grafo\n");
	printf("14. Listar os meios de transporte num determinado raio a volta de um dado cliente\n");
	printf("0. Sair\n");
	printf("\n==============================================\n\n");
	printf("Escolha a opcao que pretende: ");
	scanf("%d", &opcaoPrincipal);

	return opcaoPrincipal;
}

int main() {

	Grafo g = NULL;
	int caminho[50];

	char tipoveiculo[40], geocodigo[50], localizacaoVertice[50], verticeinico[50], verticefim[50], nomecliente[50], localizacao[50];
	int codigo, numcliente, resultado;
	float bateria, peso, distancia;

	int op = -1;

	while (op != 0) {
		op = menuSmartCity();

		switch (op) {
		case 1: printf("\nA Localizacao do novo vertice do grafo: ");
			scanf("%s", &localizacaoVertice);
			resultado = criarVertice(&g, localizacaoVertice);
			printf("\n\n=======================================\n\n");
			if (resultado == 1)
			{
				printf("Novo vertice criado com sucesso\n");
			}
			else if (resultado == 0)
			{
				printf("\nErro ao criar o vertice pretendido\n");
			}
			break;

		case 2:printf("\nA Localizacao do primeiro vertice da aresta: ");
			scanf("%s", &verticeinico);
			printf("A Localizacao do segundo vertice: ");
			scanf("%s", &verticefim);
			printf("Peso entre os vertices: ");
			scanf("%f", &peso);
			resultado = criarAresta(g, verticeinico, verticefim, peso);
			printf("\n\n=============================================\n");
			if (resultado == 1)
			{
				printf("\nA sua aresta foi criada \n");
			}
			else if (resultado == -1)
			{
				printf("\nA localizaco do primeiro ou do segundo vertice nao constam no seu grafo\n");
			}
			else
			{
				printf("\nNao foi possivel criar uma aresta\n");
			}

			break;

		case 3:printf("\nQual a localizacao do vertice no qual quer ver os adjacentes: ");
			scanf("%s", &geocodigo);
			printf("\n\n==============================================\n");
			listarAdjacentes(g, geocodigo);
			break;

		case 4: printf("\nTipo do Meio de Transporte: ");
			scanf("%s", &tipoveiculo);
			printf("Localizacao do Meio de Transporte: ");
			scanf("%s", &geocodigo);
			printf("Codigo do Meio de Transporte: ");
			scanf("%d", &codigo);
			printf("Nivel de bateria do Meio de Transporte: ");
			scanf("%f", &bateria);
			printf("\n\n==============================================\n");
			resultado = inserirMeio(g, tipoveiculo, geocodigo, codigo, bateria);
			if (resultado == 1)
			{
				printf("\nMeio inserido com sucesso\n");
			}
			else if (resultado == 0)
			{
				printf("\nErro, nao foi possivel inserir o meio de transporte pretendido\n");
			}
			break;

		case 5: printf("\n A Localizacao que pretende para procurar os meios de transporte: ");
			scanf("%s", &geocodigo);
			printf("\n\n==============================================\n");
			listarMeios(g, geocodigo);
			break;

		case 6: printf("\nO Nome do cliente: ");
			scanf("%s", &nomecliente);
			printf("A Localizacao do cliente: ");
			scanf("%s", &geocodigo);
			printf("O Numero do cliente: ");
			scanf("%d", &numcliente);
			resultado = inserirCliente(g, nomecliente, geocodigo, numcliente);
			printf("\n\n===================================================\n");
			if (resultado == 1)
			{
				printf("\nCliente inserido com sucesso\n");
			}
			else if (resultado == 0)
			{
				printf("\nErro, ao inserir o cliente pretendido\n");
			}
			break;

		case 7:printf("\nA Localizacao para serem procurados os clientes:  ");
			scanf("%s", &geocodigo);
			printf("\n\n\===================================================\n");
			listarClientes(g, geocodigo);
			break;

		case 8:
			resultado = guardarMeios(g);

			if (resultado == 1)
			{
				printf("\nOs seus Meios de Transporte foram guardados com sucesso\n");
			}
			else if (resultado == 0)
			{
				printf("\nErro ao guardar o ficheiro\n");
			}
			break;

		case 9: 
			
			resultado = lerMeios(g);

			if (resultado == 1)
			{
				printf("\nOs Meios de Transporte foram lidos com sucesso\n");
			}
			if (resultado == 0)
			{
				printf("\nErro ao ler os Meios de Transporte\n");
			}
			break;

		case 10:
			resultado = guardarClientes(g);
			if (resultado == 1)
			{
				printf("\nOs seus Clientes foram guardados com sucesso\n");
			}
			else if (resultado == 0)
			{
				printf("\nErro ao guardar o seu ficheiro\n");
			}
			break;

		case 11: resultado = lerClientes(g);

			if (resultado == 1)
			{
				printf("\nOs Clientes foram lidos com sucesso\n");
			}
			if (resultado == 0)
			{
				printf("\nErro ao ler o seu ficheiro\n");
			}
			break;

		case 12: resultado = guardarGrafo(g);

			if (resultado == 1)
			{
				printf("\nO seu grafo foi guardado com sucesso\n");
			}
			if (resultado == 0)
			{
				printf("\nErro ao guardar o seu grafo grafo\n");
			}
			break;

		case 13: resultado = lerGrafo(g, &g);

			if (resultado == 1)
			{
				printf("\nO seu grafo foi lido com sucesso\n");
			}
			if (resultado == 0)
			{
				printf("\nErro ao ler o seu grafo\n");
			}
			break;

		case 14:
			printf("\nIndique a localizacao do cliente: ");
			scanf("%s", &localizacao);
			printf("Indique o raio em metros: ");
			scanf("%f", &distancia);
			printf("Indique o tipo do meio de transporte: ");
			scanf("%s", &tipoveiculo);
			printf("\n\n====================================================\n");
			listarDistancia(g, distancia, localizacao, tipoveiculo);
			break;

		case 0:
			printf("\nO programa vai ser encerrado...\n");
			break;

		default: printf("\nEssa opcao nao esta disponivel\n");
			
			break;
		}
		printf("\n");

	} while (op != 0);

	return 0;
}