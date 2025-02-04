// Header file of XORCipher
#ifndef XORCIPHER_H
#define XORCIPHER_H

#include "header.h"
class XORCipher{
    protected:
        string key, pathOfHexFile, pathOfXORFile;
    public:
        XORCipher();

        XORCipher(string, string, string);

        void setPathOfHexFile(string);

        void setPathOfXORFile(string);

        void setKey(string);

        virtual bool performXOR() = 0;
};

class Encryption: public XORCipher{
    public:
        Encryption():XORCipher(){}

        Encryption(string, string, string);

        bool performXOR();
};

class Decryption: public XORCipher{
    public:
        Decryption():XORCipher(){}

        Decryption(string, string, string);

        bool performXOR();

};

#endif
