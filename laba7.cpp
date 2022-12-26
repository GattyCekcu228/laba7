#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <iostream>
using namespace std;

void task1(int** matrix, int edgenum)
{
	for (int i = 0; i < edgenum; i++)
	{
		matrix[i] = (int*)malloc(edgenum * sizeof(int));
		for (int j = 0; j < edgenum; j++)
		{
			matrix[i][j] = rand() % 2;
		}
	}
	for (int i = 0; i < edgenum; i++)
	{
		for (int j = 0; j < edgenum; j++)
		{
			if (i == j)
			{
				matrix[i][j] = 0;
			}
			else
				matrix[i][j] = matrix[j][i];
			printf("%d ", matrix[i][j]);

		}
		printf("\n");
		printf("\n");
	}
}


void DFS(int** matrix, bool* visited, int start, int edgenum)
{
	visited[start] = true;
	printf("Посещенная вершина: %d ", start + 1);
	printf("\n");
	for (int i = 0; i < edgenum; i++)
	{
		if ((matrix[start][i] != 0) && (visited[i]))
		{
			DFS(matrix, visited, i, edgenum);
		}
	}
}
int main()
{

	setlocale(0, "");
	srand(time(NULL));

	int start;
	printf("Введите стартовую вершину: ");
	scanf("%d", &start);

	int edgenum;
	printf("Введите кол-во вершин: ");
	scanf("%d", &edgenum);

	int** matrix = (int**)malloc(edgenum * sizeof(int**));
	bool* visited = (bool*)malloc(edgenum * sizeof(bool*));
	
	for (int i = 0; i < edgenum; i++)
	{
		visited[i] = false;
	}

	task1(matrix, edgenum);
	DFS(matrix, visited, start, edgenum);
	system("pause");
	return 0;
}

