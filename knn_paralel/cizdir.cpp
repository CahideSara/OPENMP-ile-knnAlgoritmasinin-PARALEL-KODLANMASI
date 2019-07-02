#include "pch.h"
#include <string>
#include<iostream>
#include <omp.h>

using namespace std;

int cizdirr(int düzlem[][15], int yenigsýnýfý) {
	string sonuc;
	cout << endl;

	//Yeni gözlem degeri girilmeden önce diziyi cizilen düzlem
	if (yenigsýnýfý == 0) {

		for (int i = 0;i < 15;i++)
		{
			cout << i << "    ";
			for (int j = 0;j < 15;j++)
			{
				if (düzlem[i][j] == 0)
					cout << "-" << "    ";

				else if (düzlem[i][j] == -1)
					cout << "A" << "    ";

				else if (düzlem[i][j] == -2)
					cout << "B" << "    ";
				else if (düzlem[i][j] == -3)
					cout << "A?" << "    ";
				else if (düzlem[i][j] == -4)
					cout << "B?" << "    ";
				else if (düzlem[i][j] == -5)
					cout << "?" << "    ";

			}
			cout << endl;
		}
	}

	//Yeni gözlem degeri girilip hangi sýnýfa ait oldugu belirlendikten sonra cizilen düzlem
	else {

		string sýnýf;
		//Hangi sýnýfa ait oldugu verilen bilgiye göre atanýr
		if (yenigsýnýfý == -1)
			sýnýf = "A";
		if (yenigsýnýfý == -2)
			sýnýf = "B";
		if (yenigsýnýfý == -3)
			sýnýf = "A/B";



		for (int i = 0;i < 15;i++)
		{
			cout << i << "    ";
			for (int j = 0;j < 15;j++)
			{
				if (düzlem[i][j] == 0)
					cout << "-" << "    ";

				else if (düzlem[i][j] == -1)
					cout << "A" << "    ";

				else if (düzlem[i][j] == -2)
					cout << "B" << "    ";
				else if (düzlem[i][j] == -3) {
					cout << "?=" << sýnýf << "    ";
					sonuc = "GÖZLEM DEGERÝ A SINIFIYDI VE YENÝ SINIFI =";
				}

				else if (düzlem[i][j] == -4) {
					cout << "?=" << sýnýf << "    ";
					sonuc = "GÖZLEM DEGERÝ B SINIFIYDI VE YENÝ SINIFI = ";
				}

				else if (düzlem[i][j] == -5) {
					cout << "?=" << sýnýf << "    ";
					sonuc = "GÖZLEM DEGERÝNÝN  SINIFI = ";
				}


			}
			cout << endl;
		}

		cout << sonuc << sýnýf << endl;
	}
	return 0;
}


