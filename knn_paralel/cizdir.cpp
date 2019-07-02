#include "pch.h"
#include <string>
#include<iostream>
#include <omp.h>

using namespace std;

int cizdirr(int d�zlem[][15], int yenigs�n�f�) {
	string sonuc;
	cout << endl;

	//Yeni g�zlem degeri girilmeden �nce diziyi cizilen d�zlem
	if (yenigs�n�f� == 0) {

		for (int i = 0;i < 15;i++)
		{
			cout << i << "    ";
			for (int j = 0;j < 15;j++)
			{
				if (d�zlem[i][j] == 0)
					cout << "-" << "    ";

				else if (d�zlem[i][j] == -1)
					cout << "A" << "    ";

				else if (d�zlem[i][j] == -2)
					cout << "B" << "    ";
				else if (d�zlem[i][j] == -3)
					cout << "A?" << "    ";
				else if (d�zlem[i][j] == -4)
					cout << "B?" << "    ";
				else if (d�zlem[i][j] == -5)
					cout << "?" << "    ";

			}
			cout << endl;
		}
	}

	//Yeni g�zlem degeri girilip hangi s�n�fa ait oldugu belirlendikten sonra cizilen d�zlem
	else {

		string s�n�f;
		//Hangi s�n�fa ait oldugu verilen bilgiye g�re atan�r
		if (yenigs�n�f� == -1)
			s�n�f = "A";
		if (yenigs�n�f� == -2)
			s�n�f = "B";
		if (yenigs�n�f� == -3)
			s�n�f = "A/B";



		for (int i = 0;i < 15;i++)
		{
			cout << i << "    ";
			for (int j = 0;j < 15;j++)
			{
				if (d�zlem[i][j] == 0)
					cout << "-" << "    ";

				else if (d�zlem[i][j] == -1)
					cout << "A" << "    ";

				else if (d�zlem[i][j] == -2)
					cout << "B" << "    ";
				else if (d�zlem[i][j] == -3) {
					cout << "?=" << s�n�f << "    ";
					sonuc = "G�ZLEM DEGER� A SINIFIYDI VE YEN� SINIFI =";
				}

				else if (d�zlem[i][j] == -4) {
					cout << "?=" << s�n�f << "    ";
					sonuc = "G�ZLEM DEGER� B SINIFIYDI VE YEN� SINIFI = ";
				}

				else if (d�zlem[i][j] == -5) {
					cout << "?=" << s�n�f << "    ";
					sonuc = "G�ZLEM DEGER�N�N  SINIFI = ";
				}


			}
			cout << endl;
		}

		cout << sonuc << s�n�f << endl;
	}
	return 0;
}


