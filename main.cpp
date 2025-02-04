#include "mainheader.h"

void getInputOutput(string&, string&, string&);
void printTitle();

int main(){

    char charHexaFile[] = "hex\\1.hex";
    string hexaFile = charHexaFile;

    string input = " ", output = " ", key = " ";
    char choice;

do
{
    system("cls");
    system("Color 03");
    printTitle();
    cin>>choice;
    cin.ignore();

    if(choice=='1')
    {
        system("Color 06");
        system("cls");
        cout<<endl;
        cout<<"\t\t\t------------*********//////////////\\\\\\\\\\\\\\\\\\\\\\\\\\\\*********------------\n";
        cout<<"\t\t\t-----------******************\"Encryption\"******************-----------\n";
        cout<<"\t\t\t------------*********\\\\\\\\\\\\\\\\\\\\\\\\\\\\//////////////*********------------\n";

        cout<<"\n\t**Input file path should be ended with it's appropriate extension. e.g(text.txt)**"<<endl;
        cout<<"\n\t**Output file path may or may not have an extension.**\n"<<endl;
        getInputOutput(input, output, key);

        Hexadecimal *inputFile = new FileToHexa(input, hexaFile);
        bool okay = inputFile->convertfile();

        if(okay)
        {
            cout<<"\n==================================PLEASE WAIT YOUR WORK IS IN PROGRESS...======================================\n";
            XORCipher *encryption = new Encryption(key, hexaFile, output);
            bool check = encryption->performXOR();
            inputFile->deleteHexaFile(charHexaFile);
            if(check)
            {
                system("cls");
                system("Color 02");
                cout<<"\n\t\tFile is successfully encrypted."<<endl;
                cout<<"\n\t\tPath : \""<<output<<"\""<<endl<<endl;
                system("pause");
            }
        }
    }else if(choice=='2')
    {
        system("Color 06");
        system("cls");
        cout<<endl;
        cout<<"\t\t\t------------*********//////////////\\\\\\\\\\\\\\\\\\\\\\\\\\\\*********------------\n";
        cout<<"\t\t\t-----------******************\"Decryption\"******************-----------\n";
        cout<<"\t\t\t------------*********\\\\\\\\\\\\\\\\\\\\\\\\\\\\//////////////*********------------\n";

        cout<<"\n\t**Input file path may or may not have an extension.**"<<endl;
        cout<<"\n\t**Output file path should be ended with it's appropriate extension. e.g(text.txt)**\n"<<endl;
        getInputOutput(input, output, key);

        XORCipher *decryption = new Decryption(key, hexaFile, input);
        cout<<"\n==================================PLEASE WAIT YOUR WORK IS IN PROGRESS...======================================\n";
        bool okay = decryption->performXOR();

        if(okay)
        {
            Hexadecimal *outputFile = new HexaToFile(hexaFile, output);
            bool check = outputFile->convertfile();
            outputFile->deleteHexaFile(charHexaFile);

            if(check)
            {
                system("cls");
                system("Color 02");
                cout<<"\n\t\tFile is successfully decrypted."<<endl;
                cout<<"\n\t\tPath : \""<<output<<"\""<<endl<<endl;
                system("pause");
            }
        }

    }else if(choice=='3')
    {
        //Output Developer Info
        system("cls");
        system("Color 0a");
        cout<<endl;
        cout<<"\t\t\t------------*********//////////////\\\\\\\\\\\\\\\\\\\\\\\\\\\\*********------------\n";
        cout<<"\t\t\t-----------******************\"Developed By:\"******************-----------\n";
        cout<<"\t\t\t------------*********\\\\\\\\\\\\\\\\\\\\\\\\\\\\//////////////*********------------\n";

        cout<<"\n\n\t\t\t\t\t\t\"Abdullah\""<<endl<<endl;
        cout<<"\t\t\t\t\t\t\"Anees Ahmed\""<<endl<<endl;
        cout<<"\t\t\t\t\t\t\"Zaighum Ali\""<<endl<<endl;
        cout<<"\t\t\t\t\t\t\"Usman Abbasi\""<<endl<<endl;
        system("pause");
    }else if(choice=='4')
    {
        choice = 'q';
    }else
    {
        cout<<"Invalid choice.\n";
    }
}while(choice!='q');

	return 0;
}

void getInputOutput(string &in, string &out, string &k)
{
    cout<<"\n\t\t\tEnter the path of input file : ";
    getline(cin, in);

    cout<<endl;

    cout<<"\n\t\t\tEnter the path of output file : ";
    getline(cin, out);

    cout<<endl;

    cout<<"\n\t\t\tEnter key : ";
    getline(cin, k);
}

void printTitle()
{
    cout<<endl;
    cout<<"\t\t\t--------------*********////////////\\\\\\\\\\\\\\\\\\\\\\\\*********--------------\n";
    cout<<"\t\t\t-------------*********/////////////\\\\\\\\\\\\\\\\\\\\\\\\\\*********-------------\n";
    cout<<"\t\t\t------------*********//////////////\\\\\\\\\\\\\\\\\\\\\\\\\\\\*********------------\n";
    cout<<"\t\t\t-----------*********\"Encryption & Decryption Tool\"*********-----------\n";
    cout<<"\t\t\t------------*********\\\\\\\\\\\\\\\\\\\\\\\\\\\\//////////////*********------------\n";
    cout<<"\t\t\t-------------*********\\\\\\\\\\\\\\\\\\\\\\\\\\/////////////*********-------------\n";
    cout<<"\t\t\t--------------*********\\\\\\\\\\\\\\\\\\\\\\\\////////////*********-------------\n\n\n";

    cout<<"\t\t\t\t\t\t1. \"Encryption\""<<endl<<endl;
    cout<<"\t\t\t\t\t\t2. \"Decryption\""<<endl<<endl;
    cout<<"\t\t\t\t\t\t3. \"Developer Info\""<<endl<<endl;
    cout<<"\t\t\t\t\t\t4. \"Exit\""<<endl<<endl;
    cout<<"\t\t\t\t\t\t\t";
}

