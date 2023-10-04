#include <bits/stdc++.h>
#include "List.h"
#include "List.cpp"
using namespace std;

int main()
{
    List<int> L;
    for (int i = 0; i < 10; i++)
    {
        L.push_back(i);
    }
    L.erase(0,3);
    L.add(2,10);
    // L.clear();
    cout << L.getSize() << '\n';
    for (int i=0; i<L.getSize(); i++) {
        cout << L[i] <<' ';
    }
    // L.Display();
    return 0;
}
