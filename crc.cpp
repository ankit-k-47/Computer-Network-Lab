#include <bits/stdc++.h>
using namespace std;

char exor(char a, char b)
{
    if (a == b)
        return '0';
    else
        return '1';
}
void r_crc(char data[], char div[])
{
    int datalen = strlen(data);
    int divlen = strlen(div);
    int codelen = datalen + divlen - 1;

    for (int i = 0; i < divlen; i++)
        data[datalen + i] = '0';
    data[codelen] = '\0';

    char temp[20], rem[20];
    for (int i = 0; i < divlen; i++)
        rem[i] = data[i];

    for (int j = divlen; j <= codelen; j++)
    {
        for (int i = 0; i < divlen; i++)
            temp[i] = rem[i];

        if (rem[0] == '0')
        {
            for (int i = 0; i < divlen - 1; i++)
                rem[i] = temp[i + 1];
        }
        else
        {
            for (int i = 0; i < divlen - 1; i++)
                rem[i] = exor(temp[i + 1], div[i + 1]);
        }
        if (j != codelen)
            rem[divlen - 1] = data[j];
        else
            rem[divlen - 1] = '\0';
    }

    for (int i = 0; i < divlen - 1; i++)
        data[datalen + i] = rem[i];
    data[codelen] = '\0';
    cout << "CRC=" << rem << "\nDataword=" << data;
}

void crc(char data[], char div[])
{
    int datalen = strlen(data);
    int divlen = strlen(div);
    int codelen = datalen + divlen - 1;

    for (int i = 0; i < divlen; i++)
        data[datalen + i] = '0';
    data[codelen] = '\0';

    char temp[20], rem[20];
    for (int i = 0; i < divlen; i++)
        rem[i] = data[i];

    for (int j = divlen; j <= codelen; j++)
    {
        for (int i = 0; i < divlen; i++)
            temp[i] = rem[i];

        if (rem[0] == '0')
        {
            for (int i = 0; i < divlen - 1; i++)
                rem[i] = temp[i + 1];
        }
        else
        {
            for (int i = 0; i < divlen - 1; i++)
                rem[i] = exor(temp[i + 1], div[i + 1]);
        }
        if (j != codelen)
            rem[divlen - 1] = data[j];
        else
            rem[divlen - 1] = '\0';
    }

    for (int i = 0; i < divlen - 1; i++)
        data[datalen + i] = rem[i];
    data[codelen] = '\0';
    cout << "CRC=" << rem << "\nDataword=" << data;
    cout << "From Receiver Side : - " << endl;
    r_crc(data, div);
}

int main()
{
    char div[20], data[20];
    cout << "Enter the data" << endl;
    cin >> data;
    cout << "Enter the divisor" << endl;
    cin >> div;
    crc(data, div);
    return 0;
}

//100100
//1101