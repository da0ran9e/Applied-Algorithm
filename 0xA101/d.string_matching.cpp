#include <iostream>
#include <string>

using namespace std;

int main() {
    string P, T;
    cin >> T;
    cin >> P;
    int count = 0;

    size_t pos = P.find(T);
    while (pos != string::npos) {
        count++;
        pos = P.find(T, pos + 1);
    }
    
    cout << count << endl;

    return 0;
}
