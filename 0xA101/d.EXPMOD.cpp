#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int pow_mod(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = (1LL * res * a) % mod;
        a = (1LL * a * a) % mod;
        b >>= 1;
    }
    return res;
}

int string_to_int(string s) {
    int res = 0;
    for (char c : s) res = (res * 10 + c - '0') % mod;
    return res;
}

string pow_mod(string a, string b) {
    int x = string_to_int(a);
    int y = string_to_int(b);
    return to_string(pow_mod(x, y));
}
int main(){
    long long a,b;
    cin >> a >> b;
    string num1, num2;
    num1 = to_string(a);
    num2 = to_string(b);
    cout << pow_mod(num1, num2);
}


