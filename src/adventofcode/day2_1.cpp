#include <string>
#include "..\templates\template.h"

int main() {
    int pos = 0;
    int depth = 0;

    string cmd;
    int d;
    while (cin >> cmd >> d) {
        if (cmd == "forward") {
            pos += d;
        } else depth += (cmd == "down" ? d : -d);
        if (depth < 0) cout << "Warning depth=" << depth << endl;
    }

    cout << pos * depth;

    return 0;
}