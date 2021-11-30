#include <iostream>
#include <vector>
#include <string>
#include <map>

#include <utils.h>

using namespace std;

int main()
{
    int key;
    string cipher;

    cout << "Enter cipher text:\n";
    cin >> cipher;

    cout << "Enter encryption key:\n";
    cin >> key;

    string num_cipher = to_number(cipher);
    string num_plain = subtractive(num_cipher, key);
    string plain = from_number(num_plain);

    cout << plain;

    return 0;
}

