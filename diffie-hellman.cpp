#include <bits/stdc++.h>
using namespace std;
long long int power(long long a, long long b, long long c)
{

    if (b == 1)
        return a;
    else
    {
        return (((long long int)pow(a, b)) % c);
    }
}

int main()
{
    long long int P, g, a, b, r1, r2, ka, kb;

    cout << "Enter the value of P : ";
    cin >> P;
    cout << "Enter the valued of g : ";
    cin >> g;

    cout << "Enter the private key for Alice : ";
    cin >> a;
    r1 = power(g, a, P);

    cout << "Enter the private key for Bob : ";
    cin >> b;
    r2 = power(g, b, P);

    ka = power(r2, a, P);
    kb = power(r1, b, P);

    cout << "Secret key for Alice is : " << ka << endl;
    cout << "Secret key for Bob is : " << kb << endl;

    return 0;
}

// 23 9 4 3 - inputs