// EncryptoMania.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include "CeaserCipher.h"
using namespace std;

// starts here
class displayer_UI
{
public:
	void displayBrand()
	{
		system("cls");
		cout << "\n\n\n\n\n";
		cout << setw(60) << "-------------------" << endl;
		cout << setw(60) << "| ENCRYPTRO-MANIA |" << endl;
		cout << setw(60) << "-------------------" << endl;
		cout << "\n\n\n\n";
		cout << setw(70) << "-------------------------------------" << endl;
		cout << setw(70) << "| A TEXT ENCRYPTION/DECRYPTION TOOL |" << endl;
		cout << setw(70) << "-------------------------------------" << endl;
		cout << "\n\n\n";
	}
	void displayMenu()
	{
		cout << setw(50) << " 1. CEASER CIPHER " << endl;
		cout << setw(50) << " 2. SIMPLE CIPHER " << endl;
		cout << setw(50) << " 3. EXIT WIZARD   " << endl;
	}
};

int main(int argc, char const *argv[])
{
	CeaserCipher RUNAPP;
	RUNAPP.encrypt("assets/text.txt");
	RUNAPP.decrypt();
	return 0;
}

/*
class encrypter_CeaserCipher
{
private:
	int CC_KEY;
	int getKey()
	{
		return CC_KEY;
	}

public:
	encrypter_CeaserCipher()
	{
		CC_KEY = 3;
	}
	void ceaserCipher_encrypt(string fileName)
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
			exit(0);
		}

		// real deal starts here
		while (!ogfile.eof())
		{
			ogfile.get(text);
			text = text + getKey();
			encfile << text;
		}

		// closing the files
		ogfile.close();
		encfile.close();
	}
	void ceaserCipher_decrypt()
	{
		char writeOG;

		// files
		fstream ecfile, decfile;
		ecfile.open("assets/encrypted_CCipher.txt", ios::in);
		decfile.open("assets/decrypted_CCipher.txt", ios::out);

		if ((!ecfile) && (!decfile))
		{
			perror("ERROR :");
			exit(0);
		}

		// real deal starts here
		while (!ecfile.eof())
		{
			ecfile.get(writeOG);
			writeOG = writeOG - getKey();
			decfile << writeOG;
		}

		// closing the files
		ecfile.close();
		decfile.close();
	}
};
*/