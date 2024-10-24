#include "StdAfx.h"
#define _CRT_SECURE_NO_WARNINGS
#include <time.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include "string.h"


int main()
{
	setlocale(LC_ALL, "Rus");
	int n=10, **G= NULL, count = 0, *deg=NULL, *loop= NULL;

	printf("Введите размер матирицы: ");
	scanf("%d", &n);
	deg = (int*)malloc(n * sizeof(int));
	loop = (int*)malloc(n * sizeof(int));
	G = (int**)malloc(n * sizeof(int*));
	for(int i=0; i < n; i++)
	{
		G[i] = ((int*)malloc(n * sizeof(int)));
	}

	for (int i=0; i < n; i++)
	{
		for(int j = 0; j<n; j++)
		{
			G[i][j] = 0;
		}
		deg[i] = 0;
		loop[i] = 0;
	}

	for (int i=0; i < n; i++)
	{
		for(int j = i; j<n; j++)
		{
			G[i][j] = rand()%2;
			G[j][i] = G[i][j];
		}
	}

	for (int i=0; i < n; i++)
	{
		for(int j = i; j<n; j++)
		{
			if (G[i][j]==1) 
				count+=1;

		}
	}

	printf("Размер графа : %d\n", count);

	for (int i=0; i < n; i++)
	{
		for(int j = 0; j<n; j++)
		{
			printf("%d ",G[i][j]);
		}
		printf("\n");
	}
	for (int i=0; i < n; i++)
	{
		for(int j = 0; j<n; j++)
		{
			if(i == j)
			{
				deg[i] += 2*G[i][j];
				loop[i] += 2*G[i][j];
			}
			else deg[i]+=G[i][j];
		}
		
	}

	for (int i=0; i < n; i++)
	{
		if (deg[i] - loop[i] == 0) printf("Вершина %d, - изолированная\n", i );
		if (deg[i] - loop[i] == 1) printf("Вершина %d, - концевая\n", i);
		if (deg[i] - loop[i] == n) printf("Вершина %d, - доминирующая\n", i);
		//printf("%d , %d\n", deg[i], loop[i]);
	}

	return 0;
}
