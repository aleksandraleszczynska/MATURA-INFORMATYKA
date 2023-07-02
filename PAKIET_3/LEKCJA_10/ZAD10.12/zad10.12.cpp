// W pliku tekstowym anagram.txt znajduje się 200 wierszy zawierających po 5 słów w każdym wierszu. Słowa oddzielone są znakiem odstępu. Długość każdego ze słów wynosi od 1 do 20 znaków. Przykład: abcd cdba dbac cbad dcba barbakan xle ala foto otof smok ayszkm lampa ayszkm bakara skok arabanta oko agnieba dyskietka …… Napisz program w wybranym przez siebie języku programowania, za pomocą którego wykonasz poniższe polecenia:
//  b) Wyszukaj w pliku anagram.txt wszystkie wiersze tekstu, w których wszystkie słowa są anagramami pierwszego słowa w danym wierszu. Zapisz te wiersze w pliku odp_4b.txt.

#include <iostream>
#include <fstream>
using namespace std;

bool CzyJednakowaDlugosc(string napis1, string napis2, string napis3, string napis4, string napis5)
{
    int dlugosc = napis1.length();

    if (napis2.length() != dlugosc)
    {
        return false;
    }
    if (napis3.length() != dlugosc)
    {
        return false;
    }
    if (napis4.length() != dlugosc)
    {
        return false;
    }
    if (napis5.length() != dlugosc)
    {
        return false;
    }
    return true;
}

string SortowanieBabelkowe(string napis)
{
     for (int j = 0; j < napis.length(); j++)
    {
        for (int i = 0; i <napis.length(); i++)
        {
            if (napis[i] < napis[i + 1])
            {
                int temp = napis[i];
                napis[i] = napis[i + 1];
                napis[i + 1] = temp;
            }
        }
    }
    return napis;
}

bool Porownanie(string napis1, string napis2, string napis3, string napis4, string napis5)
{
    if(SortowanieBabelkowe(napis1) != SortowanieBabelkowe(napis2))
    {
        return false;
    }
     if(SortowanieBabelkowe(napis1) != SortowanieBabelkowe(napis3))
    {
        return false;
    }
     if(SortowanieBabelkowe(napis1) != SortowanieBabelkowe(napis4))
    {
        return false;
    }
     if(SortowanieBabelkowe(napis1) != SortowanieBabelkowe(napis5))
    {
        return false;
    }
    return true;
}

int main()
{
    fstream plik;
    ofstream zapis;
    string slowo1, slowo2, slowo3, slowo4, slowo5;

    plik.open("anagram.txt");
    zapis.open("../PLIKI/odp_4b.txt");
    zapis << "b) ";

    while (!plik.eof())
    {
        plik >> slowo1 >> slowo2 >> slowo3 >> slowo4 >> slowo5;

        if (CzyJednakowaDlugosc(slowo1, slowo2, slowo3, slowo4, slowo5) == true && Porownanie(slowo1, slowo2, slowo3, slowo4, slowo5) == true)
        {
            zapis << slowo1 << " " << slowo2 << " " << slowo3 << " " << slowo4 << " " << slowo5 << endl;
        }
    }

    zapis.close();

    return 0;
}