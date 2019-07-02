#include "pch.h"
#include <iostream>
#include <omp.h>
#include "uzaklikHesapla.h"
#include "cizdir.h"
#include "sinifiBul.h"
using namespace std;

int calistir() {  


	setlocale(LC_ALL, "Turkish"); //Türkçe karakter   

	int düzlem[15][15];
	// A sýnýfýndan ise -1
	// B sýnýfýndan ise -2 deger atadýk
	// 1  2  -1 ==> 1 x ekseni 2 y ekseni -1 sýnýfý

	//int gözlemler[10][3] = { {1,2,-1},{2,2,-1},{2,3,-1},{4,3,-2},{5,5,-2},{4,2,-2},{4,4,-1},{5,6,-2},{3,3,-2},{2,6,-1} };


	int gözlemler[][3] = { {1,2,-2},{1,8,-2},{2,3,-1},{2,10,-1},{3,5,-2},{4,12,-1},{6,3,-1},{6,6,-2},{6,9,-1},{7,9,-2},{8,11,-1},{9,4,-2},{10,5,-2},{10,6,-1},{10,12,-2},{11,13,-1},{12,2,-2},{12,4,-1},{12,8,-2} };





	int boyut = (sizeof(gözlemler) / sizeof(*gözlemler));

Tekrar:

	//paralel olarak düzlem olusturulup  düzleme dizinin degerleri yerleþtirildi
#pragma omp parallel
	{

#pragma omp parallel for
		for (int i = 0;i < 15;i++)
		{
			for (int j = 0;j < 15;j++)
			{
				düzlem[i][j] = 0;
			}
		}
#pragma omp parallel for
		for (int i = 0;i < boyut;i++)
		{
			düzlem[gözlemler[i][0]][gözlemler[i][1]] = gözlemler[i][2];
		}


	}



	int yenigsýnýfý = 0;//yeni gözlem degerinin sýnýfý tanýmlanýr
	cizdirr(düzlem, yenigsýnýfý);

	int yenigözlem[1][2];
	cout << "Gözlemlenecek deðeri giriniz \n";
	cout << "Gözlem Deðerinin  " << 1 << ".sutununun Deðeri =";
	cin >> yenigözlem[0][0];
	cout << "Gözlem Deðerinin  " << 2 << ".sutununun Deðeri =";
	cin >> yenigözlem[0][1];
	cout << yenigözlem[0][0] << " " << yenigözlem[0][1] << endl;

	if (düzlem[yenigözlem[0][0]][yenigözlem[0][1]] == -1)//eger ki yeni gözlem degeri olan bir gözlem degeri ve  A grubundan ise 
		düzlem[yenigözlem[0][0]][yenigözlem[0][1]] = -3;
	else if (düzlem[yenigözlem[0][0]][yenigözlem[0][1]] == -2)//eger ki yeni gözlem degeri olan bir gözlem degeri ve  B grubundan ise 
		düzlem[yenigözlem[0][0]][yenigözlem[0][1]] = -4;
	else {                                                    //eger ki yeni gözlem degeri VAR OLAN BÝR DEGER degilse
		düzlem[yenigözlem[0][0]][yenigözlem[0][1]] = -5;
	}

	double uzaklik[(sizeof(gözlemler) / sizeof(*gözlemler))][5];
	double sýrala[(sizeof(uzaklik) / sizeof(*uzaklik))];
	uzaklikHesaplama(boyut, yenigözlem, sýrala, gözlemler, uzaklik);
	int k;
	cout << "K degerini gir = ";
	cin >> k;
	yenigsýnýfý = sinifiBulma(boyut, k, uzaklik);

	cizdirr(düzlem, yenigsýnýfý);
	int tekrar;
	cout << endl;
	cout << "Baska bir gözlem degeri ile denemek için 1 sayýsýný gir";
	cin >> tekrar;
	if (tekrar == 1)
		goto Tekrar;


	return 0;

}