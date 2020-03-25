
#include "pch.h"
#include <iostream>
#include <queue>
using namespace std;

int row[4] = { 1, -1, 0, 0 };
int col[4] = { 0, 0, 1, -1 };
int n, m, counter = 0;
bool matrix[100][100];

bool check(int i, int j) { return ((0 <= i) && (i < n) && (0 <= j) && (j < m)); }

void FindNeighbours(int start_i, int start_j)
{
	queue <int> queue_i, queue_j;
	queue_i.push(start_i);
	queue_j.push(start_j);
	int i, j;

	while (!queue_i.empty()) 
	{
		i = queue_i.front();
		j = queue_j.front();
		matrix[i][j] = 1;
		for (int k = 0; k < 4; k++)
			if (check(i + col[k], j + row[k]) && !(matrix[i + col[k]][j + row[k]])) 
			{
				queue_i.push(i + col[k]);
				queue_j.push(j + row[k]);
			}
		queue_i.pop();
		queue_j.pop();
	}
}

int main() {
	cin >> n >> m;

	char ch;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			cin >> ch;
			matrix[i][j] = ch == '.';
		}


	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (!matrix[i][j]) 
			{
				counter++;
				FindNeighbours(i, j);
			}

	cout << counter;

	return 0;
}