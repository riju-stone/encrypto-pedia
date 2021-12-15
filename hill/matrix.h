#pragma once

#include <cstdlib>
#include <ctime>

void matrixgen(float matrix[3][3], float inverse[3][3]) {
	srand(time(0));

	for (int a = 0; a < 3; a++)
		for (int b = 0; b < 3; b++)
			matrix[a][b] = inverse[a][b] = rand() % 10 - rand() % 10;
}

int minorsanddeterminant(float matrix[3][3]) {
	int determinant;
	float temp[3][3];

	for (int m = 0; m < 3; m++)
		for (int n = 0; n < 3; n++)
		{
			int x = 0, y = 0, u, v;

			while (x == m)
				x++;
			while (y == n)
				y++;

			u = x;
			v = y;

			do
				u++;
			while (u == m);

			do
				v++;
			while (v == n);

			temp[m][n] = matrix[x][y] * matrix[u][v] - matrix[x][v] * matrix[u][y];
		}

	determinant = matrix[0][0] * temp[0][0] - matrix[0][1] * temp[0][1] + matrix[0][2] * temp[0][2];

	for (int m = 0; m < 3; m++)
		for (int n = 0; n < 3; n++)
			matrix[m][n] = temp[m][n];

	return determinant;
}

void cofactors(float matrix[3][3]) {
	matrix[0][1] *= -1;
	matrix[1][0] *= -1;
	matrix[1][2] *= -1;
	matrix[2][1] *= -1;
}

void adjoint(float matrix[3][3]) {
	float temp[3][3];

	for (int a = 0; a < 3; a++)
		for (int b = 0; b < 3; b++)
			temp[a][b] = matrix[b][a];

	for (int a = 0; a < 3; a++)
		for (int b = 0; b < 3; b++)
			matrix[a][b] = temp[a][b];
}

void multiplication(int rows, float matrix[3][3], float threebyones[1000][3], float finalmessage[100000]) {
	for (int a = 0; a < rows; a++)
		for (int b = 0; b < 3; b++)
			for (int c = 0; c < 3; c++)
				finalmessage[3 * a + b] += matrix[b][c] * threebyones[a][c];
}