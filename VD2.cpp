#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    double S = 0, i = 1;
    while(i <= n){
        S += (2 * i + 1) / (2 * i + 2);
        i++;
    }

    cout << S;
    return 0;
}
