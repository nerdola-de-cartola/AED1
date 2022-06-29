#include <iostream>
#include <iomanip>
using namespace std;

int n;
int x[9];
bool a[9], b[17], c[17];

void Print();
void Try(int i);

int main() {
    int i;

    cout << "Tamanho do tabuleiro (1-8): ";
    cin >> n;

    for(i = 1; i <= 8; i++) a[i] = true;
    for(i = 2; i <= 16; i++) {
        b[i] = true;
        c[i] = true;
    }

    Try(1);

    return 0;
}

void Print() {
    int i;

    for(i = 1; i <= n; i++) {
        cout << "(" << i;
        cout << "," << x[i];
        cout << ") ";
    }

    cout << endl;
}

void Try(int i) {
    int j;

    for(j = 1; j <= n; j++) {
        if(a[j] && b[i+j] && c[i-j+9]) {
            x[i] = j;
            a[j] = b[i+j] = c[i-j+9] = false;
            if(i < n) Try(i+1);
            else Print();
            a[j] = b[i+j] = c[i-j+9] = true;
        }
    }
}