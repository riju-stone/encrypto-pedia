#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <cmath>

#include "conversion.h"
#include "matrix.h"

using namespace std;

void encrypt();
void decrypt();

void eninput(string&, string&);
void inversecalc(float[3][3], float[3][3]);
void fileoutput(string, int, float[3][3], float[100000]);

int deinput(float[3][3], float[100000]);

int main() {
	int choice;
	char again;

	do
	{
		system("CLS");

		cout << "Do you want to:" << endl
			<< "\t1) Encrypt" << endl
			<< "\t2) Decrypt" << endl;
		cin >> choice;

		while (choice != 1 && choice != 2)
		{
			cout << "Choice not valid.  Choose again please: ";
			cin >> choice;
		}

		switch (choice)
		{
		case 1:
			encrypt();
			break;
		case 2:
			decrypt();
			break;
		}

		cout << "Continue (Y or N)?: ";
		cin >> again;

		while (again != 'Y' && again != 'y' && again != 'n' && again != 'N')
		{
			cout << "Choice not valid.  Choose again please: ";
			cin >> again;
		}

	} while (again == 'y' || again == 'Y');

	return 0;
}

/******************************************************************************************************************************/

void encrypt() {
	int rows;
	float numbers[100000], threebyones[1000][3], matrix[3][3], inverse[3][3], finalmessage[100000] = { 0 };

	string message, file;

	eninput(message, file);
	letterconverter(message, numbers);
	onebythrees(numbers, threebyones);

	if (message.length() % 3 == 0)
		rows = message.length() / 3;
	else
		rows = message.length() / 3 + 1;

	inversecalc(matrix, inverse);
	multiplication(rows, matrix, threebyones, finalmessage);
	fileoutput(file, rows, inverse, finalmessage);
}

void decrypt() {
	int rows;
	float inverse[3][3], numbers[100000], threebyones[1000][3], decodednumbers[100000] = { 0 };

	string message;

	rows = deinput(inverse, numbers);
	onebythrees(numbers, threebyones);
	multiplication(rows, inverse, threebyones, decodednumbers);

	for (int a = 0; a < rows * 3; a++)
	{
		if (ceil(decodednumbers[a]) - decodednumbers[a] > decodednumbers[a] - floor(decodednumbers[a]))
			decodednumbers[a] = floor(decodednumbers[a]);
		else
			decodednumbers[a] = ceil(decodednumbers[a]);
	}

	numberconverter(message, decodednumbers);
}

/******************************************************************************************************************************/

void eninput(string& message, string& file) {
	cout << "Enter in message: ";
	cin.ignore();
	getline(cin, message);

	cout << "Enter in file: ";
	getline(cin, file);
}

void inversecalc(float matrix[3][3], float inverse[3][3]) {
	int determinant;

	do
	{
		matrixgen(matrix, inverse);
		determinant = minorsanddeterminant(inverse);
	} while (determinant == 0);

	cofactors(inverse);
	adjoint(inverse);

	for (int a = 0; a < 3; a++)
		for (int b = 0; b < 3; b++)
			inverse[a][b] /= determinant;
}

void fileoutput(string file, int rows, float inverse[3][3], float finalmessage[100000]) {
	ofstream out_stream(file);

	for (int a = 0; a < 3; a++)
		for (int b = 0; b < 3; b++)
			out_stream << inverse[a][b] << endl;

	for (int a = 0; a < rows * 3; a++)
		out_stream << finalmessage[a] << endl;

	out_stream.close();
}

/******************************************************************************************************************************/

int deinput(float inverse[3][3], float numbers[100000]) {
	int c;
	string file;

	cout << "Enter in the file name: ";
	cin.ignore();
	getline(cin, file);

	ifstream in_stream(file);

	for (int a = 0; a < 3; a++)
		for (int b = 0; b < 3; b++)
			in_stream >> inverse[a][b];

	for (c = 0; !in_stream.eof(); c++)
		in_stream >> numbers[c];

	numbers[c - 1] = 77777;

	in_stream.close();

	return c / 3;
}