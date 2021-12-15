#pragma once

#include <string>
using namespace std;

void letterconverter(string message, float numbers[]) {
	string listofchars = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM ";

	for (int a = 0; a < message.length(); a++)
		for (int b = 0; b < listofchars.length(); b++)
			if (message[a] == listofchars[b])
				numbers[a] = b;

	numbers[message.length()] = 77777;
}

void onebythrees(float numbers[], float onebythrees[1000][3]) {
	for (int a = 0; a < 1000; a++)
		for (int b = 0; b < 3; b++)
		{
			if (numbers[3 * a + b] != 77777)
				onebythrees[a][b] = numbers[3 * a + b];
			else
			{
				switch (b)
				{
				case 1:
					onebythrees[a][1] = 777;
					onebythrees[a][2] = 777;
					break;
				case 2:
					onebythrees[a][2] = 777;
					break;
				}

				break;
			}
		}
}

void numberconverter(string& message, float numbers[100000]) {
	string listofchars = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM ";

	for (int a = 0; numbers[a] != 777; a++)
		cout << listofchars[numbers[a]];

	cout << endl;
}