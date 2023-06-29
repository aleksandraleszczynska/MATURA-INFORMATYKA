// Napisz program, który obliczy iteracyjnie NWD z wpisanych przez użytkownika liczb.

#include <iostream>

using namespace std;

int NWD(int liczba1, int liczba2)
{
    while (liczba1 != liczba2)
    {
         if(liczba1 > liczba2)
        {
            liczba1 = liczba1 - liczba2;
        }
        else
        {
            liczba2 = liczba2 - liczba1;
        }
    }

    return liczba1;

    }

int main()
{
    cout << NWD(30,20);
    return 0;
}