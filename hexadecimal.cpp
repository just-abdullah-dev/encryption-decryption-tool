#include "hexadecimal.h"

Hexadecimal::Hexadecimal()
{
	this->pathOfInputFile = " ";
	this->pathOfOutputFile = " ";
}

Hexadecimal::Hexadecimal(string pathOfInputFile, string pathOfOutputFile){
    this->pathOfInputFile = pathOfInputFile;
    this->pathOfOutputFile = pathOfOutputFile;
}

void Hexadecimal::setPathOfInputFile(string pathOfInputFile)
{
    this->pathOfInputFile = pathOfInputFile;
}

void Hexadecimal::setPathOfOutputFile(string pathOfOutputFile)
{
    this->pathOfOutputFile = pathOfOutputFile;
}

void Hexadecimal::deleteHexaFile(char pathOfHexaFile[])
{
    remove(pathOfHexaFile);
}

/*------------------File TO Hexa Class Code -----------------*/

FileToHexa::FileToHexa() : Hexadecimal(){}

FileToHexa::FileToHexa(string pathOfInputFile, string pathOfOutputFile) : Hexadecimal(pathOfInputFile, pathOfOutputFile){}

bool FileToHexa::convertfile()
{
    vector<unsigned char> file_data;
    bool flag = true;

   fstream inputFile;
   inputFile.open(pathOfInputFile, ios::in | ios::binary);
   if(!inputFile.is_open())
   {
        system("cls");
        system("Color 04");
        cout<<"\n\n\t\t\t\tUnable to open a "<<pathOfInputFile<<" file :( "<<endl;
        system("pause");
        flag = false;
        return false;
   }else{
        while (true) {
        unsigned char byte;
        inputFile.read(reinterpret_cast<char*>(&byte), sizeof(byte));
        if (inputFile.eof()) {
            break;
        }
        file_data.push_back(byte);
    }
    inputFile.close();
   }

   if(flag){
        fstream outputFile;
        outputFile.open(pathOfOutputFile, ios::out | ios::binary);
        if(!outputFile.is_open())
        {
            system("cls");
            system("Color 04");
            cout<<"\n\n\t\t\t\tUnable to open a "<<pathOfOutputFile<<" file :( "<<endl;
            system("pause");
            return false;
        }else{
            for (unsigned char byte : file_data) {
            outputFile << hex << setw(2) << setfill('0') << static_cast<int>(byte) << ' ';
        }
        }
        outputFile.close();
        return true;
    }
}

/*------------------Hexa To File Class Code -----------------*/

HexaToFile::HexaToFile(): Hexadecimal(){}

HexaToFile::HexaToFile(string pathOfInputFile, string pathOfOutputFile): Hexadecimal(pathOfInputFile, pathOfOutputFile){}

bool HexaToFile::convertfile()
{
    vector <unsigned char> file_data;
    bool flag = true;

    fstream inputFile;
    inputFile.open(pathOfInputFile, ios::in | ios::binary);
    if(!inputFile.is_open())
    {
        system("cls");
        system("Color 04");
        cout<<"\n\n\t\t\t\tUnable to open a "<<pathOfInputFile<<" file :( "<<endl;
        system("pause");
        flag = false;
        return false;
    }else{
        string value;
        while(inputFile >> value)
        {
            unsigned char byte;
            byte = static_cast<unsigned char>(stoi(value, nullptr, 16));
            file_data.push_back(byte);
        }
        inputFile.close();
    }
    if(flag){
        fstream outputFile;
        outputFile.open(pathOfOutputFile, ios::out | ios::binary);
        if(!outputFile.is_open())
        {
            system("cls");
            system("Color 04");
            cout<<"\n\n\t\t\t\tUnable to open a "<<pathOfOutputFile<<" file :( "<<endl;
            system("pause");
            return false;
        }else{
            char *ch = reinterpret_cast<char*>(&file_data[0]);
            outputFile.write(ch, file_data.size());
            outputFile.close();
            return true;
        }
    }
}

