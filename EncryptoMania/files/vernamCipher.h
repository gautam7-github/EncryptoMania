#ifndef VERNAM_H
#define VERNAM_H
#include <string>
using namespace std;
class vernamCipher
{
private:
    string s, k;
    char enc[1000], dec[1000];

public:
    vernamCipher(string a, string b);
    void encrypt();
    void decrypt();
    void printenc();
    void printdec();
};

#endif // VERNAM_H