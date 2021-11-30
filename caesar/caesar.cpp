#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main()
{
    cout << "Enter plain text:\n";
    string s;
    cin >> s;

    string cipher = "", temp_cipher = "";
    char temp_char;
    int temp_ascii = 0;

    for (int i = 0; i < s.length(); i++)
    {
        temp_char = s.at(i);

        if (temp_char == ' ')
            cipher += " ";
        else
        {
            if (isupper(temp_char))
                temp_ascii = (int)temp_char - 65;
            else
                temp_ascii = (int)temp_char - 97;

            temp_cipher = to_string(temp_ascii);
            cipher += temp_cipher;
        }
    }

    cout << cipher;
    return 0;
}