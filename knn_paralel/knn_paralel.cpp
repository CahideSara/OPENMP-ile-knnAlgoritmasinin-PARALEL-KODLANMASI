
#include "pch.h"
#include <iostream>
#include <omp.h>
#include "uzaklikHesapla.h"
#include "cizdir.h"
#include "calistir.h"
#include "sinifiBul.h"

#include <ctime>

using namespace std;
int main()
{
	clock_t basla = clock(), bitis;

	calistir();
	bitis = clock();
	cout << "CALISMA SÜRESÝ   : " << (float)(bitis - basla) / CLOCKS_PER_SEC;
	cout << endl;


	system("Pause");
	return 0;


}
