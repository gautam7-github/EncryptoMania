#include "CeaserCipher.h"
#include <fstream>
#include <iostream>
#include <cstdlib>
using namespace std;

int CeaserCipher::getKey()
{
    return CC_KEY;
}

CeaserCipher::CeaserCipher()
{
    CC_KEY = 3;
}
void CeaserCipher::encrypt(string fileName)
{
    int keyNum;
    char text;

    // files
    fstream ogfile, encfile;
    ogfile.open(fileName.c_str(), ios::in);
    encfile.open("assets/encrypted_CCipher.txt", ios::out);

    if ((!ogfile) && (!encfile))
    {
        perror("ERROR :");
        return;
    }
    cout << "ENCRYPTING...\n";
    // real deal starts here
    while (!ogfile.eof())
    {
        ogfile.get(text);
        text = text + getKey();
        encfile << text;
    }
    cout << "ENCRYPTED...\n";
    // closing the files
    ogfile.close();
    encfile.close();
}
void CeaserCipher::decrypt()
{
    char writeOG;

    // files
    fstream ecfile, decfile;
    ecfile.open("assets/encrypted_CCipher.txt", ios::in);
    decfile.open("assets/decrypted_CCipher.txt", ios::out);

    if ((!ecfile) && (!decfile))
    {
        perror("ERROR :");
        return;
    }
    cout << "DECRYPTING...\n";
    // real deal starts here
    while (!ecfile.eof())
    {
        ecfile.get(writeOG);
        writeOG = writeOG - getKey();
        decfile << writeOG;
    }
    cout << "DECRYPTED...\n";
    // closing the files
    ecfile.close();
    decfile.close();
}