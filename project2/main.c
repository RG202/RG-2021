/*****************************************************************//**
 * \file   main.c
 * \brief
 * \object respons�vel por conter todos os chamamentos necess�rios
 *
 * \author 21166 - Rodrigo Rebelo  | contact: a21166@alunos.ipca.pt
 * \date   June 2021
 *********************************************************************/

 //includes
#include"header.h"
#pragma warning(disable:4996)

void MostraLista(Maquina* Lista);
void MostraMaquina(Maquina* Maquina);

int main()
{
#pragma region Chamamentos

	//Cria��o de uma nova m�quina com lista a zeros.
	Maquina* aux = NULL;
	Maquina* head = novaMaquina("18:30:00", 7, 7, 3); // first machine

	//Importa��o CSV
	importarCsv(head, "campos.csv");

	//MostraLista
	MostraLista(head);

	//+ Defeitos
	printf("\n Mais Defeitos: %s \n", momentoComMaisDefeitos(head));

	//Exporta��o JSON
	

	//Exporta��o CSV
	exportaCsv(head, "CsvExport.csv");

	puts("\n \n");

	return 0;

}