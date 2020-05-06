#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct rekord
{
	string tytul = "Bad Boy", rezyser = "Patryk Vega", opis = "Powstanie i upadek wlasciciela klubu pilkarskiego";
	int id, rok;
};

class FILMY 
{
		vector <struct rekord> wynik;
	public:
		void wczytaj();
		void wypisz();
		int rok, id;
		string nazwa;
};



void FILMY::wczytaj()
{
    ifstream plik;
    plik.open("a.txt");
    if (! plik) cout<<"Brak podanego pliku, sprobuj ponownie\n";

    int s = 0;
    vector<string> elo;
    ifstream plik2("a.txt");
    string l;
    while (getline(plik2, l)) elo.push_back(l);
    for (int i = 0; i < elo.size(); i++) s++;
    plik2.close();
    
    cout<<"ID:    "<<"Tytul:"<<"  "<<"  Rezyser:"<<"       "<<"Rok: "<<"    "<<"Opis: \n";
    
    for (int i=0; i<elo.size(); i++)
    {
      cout<< i<<"      "<<elo[i]<<endl;
    }
	
}



void FILMY::wypisz()
{
        ofstream plik3;
        plik3.open("wyniki.txt");
        for (vector<struct rekord>::iterator it = wynik.begin(); it != wynik.end(); ++it)
        {
                plik3 << it->tytul << " "
                         << it->id << " "
                         << it->rok << " "
                         << it->rezyser << "\n";
        }
        plik3.close(); 
}

int main(int argc, char** argv) {
	
	FILMY PG;
	PG.wczytaj();
	PG.wypisz();
	return 0;
}
