#include "pch.h"
#include<iostream>
#include <omp.h>
#include <stdlib.h>

using namespace std;

int uzaklikHesaplama(int boyut, int yenig�zlem[][2], double s�rala[], int g�zlemler[][3], double uzaklik[][5]) {


	//yenig�zlem degeri ile g�zlem degerleri ars�ndaki fark bulunur 
#pragma omp parallel
	{
      #pragma omp parallel 
		 for (int i = 0; i < boyut; i++)
		  {
			uzaklik[i][0] = g�zlemler[i][0];
			uzaklik[i][1] = g�zlemler[i][1];
			double deger = sqrt(((g�zlemler[i][0] - yenig�zlem[0][0]))*((g�zlemler[i][0] - yenig�zlem[0][0])) + ((g�zlemler[i][1] - yenig�zlem[0][1]))*((g�zlemler[i][1] - yenig�zlem[0][1])));
			uzaklik[i][3] = deger;
			uzaklik[i][2] = (double)g�zlemler[i][2];
			s�rala[i] = deger;
		 }
	}



	// bu bulunan degerler buyukluklerine g�re s�raya koyulur

	double temp;

	for (int i = 0;i < boyut - 1;i++)
		for (int j = 0;j < boyut - 1;j++)
		{
			if (s�rala[j] > s�rala[j + 1])
			{
				temp = s�rala[j];
				s�rala[j] = s�rala[j + 1];
				s�rala[j + 1] = temp;
			}
		}
	

	cout << endl;
	//s�ral� verileri numaraland�r�yoruz

	for (int i = 0;i < boyut;) {
		for (int j = 0;j < boyut;j++) {

			if ((uzaklik[j][3] == s�rala[i]) & (!(uzaklik[j][4] > 0 & uzaklik[j][4] < (i + 1)))) {
				uzaklik[j][4] = i + 1;
				i++;
				break;
			}

		}
	}



	/*
		double ekucuk = uzaklik[0][2];
	double ebuyuk = uzaklik[0][2];
	int ikucuk = 0;

	  //for (int i = 0; i < boyut; i++)
	  //{

		 // for (int j = 0; j < boyut; j++)
		 // {
			//  if (!(uzaklik[j][4] <= i && uzaklik[j][4] >= 1)) {
			//	  if (s�rala[j] <= ekucuk) {
			//		  ekucuk = s�rala[j];
			//		  ikucuk = j;
			//	  }
			//	  if (s�rala[j] >= ebuyuk) {
			//		  ebuyuk = s�rala[j];
			//	  }
			//  }
		 // }
		 // uzaklik[ikucuk][4] = i + 1;
		 // s�rala[ikucuk] = ebuyuk + 1;
		 // ekucuk = uzaklik[0][2];
		 // ebuyuk = uzaklik[0][2];
		 // ikucuk = 0;
	  //}
 int nthreads, tid;
    #pragma omp parallel for
	  for (int i = 0; i < boyut; i++)
	  {
		  tid = omp_get_thread_num();
		  cout <<tid<<" . thread  "<< uzaklik[i][0] << "  "<< uzaklik[i][1] << "  "<< uzaklik[i][2] << "  "<< uzaklik[i][3] << "  "<< uzaklik[i][4] << endl;		 
		  if (tid == 0) {
			  nthreads = omp_get_num_threads();
			  cout << "Toplam thread say�s�  =" << nthreads << endl;
		  }

	  }*/
	 
	  for (int i = 0; i < boyut; i++)
	  {
		  cout << uzaklik[i][0] << "\t";
		  cout << uzaklik[i][1] << "\t";
		  cout << uzaklik[i][2] << "\t";
		  cout << uzaklik[i][3] << "\t";
		  cout << uzaklik[i][4] <<  "\t" << endl;


	  }
	  cout << endl;
	  return 0;

}