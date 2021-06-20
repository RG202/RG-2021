#pragma once
/*****************************************************************//**
 * \file   funcoes.c
 * \brief
 * \object respons�vel por conter todos os m�todos necess�rios
 *
 * \author 21166 - Rodrigo Rebelo  | contact: a21166@alunos.ipca.pt
 * \date   June 2021
 *********************************************************************/

 //includes
#include "header.h"


//disables
#pragma warning(disable:4996)


/// <summary>
/// Cria��o de uma nova M�quina
/// </summary>
/// <param name="Hora"></param>
/// <param name="in"></param>
/// <param name="out"></param>
/// <param name="Espera"></param>
/// <returns></returns>
Maquina* novaMaquina(char Hora[], int in, int out, int Espera)
{
	//Aloca��o de espa�o para uma m�quina na mem�ria din�mica
	Maquina* aux = (Maquina*)malloc(sizeof(Maquina));

	//Dever� existir algo na nossa lista para que se proceda �s c�lulas
	if (aux != NULL)
	{
		strcpy(aux->Hora, Hora);
		aux->in = in;
		aux->out = out;
		aux->Espera = Espera;
		aux->next = NULL;
		return aux;
	}
	else return NULL;
}


/// <summary>
/// Cria��o de uma nova M�quina no fim da lista
/// </summary>
/// <param name="head"></param>
/// <param name="Hora"></param>
/// <param name="in"></param>
/// <param name="out"></param>
/// <param name="Espera"></param>
/// <returns></returns>
Maquina* novaMaquinaFim(Maquina* head, char* Hora, int in, int out, int Espera)
{
	while (head->next != NULL)
	{
		head = head->next;
	}
	head->next = novaMaquina(Hora, in, out, Espera);
	return head->next;
}


/// <summary>
/// Importa��o de CSV
/// </summary>
/// <param name="head"></param>
/// <param name="nomeFicheiro"></param>
/// <returns></returns>
int importarCsv(Maquina* head, char* nomeFicheiro)
{
	//Abrir ou inicializar o arquivo
	FILE* fp;
	fp = fopen(nomeFicheiro, "r");

	//Se o  caminho do arquivo n�o existir ou at� mesmo se existir algum problema com o mesmo, n�o faz nada.
	if (fp == NULL) {
		perror("Erro ao abrir ficheiro!\n");
		return 1;
	}

	char* line = (char*)malloc(sizeof(char) * 20);
	char* csvString = (char*)malloc(sizeof(char) * 100);
	char* auxString = (char*)malloc(sizeof(char) * 100);
	size_t len = 0;

	//realizar fgets 2x com o objetivo de passar a linha 1 (dos campos) � frente
	getline(&csvString, &len, fp);
	getline(&csvString, &len, fp);

	//ciclo While para copiar algumas strings
	while (getline(&csvString, &len, fp) > 0)
	{
		char* h = strtok(csvString, ";");
		char* in = strtok(NULL, ";");
		char* out = strtok(NULL, ";");
		char* esp = strtok(NULL, ";");
		novaMaquinaFim(head, strdup(h), atoi(in), atoi(out), atoi(esp));
	}
	fclose(fp);
	return 0;
}


/// <summary>
/// Fun��o que calcula o n�mero de defeitos de uma M�quina
/// </summary>
/// <param name="Lista"></param>
/// <returns></returns>
int calculaMaquinaDefeitos(Maquina* Lista)
{
	int count = 0;

	while (Lista->next != NULL)
	{
		if (Lista->in > Lista->out) count++;
	}
	return count;
}


/// <summary>
/// Hora com mais defeitos
/// </summary>
/// <param name="Lista"></param>
/// <returns></returns>
char* momentoComMaisDefeitos(Maquina* Lista)
{
	int horaMaxDef = (Lista->in) - (Lista->out); // first
	char* HoraMax = strdup(Lista->Hora);

	while (Lista != NULL)
	{
	 	int auxHora = (Lista->in) - (Lista->out); // 1, 2 ou 3, ...
		if (auxHora > horaMaxDef)
		{
			horaMaxDef = auxHora;
			HoraMax = strdup(Lista->Hora);
		}
		Lista = Lista->next;
	}
	return HoraMax;
}


/// <summary>
/// Exportar para CSV
/// </summary>
/// <param name="Lista"></param>
/// <param name="nomeFicheiro"></param>
int exportaCsv(Maquina* Lista, char nomeFicheiro[])
{
	FILE* fp;
	fp = fopen(nomeFicheiro, "w");

	if (fp != NULL)
	{
		fprintf(fp, "Hora;in;out;Espera\n");
		while (Lista != NULL)
		{
			fprintf(fp, "%s;%d;%d;%d\n", Lista->Hora, Lista->in, Lista->out, Lista->Espera);
			Lista = Lista->next;
		}

	}
	else return 1;
	fclose(fp);
	return 0;
}


/// <summary>
/// Procedimento que mostra a lista de informa��o relevante
/// </summary>
/// <param name="Lista"></param>
void MostraLista(Maquina* Lista)
{
	while (Lista != NULL)
	{
		printf("\n Hora: %s", Lista->Hora);
		printf("\n In: %d", Lista->in);
		printf("\n Out: %d", Lista->out);
		printf("\n Espera: %d", Lista->Espera);
		Lista = Lista->next;

	}
}



/// <summary>
/// Procedimento que mostra a informa��o da lista relativas �s maquinas
/// </summary>
/// <param name="Maquina"></param>
void MostraMaquina(Maquina* Maquina)
{
	printf("\n Hora: %s", Maquina->Hora);
	printf("\n In: %d", Maquina->in);
	printf("\n Out: %d", Maquina->out);
	printf("\n Espera: %d \n \n", Maquina->Espera);
}
