// CPP file of XORCipher

#include "xorcipher.h"

/*--------------------------Defination of XORCipher class--------------------------------*/

XORCipher::XORCipher(): key(" "), pathOfHexFile(" "), pathOfXORFile(" ") {}

XORCipher::XORCipher(string key, string pathOfHexFile, string pathOfXORFile)
{
    this->key = key;
    this->pathOfHexFile = pathOfHexFile;
    this->pathOfXORFile = pathOfXORFile;
}

void XORCipher::setPathOfHexFile(string pathOfHexFile)
{
    this->pathOfHexFile = pathOfHexFile;
}

void XORCipher::setPathOfXORFile(string pathOfXORFile)
{
    this->pathOfXORFile = pathOfXORFile;
}

void XORCipher::setKey(string key)
{
    this->key = key;
}

/*--------------------------Defination of Encryption class--------------------------------*/

Encryption::Encryption(string key, string pathOfHexFile, string pathOfXORFile): XORCipher(key, pathOfHexFile, pathOfXORFile) {}

bool Encryption::performXOR()
{
    string hexData;

    /* Storing hexadecimal values to string hexData  */

    fstream inputFile;
	inputFile.open(pathOfHexFile, ios::in);
	if(!inputFile.is_open())
	{
		system("cls");
        system("Color 04");
        cout<<"\n\n\t\t\t\tUnable to open a "<<pathOfHexFile<<" file :( "<<endl;
        system("pause");
        return false;
	}else{
		string data;
		while(getline(inputFile, data))
		{
			hexData += data;
		}

        inputFile.close();

    /* Performing XOR operation using key to string hexData  */

        string cipherText;
        stringstream ss;

        for (size_t i = 0; i < hexData.length(); ++i)
        {
            char encryptedChar;

            encryptedChar = hexData[i] ^ key[i % key.length()];

            ss << hex << setw(2) << setfill('0') << (int)encryptedChar;
        }
        ss >> cipherText;

    /* Storing cipher text to file (path entered by the user)   */

        fstream outputFile;
        outputFile.open(pathOfXORFile, ios::out);
        if(!outputFile.is_open())
        {
            system("cls");
            system("Color 04");
            cout<<"\n\n\t\t\t\tUnable to open a "<<pathOfXORFile<<" file :( "<<endl;
            system("pause");
            return false;
        }else{
            outputFile << cipherText;
        }
        outputFile.close();
        return true;
	}
}


/*--------------------------Defination of Decryption class--------------------------------*/

Decryption::Decryption(string key, string pathOfHexFile, string pathOfXORFile): XORCipher(key, pathOfHexFile, pathOfXORFile){}

bool Decryption::performXOR()
{
    /* First load and store (encrypted data) file in the string  */
    string encryptedData;

    fstream inputFile;
	inputFile.open(pathOfXORFile, ios::in);
	if(!inputFile.is_open())
	{
		system("cls");
        system("Color 04");
        cout<<"\n\n\t\tUnable to open a "<<pathOfXORFile<<" file :( "<<endl;
        system("pause");
        return false;
	}else{
		string data;
		while(getline(inputFile, data))
		{
			encryptedData += data;
		}

        inputFile.close();

    /* Performing XOR operation using key to on encrypted data  */

        string decryptedData;
        stringstream ss;

        for (size_t i = 0; i < encryptedData.length(); i += 2)
        {
            string singleHexByte = encryptedData.substr(i, 2);
            int encryptedChar;
            ss << hex << singleHexByte;
            ss >> encryptedChar;

            char decryptedChar;
            decryptedChar = encryptedChar ^ key[i / 2 % key.length()];
            decryptedData += decryptedChar;
            ss.clear();
        }

    /* Storing decrypted data to .hex file */

        fstream outputFile;
        outputFile.open(pathOfHexFile, ios::out);
        if(!outputFile.is_open())
        {
            system("cls");
            system("Color 04");
            cout<<"\n\n\t\tUnable to open a "<<pathOfHexFile<<" file :( "<<endl;
            system("pause");
            return false;
        }else{
            outputFile << decryptedData;
        }
        outputFile.close();
        return true;
	}
}





