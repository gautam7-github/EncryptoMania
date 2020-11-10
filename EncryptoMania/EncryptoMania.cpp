// EncryptoMania.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

// starts here
class displayer
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
class encrypter
{
public:
	void ceaserCipher_encrypt(string fileName)
	{
		int keyNum;
		char readOG;

		// files
		fstream ogfile, encfile, keyfile;
		ogfile.open(fileName.c_str(), ios::in);
		encfile.open("encrypted.txt", ios::out);
		keyfile.open("key.txt", ios::out);

		if ((!ogfile) && (!encfile) && (!keyfile))
		{
			cout << "ERROR LOG : 431";
			exit(0);
		}

		// real deal starts here
		while (!ogfile.eof())
		{
			ogfile.get(readOG);
			keyNum = 3;
			keyfile << keyNum << endl;
			readOG = readOG + keyNum;
			encfile << readOG;
		}

		// closing the files
		ogfile.close();
		encfile.close();
		keyfile.close();
	}
	void ceaserCipher_decrypt()
	{
		char writeOG;

		// files
		fstream ecfile, decfile;
		ecfile.open("encrypted.txt", ios::in);
		decfile.open("decrypted.txt", ios::out);

		if ((!ecfile) && (!decfile))
		{
			cout << "ERROR LOG : 431";
			exit(0);
		}

		// real deal starts here
		while (!ecfile.eof())
		{
			ecfile.get(writeOG);
			writeOG = writeOG - 3;
			decfile << writeOG;
		}

		// closing the files
		ecfile.close();
		decfile.close();
	}
};

class admin : public displayer, public encrypter
{
public:
	void adminDoAll(char const *argu)
	{
		srand(time(NULL));
		cout << "DETECTED FILE NAME : ";
		cout << argu;
		//displayBrand();
		//displayMenu();
		ceaserCipher_encrypt("text.txt");
		ceaserCipher_decrypt();
	}
};
int main(int argc, char const *argv[])
{
	class admin sudo;
	sudo.adminDoAll(argv[1]);
	return 0;
}
