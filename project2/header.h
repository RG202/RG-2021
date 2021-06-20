/******************************************************************//**
* \file   header.h
* \brief
* \object responsável por conter todos os cabeçalhos necessários
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
//Estrtutra que contém  a informação da máquina
typedef struct Maquina
{
	char Hora[20];
	int in;
	int out;
	int Espera;
	struct Maquina* next; //lista
}Maquina;

#pragma region Assinatura de funcoes
//Exportação JSON


//Exportação CSV
int exportaCsv(Maquina* Lista, char nomeFicheiro[]);

//Momento com mais defeitos
char* momentoComMaisDefeitos(Maquina* Lista);

//Cálculo da máquina com mais defeitos
int calculaMaquinaDefeitos(Maquina* Lista);

//Importação CSV
int importarCsv(Maquina* head, char nomeFicheiro[]);

//Inserção de uma máquina no fim da lista
Maquina* novaMaquinaFim(Maquina* head, char Hora, int in, int out, int Espera);

//Criação de uma máquina 
Maquina* novaMaquina(char* Hora, int in, int out, int Espera);

//Lista com informação relevante
void MostraLista(Maquina* Lista);

//Lista com informação relativa ás máquinas
void MostraMaquina(Maquina* Maquina);

#endif // !P
