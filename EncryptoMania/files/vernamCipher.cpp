#include <iostream>
#include <fstream>
#include "vernamCipher.h"
using namespace std;
vernamCipher::vernamCipher(string M, string K)
{
    message = M;
    key = K;
}
void vernamCipher::encrypt()
{
    // files
    fstream encFile, textFile;
    encFile.open("assets/encrypted-VCipher.txt", ios::out);
    textFile.open("assets/text2.txt", ios::in);
    if ((!encFile) && (!textFile))
    {
        perror("ERROR ::");
        return;
    }
    // real deal starts here
    int i, j = 0;
    char c, textOG;
    while (!textFile.eof())
    {
        cin.clear();
        getline(textFile, message);

        for (i = 0; i < message.size(); i++)
        {
            enc[i] = message[i] ^ key[j];
            j++;
            if (j >= key.size())
            {
                j = 0;
            }
            c = enc[i] % 74 + 48;
            encFile << c;
        }
        encFile << endl;
    }
    encFile.close();
}
void vernamCipher::decrypt()
{
    fstream encFile;
    string encr;
    encFile.open("assets/encrypted-VCipher.txt", ios::in);
    while (!encFile.eof())
    {
        cin.clear();
        getline(encFile, encr);

        int i, j = 0;
        for (i = 0; i < message.size(); i++)
        {
            dec[i] = encr[i] ^ key[j];
            j++;
            if (j >= key.size())
            {
                j = 0;
            }
            cout << dec[i] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
