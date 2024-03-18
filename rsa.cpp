#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b)
{
    int t;
    while (1)
    {
        t = a % b;
        if (t == 0)
            return b;
        a = b;
        b = t;
    }
}

int main()
{
    double p, q;
    cout << "Enter the value for p : ";
    cin >> p;
    cout << "Enter the value for q : ";
    cin >> q;

    double n = p * q;
    double phi = (p - 1) * (q - 1);
    double e, temp;
    cout << "Enter the value of e : ";
    cin >> e;

    while (e < phi)
    {
        temp = gcd(e, phi);
        if (temp == 1)
            break;
        else
            e++;
    }

    double d1 = 1 / e;
    double d = fmod(d1, phi);

    double message;
    cout << "Enter the message : ";
    cin >> message;

    double c = pow(message, e);
    double m = pow(c, d);
    c = fmod(c, n);
    m = fmod(m, n);

    cout << "p : " << p << endl;
    cout << "q : " << q << endl;
    cout << "n : " << n << endl;
    cout << "Phi : " << phi << endl;
    cout << "Public key d : " << d << endl;
    cout << "Private key e : " << e << endl;
    cout << "Plain Text : " << message << endl;
    cout << "Cipher Text : " << c << endl;
    cout << "Decrypting the message : " << m << endl;

    return 0;
}

// 13 11 7 9 - inputs