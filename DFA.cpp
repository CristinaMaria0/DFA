#include <iostream>
#include <fstream>
#include <string.h>>
using namespace std;
struct Lista
{
	int nod1, nod2;
	char litera;
}

stari[100];
int nod_f[100], viz[100], nr_stari, nr_nod_final;
int drum[1000];
void parcurgere(int nod, char cuvant[100], int &i, int &corect)
{
	drum[i] = nod;
	for (int j = 0; j < nr_nod_final; j++)
		if (nod == nod_f[j] && i == strlen(cuvant))
			corect = 1;
	viz[nod] = 1;
	for (int j = 0; j < nr_stari; j++)
		if (stari[j].nod1 == nod && stari[j].litera == cuvant[i])
		{
			i++;
			parcurgere(stari[j].nod2, cuvant, i, corect);
		}
}

int main()
{
	ifstream f("date.in");
	ofstream g("date.out");
	int nr_noduri, nod_init, nr_cuvinte;

	f >> nr_noduri;
	f >> nr_stari;
	///starile
	for (int i = 0; i < nr_stari; i++)
		f >> stari[i].nod1 >> stari[i].nod2 >> stari[i].litera;
	f >> nod_init;
	f >> nr_nod_final;
	for (int i = 0; i < nr_nod_final; i++)
		f >> nod_f[i];
	f >> nr_cuvinte;
	for (int i = 0; i < nr_cuvinte; i++)
	{
		char cuv[1000];
		f >> cuv;
		g << cuv << ": " << endl;
		int j = 0, corect = 0;
		parcurgere(nod_init, cuv, j, corect);
		if (corect == 1)
		{
			g << "    DA" << endl << "    " << "Traseu:";
			for (int i = 0; i <= strlen(cuv); i++)
				g << drum[i] << " ";
			g << endl;
		}
		else
			g << "    NU" << endl;

	}

	return 0;

}
