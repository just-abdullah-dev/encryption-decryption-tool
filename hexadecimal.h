//hexadecimal header file
#ifndef HEXADECIMAL_H
#define HEXADECIMAL_H

#include "header.h"

class Hexadecimal{
	protected:
		string pathOfInputFile, pathOfOutputFile;
	public:
		Hexadecimal();

		Hexadecimal(string, string);

		void setPathOfInputFile(string);

		void setPathOfOutputFile(string);

		void deleteHexaFile(char[]);

		virtual bool convertfile() = 0;
};

class FileToHexa : public Hexadecimal{
	public:
		FileToHexa();

		FileToHexa(string, string);

		bool convertfile();
};

class HexaToFile : public Hexadecimal{
	public:
		HexaToFile();

		HexaToFile(string, string);

		bool convertfile();
};

#endif
