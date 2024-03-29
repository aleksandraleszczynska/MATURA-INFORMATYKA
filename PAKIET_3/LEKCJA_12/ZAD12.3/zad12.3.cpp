// Napisz program, który posortuje tablicę rosnąco za pomocą zmodyfikowanego algorytmu sortowania szybkiego, w którtym użytkownik podaje, który element poczatkowej tablicy jest pierwszym pivotem.

#include <iostream>

using namespace std;

void quicksort(int tablica[], int lewyindex, int prawyindex, int pivotindex)
{
    int licznikIndex = lewyindex;
    int granica = lewyindex - 1;
    int pivot = tablica[pivotindex];

    if (lewyindex >= prawyindex)
    {
        return;
    }

    while (licznikIndex <= prawyindex)
    {
        if (tablica[licznikIndex] < pivot)
        {
            granica++;
            if (granica != licznikIndex)
            {
                swap(tablica[granica], tablica[licznikIndex]);
            }
        }

        licznikIndex++;
    }

    granica++;
    if (granica != prawyindex)
    {
        swap(tablica[granica], tablica[pivotindex]);
        pivotindex = granica;
    }

    quicksort(tablica, lewyindex, granica - 1, granica - 1);
    quicksort(tablica, granica + 1, prawyindex, prawyindex);
}

int main()
{
    int tablica[8] = {3, 5, 1, 2, 7, 8, 1, 9};
    int lewy = 0;
    int prawy = 7;
    int pivotindex = 2;
    quicksort(tablica, lewy, prawy, pivotindex);

    for (int i = 0; i < 8; i++)
    {
        cout << tablica[i] << " ";
    }

    return 0;
}