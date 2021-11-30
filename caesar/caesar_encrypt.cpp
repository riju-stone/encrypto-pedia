#include <iostream>
#include <vector>
#include <string>
#include <map>

#include <utils.h>

using namespace std;

int main()
{
    int key;
    string plain;

    cout << "Enter plain text:\n";
    cin >> plain;

    cout << "Enter encryption key:\n";
    cin >> key;

    string num_plain = to_number(plain);
    string num_cipher = additive(num_plain, key);
    string cipher = from_number(num_cipher);

    cout << cipher;

    return 0;
}
