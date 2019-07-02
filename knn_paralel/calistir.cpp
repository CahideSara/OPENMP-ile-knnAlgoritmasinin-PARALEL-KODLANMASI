#include "pch.h"
#include <iostream>
#include <omp.h>
#include "uzaklikHesapla.h"
#include "cizdir.h"
#include "sinifiBul.h"
using namespace std;

int calistir() {  


	setlocale(LC_ALL, "Turkish"); //T�rk�e karakter   

	int d�zlem[15][15];
	// A s�n�f�ndan ise -1
	// B s�n�f�ndan ise -2 deger atad�k
	// 1  2  -1 ==> 1 x ekseni 2 y ekseni -1 s�n�f�

	//int g�zlemler[10][3] = { {1,2,-1},{2,2,-1},{2,3,-1},{4,3,-2},{5,5,-2},{4,2,-2},{4,4,-1},{5,6,-2},{3,3,-2},{2,6,-1} };


	int g�zlemler[][3] = { {1,2,-2},{1,8,-2},{2,3,-1},{2,10,-1},{3,5,-2},{4,12,-1},{6,3,-1},{6,6,-2},{6,9,-1},{7,9,-2},{8,11,-1},{9,4,-2},{10,5,-2},{10,6,-1},{10,12,-2},{11,13,-1},{12,2,-2},{12,4,-1},{12,8,-2} };





	int boyut = (sizeof(g�zlemler) / sizeof(*g�zlemler));

Tekrar:

	//paralel olarak d�zlem olusturulup  d�zleme dizinin degerleri yerle�tirildi
#pragma omp parallel
	{

#pragma omp parallel for
		for (int i = 0;i < 15;i++)
		{
			for (int j = 0;j < 15;j++)
			{
				d�zlem[i][j] = 0;
			}
		}
#pragma omp parallel for
		for (int i = 0;i < boyut;i++)
		{
			d�zlem[g�zlemler[i][0]][g�zlemler[i][1]] = g�zlemler[i][2];
		}


	}



	int yenigs�n�f� = 0;//yeni g�zlem degerinin s�n�f� tan�mlan�r
	cizdirr(d�zlem, yenigs�n�f�);

	int yenig�zlem[1][2];
	cout << "G�zlemlenecek de�eri giriniz \n";
	cout << "G�zlem De�erinin  " << 1 << ".sutununun De�eri =";
	cin >> yenig�zlem[0][0];
	cout << "G�zlem De�erinin  " << 2 << ".sutununun De�eri =";
	cin >> yenig�zlem[0][1];
	cout << yenig�zlem[0][0] << " " << yenig�zlem[0][1] << endl;

	if (d�zlem[yenig�zlem[0][0]][yenig�zlem[0][1]] == -1)//eger ki yeni g�zlem degeri olan bir g�zlem degeri ve  A grubundan ise 
		d�zlem[yenig�zlem[0][0]][yenig�zlem[0][1]] = -3;
	else if (d�zlem[yenig�zlem[0][0]][yenig�zlem[0][1]] == -2)//eger ki yeni g�zlem degeri olan bir g�zlem degeri ve  B grubundan ise 
		d�zlem[yenig�zlem[0][0]][yenig�zlem[0][1]] = -4;
	else {                                                    //eger ki yeni g�zlem degeri VAR OLAN B�R DEGER degilse
		d�zlem[yenig�zlem[0][0]][yenig�zlem[0][1]] = -5;
	}

	double uzaklik[(sizeof(g�zlemler) / sizeof(*g�zlemler))][5];
	double s�rala[(sizeof(uzaklik) / sizeof(*uzaklik))];
	uzaklikHesaplama(boyut, yenig�zlem, s�rala, g�zlemler, uzaklik);
	int k;
	cout << "K degerini gir = ";
	cin >> k;
	yenigs�n�f� = sinifiBulma(boyut, k, uzaklik);

	cizdirr(d�zlem, yenigs�n�f�);
	int tekrar;
	cout << endl;
	cout << "Baska bir g�zlem degeri ile denemek i�in 1 say�s�n� gir";
	cin >> tekrar;
	if (tekrar == 1)
		goto Tekrar;


	return 0;

}