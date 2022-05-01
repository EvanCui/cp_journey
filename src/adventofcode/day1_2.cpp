#include <queue>
#include "..\templates\template.h"

int main() {
    int d;
    int ans = 0;
    queue<int> q;
    for (int i = 0; i < 3; i++) {
        if (!(cin >> d)) break;
        q.push(d);
    }

    while (cin >> d) {
        int f = q.front(); q.pop();
        if (d > f) ans++;
        q.push(d);
    }

    cout << ans << endl;
}