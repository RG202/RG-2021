/******************************************************************//**
* \file   header.h
* \brief
* \object respons�vel por conter todos os cabe�alhos necess�rios
*
* \author 21166 - Rodrigo Rebelo | contact: a21166@alunos.ipca.pt
* \date   June 2021
* ********************************************************************/

//bibliotecas
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#ifndef P

//struct's
//Estrtutra que cont�m  a informa��o da m�quina
typedef struct Maquina
{
	char Hora[20];
	int in;
	int out;
	int Espera;
	struct Maquina* next; //lista
}Maquina;

#pragma region Assinatura de funcoes
//Exporta��o JSON


//Exporta��o CSV
int exportaCsv(Maquina* Lista, char nomeFicheiro[]);

//Momento com mais defeitos
char* momentoComMaisDefeitos(Maquina* Lista);

//C�lculo da m�quina com mais defeitos
int calculaMaquinaDefeitos(Maquina* Lista);

//Importa��o CSV
int importarCsv(Maquina* head, char nomeFicheiro[]);

//Inser��o de uma m�quina no fim da lista
Maquina* novaMaquinaFim(Maquina* head, char Hora, int in, int out, int Espera);

//Cria��o de uma m�quina 
Maquina* novaMaquina(char* Hora, int in, int out, int Espera);

//Lista com informa��o relevante
void MostraLista(Maquina* Lista);

//Lista com informa��o relativa �s m�quinas
void MostraMaquina(Maquina* Maquina);

#endif // !P
