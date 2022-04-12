#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

typedef long long LL;
typedef vector<vector<int>> VVI;
typedef vector<int> VI;
typedef vector<LL> VLL;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef map<int, int> MII;
typedef unordered_map<int, int> UII;

class logger {
    static constexpr bool LOG = true;

    template <class T> inline static void _info(const T &v) { cout << v; }
    inline static void _info(const string &v) { cout << v; }
    template <class K, class V> inline static void _info(const pair<K, V> &v) { info<'\0', false>('(', v.first, ',', v.second, ')'); }
    template <template <class T1, class T2> class M, class K, class V>
    inline static void _info(const M<K, V> &v) { _info("["); bool f = true; for (auto &p : v) { f = f || (cout << "," && false); _info(p); } _info("]"); }
    public:
    template <char sep = ',', bool el = true, class... T> inline static void info(const T &...args) {
        if constexpr (LOG) {
            bool f = true;
            const auto &dummy = {(f || (sep != '\0' && cout << sep), _info(args), f = false)...};
            if constexpr (el) cout << endl;
        }
    }
};

template <class... T> inline static void info(const T &...args) { logger::info(args...); }
