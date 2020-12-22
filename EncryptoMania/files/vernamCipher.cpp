#include <iostream>
#include <fstream>
#include <algorithm>
#include "vernamCipher.h"
using namespace std;
vernamCipher::vernamCipher(string K)
{
    key = K;
}
void vernamCipher::encrypt()
{
    // files
    fstream encFile, textFile;
    textFile.open("assets/text2.txt", ios::in);
    encFile.open("assets/encrypted-VCipher.txt", ios::out);
    if ((!encFile.is_open()) && (!textFile.is_open()))
    {
        perror("ERROR ::");
        return;
    }
    // real deal starts here
    int i, j = 0;
    char c, textOG;
    cin.clear();

    while (textFile >> message)
    {
        transform(message.begin(), message.end(), message.begin(), ::toupper);
        int mod = key.size();
        j = 0;
        for (int i = key.size(); i < message.size(); i++)
        {
            key += key[j % mod];
            j++;
        }
        string ans = "";
        for (i = 0; i < message.size(); i++)
        {
            ans += (key[i] - 'A' + message[i] - 'A') % 26 + 'A';
        }
        encFile << ans << endl;
    }
    textFile.close();
    encFile.close();
}
void vernamCipher::decrypt()
{
    fstream encFile, decFile;
    string encr;
    encFile.open("assets/encrypted-VCipher.txt", ios::in);
    decFile.open("assets/decrypted_VCipher.txt", ios::out);

    if ((!encFile.is_open()) && (!decFile.is_open()))
    {
        perror("ERROR :");
        return;
    }
    int mod = key.size();
    while (encFile >> message)
    {
        transform(message.begin(), message.end(), message.begin(), ::toupper);
        int j = 0;
        for (int i = key.size(); i < message.size(); i++)
        {
            key += key[j % mod];
            j++;
        }
        string ans = "";
        for (int i = 0; i < message.size(); i++)
        {
            ans += (message[i] - key[i] + 26) % 26 + 'A';
        }
        decFile << ans << endl;
    }
}
