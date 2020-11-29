// EncryptoMania.cpp : This file contains the 'main' function. Program execution begins and ends there.

// standard header files
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <Windows.h>

// custom header files
#include "CeaserCipher.h"
#include "vernamCipher.h"
#include "asciiArt.h"

// standard namespace
using namespace std;

// UI CLASS
class displayer_UI
{
public:
	void displayBrand()
	{
		system("cls");
		ascii_selector();
	}
	void displayMenu()
	{
		cout << endl;
		cout << setw(50) << " 1. CEASER CIPHER " << endl;
		cout << setw(50) << " 2. SIMPLE CIPHER " << endl;
		cout << setw(50) << " 3. EXIT WIZARD   " << endl;
	}
	void askUser()
	{
		int choice;
		displayBrand();
		displayMenu();
		cout << setw(30) << " WHAT ? :: ";
		cin >> choice;
		if (choice == 1)
		{
			CeaserCipher RUNAPP;
			RUNAPP.encrypt("assets/text.txt");
			RUNAPP.decrypt();
		}
		if (choice == 2)
		{
			vernamCipher RUNAPP("HELLOWORLD", "MANIA");
			RUNAPP.encrypt();
			RUNAPP.printenc();
			system("pause");
			RUNAPP.decrypt();
			RUNAPP.printdec();
			system("pause");
		}
	}
};

int main(int argc, char const *argv[])
{
	displayer_UI RUN;
	RUN.askUser();
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