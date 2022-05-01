#include "..\templates\template.h"

int main() {
    int d;
    int last = INT_MAX;
    int ans = 0;
    while (cin >> d) {
        if (d > last) ans++;
        last = d;
    }

    cout << ans << endl;
}