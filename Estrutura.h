/*
* author: Gonçalo Malheiro
* brief: Ficheiro que engloba todas as estruturas de dados utilizadas
* descricao: Trabalho Prático Estruturas De Dados Avançadas, 2 Fase
* data: Maio de 2023
*/

#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable: 4996)


//Representação dos dados dos Meios de Transporte
typedef struct registoMeios {

	int codigo; // Codigo do Meio de Transporte
	float bateria; // Bateria do Meio de Transporte
	char tipotransporte[50]; // Tipo do meio de Transporte
	char geocodigo[50]; //Geocódigo do Meio de Transporte
	struct registoMeios* seguinte; // Remete o endereço de memoria para o proximo Meio de Transporte

}*Meio;


//Representação dos dados dos Clientes
typedef struct registoCliente {

	int numcliente; // Numero de cada Cliente
	char nome[50]; // Nomes dos Clientes
	char localizacao[50]; // Localização dos Clientes
	struct registoCliente* seguinte; //Remete o endereço de memoria para o proximo Cliente

}*Cliente;

// Representação de um grafo orientado e pesado
typedef struct registoAdjacentes {

	char vertice[50]; // Geocódigo
	float peso; // A distância de um meio de transporte para outro
	struct registoAdjacentes* seguinte; //Remete o endereço de memória para o proximo vertice Adjacente 

}*Adjacentes;


// Representação de um grafo orientado e pesado
typedef struct registoGrafo {

	char vertice[50]; // Geoc+idgo
	Adjacentes adjacentes; // Lista ligada com os vertices e o peso para caminho neste geocódigo
	Meio meios; //Lista ligada com os códigos dos meios de transporte existente neste geocódigo
	Cliente cliente; // Lista ligada com o numero, nome, e localizacão dos clientes existentes neste geocódigo
	struct registoGrafo* seguinte; //Remete o endereço de memória para o próximo Grafo

}*Grafo;


//Funcões dos Clientes
int inserirCliente(Grafo g, char nome[], char localizacaocliente[], int numcliente);
void listarClientes(Grafo g, char localização[]);
int guardarClientes(Grafo g);
int lerClientes(Grafo g);

//Funcões dos Meios de Transporte
int inserirMeio(Grafo g, char tipotransporte[], char geocodigo[], int codigoMeio, float bateria);
void listarMeios(Grafo g, char geocodigo[]);
int guardarMeios(Grafo g);
int lerMeios(Grafo g);
void listarDistancia(Grafo g, float distancia, char localizacao[], char tipotranporte[]);

//Funcões para as Localizacões
int criarVertice(Grafo* g, char novoid[]);
int existeVertice(Grafo g, char vertice[]);
int criarAresta(Grafo g, char vOrigem[], char vDestino[], float peso);
void listarAdjacentes(Grafo g, char vertice[]);
int guardarGrafo(Grafo g);
int lerGrafo(Grafo g, Grafo* g1);
