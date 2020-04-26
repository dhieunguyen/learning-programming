#include <iostream>
#include <string>

using namespace std;

string nextString(string binary)
{
    int i = binary.length() - 1;
    while (i >= 0 && binary[i] != '0')
    {
        binary[i] = '0';
        i--;
    }
    if(i>=0)
    binary[i] = '1';
    return binary;
}

int main()
{
    string binary;
    int t;
    cin>>t;
    while (t--)
    {
        cin>>binary;
        cout << nextString(binary) << "\n";
    }
    return 0;
}
