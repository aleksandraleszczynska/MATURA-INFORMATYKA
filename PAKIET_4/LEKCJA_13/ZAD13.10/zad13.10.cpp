// Rozważmy szyfr podstawieniowy działający zgodnie z następującymi zasadami:
// Tekst jawny, szyfrogram oraz klucz składają się wyłącznie z wielkich liter alfabetu angielskiego.
//  Litery ponumerowano i przyporządkowano im kody ASCII (liczby z zakresu 65–90): Tabela numerów i kodów ASCII poszczególnych liter
//      Kolejne litery tekstu jawnego są szyfrowane za pomocą kolejnych liter słowa będącego kluczem, być może powtórzonego wiele razy.
//      W procesie szyfrowania tekst jawny przekształcany jest na szyfrogram przy pomocy klucza poprzez dodanie do kodu litery tekstu jawnego numeru odpowiadającej jej litery klucza. Jeżeli tak uzyskana wartość liczbowa będzie większa od 90, należy ją zmniejszyć o 26. Szyfrem danej litery jest litera o tak uzyskanym kodzie. Poniższy przykład precyzuje zasady szyfrowania.
//  Przykład: Tekst jawny: LATO, klucz: WODA L+W = 76+23 = 99. Ponieważ przekroczono zakres 90, należy od 99 odjąć 26, czyli 99–26 = 73. Zatem zaszyfrowanym znakiem jest litera I. A+O = 65+15 = 80, czyli zaszyfrowanym znakiem jest litera P. T+D = 84+4 = 88, czyli zaszyfrowanym znakiem jest litera X. O+A = 79+1 = 80, czyli zaszyfrowanym znakiem jest litera P. Szyfrogram: IPXP
//      Jeżeli użyte słowo kluczowe jest zbyt krótkie, by wystarczyło do zaszyfrowania całego tekstu, należy użyć jego powtórzeń.
//  Przykład: Tekst jawny: MARTA, klucz: TOR M+T = 77+20 = 97, 97-26=71, G A+O = 65+15 =80, P R+R = 82+18= 100, 100-26 = 74, J T+T = 84+20 = 104, 104-26=78, N A+O = 65+15 =80, P Szyfrogram: GPJNP
//      W procesie deszyfrowania szyfrogram przekształcany jest na tekst jawny przy pomocy klucza poprzez odjęcie od kodu litery szyfrogramu numeru odpowiadającej jej litery klucza (jeżeli tak uzyskana wartość liczbowa będzie mniejsza od 65, należy ją powiększyć o 26) i odczytanie litery o otrzymanym kodzie.
//  a) W pliku tj.txt znajdują się niezaszyfrowane słowa, a w pliku klucze1.txt – klucze szyfrujące. W obu plikach wyrazy umieszczone są w osobnych wierszach. Zaszyfruj słowa zawarte w pliku tj.txt, wynik zapisz w pliku wynik4a.txt. Wyraz zapisany w N-tym wierszu w pliku z wynikami powinien stanowić szyfrogram tekstu jawnego znajdującego się w N-tym wierszu w pliku z tekstem jawnym uzyskany za pomocą klucza znajdującego się w N-tym wierszu pliku z kluczami.

#include <iostream>
#include <fstream>
using namespace std;

string szyfrowanie(string slowo, string klucz)
{
    string szyfrogram = "";
    char litera;

    for (int i = 0; i < slowo.length(); i = i + klucz.length())
    {
        for (int j = 0; j < klucz.length(); j++)
        {
            if (i + j >= slowo.length())
            {
                return szyfrogram;
            }
            else
            {
                litera = slowo[i + j] + (klucz[j] - 64);

                if (litera > 90)
                {
                    litera = litera - 26;
                }
                szyfrogram = szyfrogram + litera;
            }
        }
    }
}

int main()
{
    fstream plik1;
    fstream plik2;
    ofstream zapis;
    string slowo;
    string klucz;

    plik1.open("../PLIKI/tj.txt");
    plik2.open("../PLIKI/klucze1.txt");
    zapis.open("../PLIKI/wynik4a.txt");

    zapis << "a) ";

    while (!plik1.eof())
    {
        plik1 >> slowo;
        plik2 >> klucz;
        zapis << szyfrowanie(slowo, klucz) << endl;
    }
    zapis.close();
    return 0;
}