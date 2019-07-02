#include "pch.h"
#include<iostream>
#include <omp.h>
#include <stdlib.h>

using namespace std;

int uzaklikHesaplama(int boyut, int yenigözlem[][2], double sýrala[], int gözlemler[][3], double uzaklik[][5]) {


	//yenigözlem degeri ile gözlem degerleri arsýndaki fark bulunur 
#pragma omp parallel
	{
      #pragma omp parallel 
		 for (int i = 0; i < boyut; i++)
		  {
			uzaklik[i][0] = gözlemler[i][0];
			uzaklik[i][1] = gözlemler[i][1];
			double deger = sqrt(((gözlemler[i][0] - yenigözlem[0][0]))*((gözlemler[i][0] - yenigözlem[0][0])) + ((gözlemler[i][1] - yenigözlem[0][1]))*((gözlemler[i][1] - yenigözlem[0][1])));
			uzaklik[i][3] = deger;
			uzaklik[i][2] = (double)gözlemler[i][2];
			sýrala[i] = deger;
		 }
	}



	// bu bulunan degerler buyukluklerine göre sýraya koyulur

	double temp;

	for (int i = 0;i < boyut - 1;i++)
		for (int j = 0;j < boyut - 1;j++)
		{
			if (sýrala[j] > sýrala[j + 1])
			{
				temp = sýrala[j];
				sýrala[j] = sýrala[j + 1];
				sýrala[j + 1] = temp;
			}
		}
	

	cout << endl;
	//sýralý verileri numaralandýrýyoruz

	for (int i = 0;i < boyut;) {
		for (int j = 0;j < boyut;j++) {

			if ((uzaklik[j][3] == sýrala[i]) & (!(uzaklik[j][4] > 0 & uzaklik[j][4] < (i + 1)))) {
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
			//	  if (sýrala[j] <= ekucuk) {
			//		  ekucuk = sýrala[j];
			//		  ikucuk = j;
			//	  }
			//	  if (sýrala[j] >= ebuyuk) {
			//		  ebuyuk = sýrala[j];
			//	  }
			//  }
		 // }
		 // uzaklik[ikucuk][4] = i + 1;
		 // sýrala[ikucuk] = ebuyuk + 1;
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
			  cout << "Toplam thread sayýsý  =" << nthreads << endl;
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