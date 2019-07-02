#include "pch.h"
#include<iostream>
#include <omp.h>
using namespace std;
int sinifiBulma(int boyut, int k, double uzaklik[][5]) {

	int yenigs�n�f� = 0;
	int Asay�s� = 0, Bsay�s� = 0;

	for (int i = 1;i <= k;i++) {//k degerini d�nd�r�yor s�ras�yla 1. degeri 2. degeri k kadar
		// k degerine g�re hangi s�n�ftan kac tane oldugunun bulunmas� 
		for (int j = 0;j < boyut; j++) {
			if (uzaklik[j][4] == i) {  // k. s�radakini buluyor
				if (uzaklik[j][2] == -1) //k. degerdekini As�n�f�na m� ait diye kontrolunu sagl�yor
					Asay�s� = Asay�s� + 1;  // k ya g�re A s�n�f�n�n say�s�n� buluyor
				else if (uzaklik[j][2] == -2)//k. degerdekini As�n�f�na m� ait diye kontrolunu sagl�yor
					Bsay�s� = Bsay�s� + 1;  // k ya g�re B s�n�f�n�n say�s�n� buluyor
			}
		}
	}
	if (Asay�s� > Bsay�s�) {
		//A s�n�f�nn daha fazla oldugu durumlarda
		yenigs�n�f� = -1;
	}
	else if (Asay�s� < Bsay�s�) {
		//B s�n�f� daha buyukse
		yenigs�n�f� = -2;
	}
	else if (Asay�s� == Bsay�s�) {
		//iki s�n�ftanda esit oldugu durumlarda
		yenigs�n�f� = -3;
	}
	cout << "yeni g�zlem degerinin s�n�f�  A=" << Asay�s� << "  B=" << Bsay�s� << "  " << yenigs�n�f� << endl;

	return yenigs�n�f�;
}