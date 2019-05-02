#include <iostream>
using namespace std;

int find(int a[], int nr, int el)
{
    for(int i=0; i<=nr; i++)
        if (a[i] == el)
            return i;
    return -1;
}

unsigned long difference(unsigned long a, unsigned long b)
{
    if (a-b < 0)
        return b-a;
    else
        return a-b;
}

int main()
{
    int n, val;
    cout << "n=";
    cin >> n;
    int *v=new int[n];
    cout << "Elements the elements of array:" << endl;
    for(int i=0; i<n; i++)
        cin >> v[i];
    cout << "val=";
    cin >> val;
    int result = find(v, n, val);
    cout << "Position of the searched element=" << result << endl;
    delete v;
    unsigned long x, y;
    x=550000;
    y=550005;
    cout << "Difference=" << difference(x, y) << endl;
    return 0;
}
