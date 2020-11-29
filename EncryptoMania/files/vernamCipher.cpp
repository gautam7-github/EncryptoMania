#include <iostream>
#include "vernamCipher.h"
vernamCipher::vernamCipher(string a, string b)
{
    s = a;
    k = b;
}
void vernamCipher::encrypt()
{
    int i, j = 0;
    for (i = 0; i < s.size(); i++)
    {
        enc[i] = s[i] ^ k[j];
        j++;
        if (j >= k.size())
        {
            j = 0;
        }
    }
}
void vernamCipher::decrypt()
{
    int i, j = 0;
    for (i = 0; i < s.size(); i++)
    {
        dec[i] = enc[i] ^ k[j];
        j++;
        if (j >= k.size())
        {
            j = 0;
        }
    }
}
void vernamCipher::printenc()
{
    int i;
    char c;
    for (i = 0; i < s.size(); i++)
    {
        c = enc[i] % 74 + 48;
        cout << c;
    }
    cout << endl;
}
void vernamCipher::printdec()
{
    int i;
    for (i = 0; i < s.size(); i++)
    {
        cout << dec[i];
    }
    cout << endl;
}
