#include "./template.h"

using namespace std;

int main() {
    info(pair<int, string>(1, "ddd"));
    info("abc");
    info("abc", 123);
    info("abc", 123, 2.5);
    info("abc", 123, 2.5, pair<int, string>(1, "ddd"));
    info(map<int, string>({ { 1, "abc" }}));
    info(unordered_map<int, string>({ { 1, "abc" }}));
    info("abc", 123, 2.5, vector<int>({1,2,3}));
}