#ifndef CeaserCipher_H
#define CeaserCipher_H
#include <string>
class CeaserCipher
{
private:
    int CC_KEY;
    int getKey();

public:
    CeaserCipher();
    void encrypt(std::string);
    void decrypt();
};
#endif