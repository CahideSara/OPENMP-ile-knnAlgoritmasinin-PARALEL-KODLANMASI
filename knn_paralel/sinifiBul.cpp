#include "pch.h"
#include<iostream>
#include <omp.h>
using namespace std;
int sinifiBulma(int boyut, int k, double uzaklik[][5]) {

	int yenigsýnýfý = 0;
	int Asayýsý = 0, Bsayýsý = 0;

	for (int i = 1;i <= k;i++) {//k degerini döndürüyor sýrasýyla 1. degeri 2. degeri k kadar
		// k degerine göre hangi sýnýftan kac tane oldugunun bulunmasý 
		for (int j = 0;j < boyut; j++) {
			if (uzaklik[j][4] == i) {  // k. sýradakini buluyor
				if (uzaklik[j][2] == -1) //k. degerdekini Asýnýfýna mý ait diye kontrolunu saglýyor
					Asayýsý = Asayýsý + 1;  // k ya göre A sýnýfýnýn sayýsýný buluyor
				else if (uzaklik[j][2] == -2)//k. degerdekini Asýnýfýna mý ait diye kontrolunu saglýyor
					Bsayýsý = Bsayýsý + 1;  // k ya göre B sýnýfýnýn sayýsýný buluyor
			}
		}
	}
	if (Asayýsý > Bsayýsý) {
		//A sýnýfýnn daha fazla oldugu durumlarda
		yenigsýnýfý = -1;
	}
	else if (Asayýsý < Bsayýsý) {
		//B sýnýfý daha buyukse
		yenigsýnýfý = -2;
	}
	else if (Asayýsý == Bsayýsý) {
		//iki sýnýftanda esit oldugu durumlarda
		yenigsýnýfý = -3;
	}
	cout << "yeni gözlem degerinin sýnýfý  A=" << Asayýsý << "  B=" << Bsayýsý << "  " << yenigsýnýfý << endl;

	return yenigsýnýfý;
}