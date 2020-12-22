#ifndef VERNAM_H
#define VERNAM_H
#include <string>
using namespace std;
class vernamCipher
{
private:
    string message, key;
    char *enc, *dec;

public:
    vernamCipher(string);
    void encrypt();
    void decrypt();
};

#endif // VERNAM_H