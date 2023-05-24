/*
* author: Gon�alo Malheiro
* brief: Ficheiro que engloba todas as estruturas de dados utilizadas
* descricao: Trabalho Pr�tico Estruturas De Dados Avan�adas, 2 Fase
* data: Maio de 2023
*/

#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable: 4996)


//Representa��o dos dados dos Meios de Transporte
typedef struct registoMeios {

	int codigo; // Codigo do Meio de Transporte
	float bateria; // Bateria do Meio de Transporte
	char tipotransporte[50]; // Tipo do meio de Transporte
	char geocodigo[50]; //Geoc�digo do Meio de Transporte
	struct registoMeios* seguinte; // Remete o endere�o de memoria para o proximo Meio de Transporte

}*Meio;


//Representa��o dos dados dos Clientes
typedef struct registoCliente {

	int numcliente; // Numero de cada Cliente
	char nome[50]; // Nomes dos Clientes
	char localizacao[50]; // Localiza��o dos Clientes
	struct registoCliente* seguinte; //Remete o endere�o de memoria para o proximo Cliente

}*Cliente;

// Representa��o de um grafo orientado e pesado
typedef struct registoAdjacentes {

	char vertice[50]; // Geoc�digo
	float peso; // A dist�ncia de um meio de transporte para outro
	struct registoAdjacentes* seguinte; //Remete o endere�o de mem�ria para o proximo vertice Adjacente 

}*Adjacentes;


// Representa��o de um grafo orientado e pesado
typedef struct registoGrafo {

	char vertice[50]; // Geoc+idgo
	Adjacentes adjacentes; // Lista ligada com os vertices e o peso para caminho neste geoc�digo
	Meio meios; //Lista ligada com os c�digos dos meios de transporte existente neste geoc�digo
	Cliente cliente; // Lista ligada com o numero, nome, e localizac�o dos clientes existentes neste geoc�digo
	struct registoGrafo* seguinte; //Remete o endere�o de mem�ria para o pr�ximo Grafo

}*Grafo;


//Func�es dos Clientes
int inserirCliente(Grafo g, char nome[], char localizacaocliente[], int numcliente);
void listarClientes(Grafo g, char localiza��o[]);
int guardarClientes(Grafo g);
int lerClientes(Grafo g);

//Func�es dos Meios de Transporte
int inserirMeio(Grafo g, char tipotransporte[], char geocodigo[], int codigoMeio, float bateria);
void listarMeios(Grafo g, char geocodigo[]);
int guardarMeios(Grafo g);
int lerMeios(Grafo g);
void listarDistancia(Grafo g, float distancia, char localizacao[], char tipotranporte[]);

//Func�es para as Localizac�es
int criarVertice(Grafo* g, char novoid[]);
int existeVertice(Grafo g, char vertice[]);
int criarAresta(Grafo g, char vOrigem[], char vDestino[], float peso);
void listarAdjacentes(Grafo g, char vertice[]);
int guardarGrafo(Grafo g);
int lerGrafo(Grafo g, Grafo* g1);
