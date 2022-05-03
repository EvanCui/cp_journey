#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <queue>

using namespace std;

using STR = string;
using LL = long long;
template <class T>
using V = vector<T>;
template <class T>
using VV = V<V<T>>;
template <class T1, class T2>
using P = pair<T1, T2>;
template <class T1, class T2>
using M = map<T1, T2>;
template <class T1, class T2>
using UM = unordered_map<T1, T2>;
template <class T>
using S = set<T>;
template <class T>
using US = unordered_set<T>;
using VI = V<int>;
using VVI = V<VI>;
using VLL = V<LL>;
using VVLL = V<VLL>;
using VS = V<STR>;
using VB = V<bool>;
using VVB = VV<bool>;
using PII = P<int, int>;
using MII = M<int, int>;
using SI = S<int>;
using UII = UM<int, int>;
using UI = US<int>;
V<PII> dir4{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
V<PII> dir8{{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
PII operator+(PII a, PII b) { return {a.first + b.first, a.second + b.second}; }
VI operator+(VI &a, VI &b) { return {a[0] + b[0], a[1] + b[1]}; }
PII operator+(PII a, VI b) { return {a.first + b[0], a.second + b[1]}; }
VI operator+(VI a, PII b) { return {a[0] + b.first, a[1] + b.second}; }
PII to_pii(VI a) { return {a[0], a[1]}; }
VI to_vi(PII a) { return {a.first, a.second}; }
#define FOR(i, n) for (int i = 0; i < (n); i++)

class logger
{
    static constexpr bool LOG = 0;

    template <class T>
    inline static void _info(const T &v) { cout << v; }
    inline static void _info(const string &v) { cout << v; }
    template <class K, class V>
    inline static void _info(const pair<K, V> &v) { info<'\0', false>('(', v.first, ',', v.second, ')'); }
    template <template <class...> class M, class... T>
    inline static void _info(const M<T...> &v)
    {
        _info("[");
        int o = 0;
        for (const auto &p : v)
        {
            o++ > 0 && cout << ",";
            _info(p);
        }
        _info("]");
    }

public:
    template <char sep = ',', bool el = true, class... T>
    inline static void info(const T &...a)
    {
        if constexpr (LOG)
        {
            int o = 0;
            const auto &d = {(_info(a), ++o < sizeof...(a) ? (sep && cout << sep) : (el && cout << endl))...};
        }
    }
};

template <class... T>
inline static void info(const T &...args) { logger::info(args...); }

class fenwick {
public:
    VI f;
    fenwick(int n) : f(n, 0) { } 
    static int lowbit(int i) { return i & (-i); }

    void add(int i, int v) { while (i < f.size()) { f[i] += v; i += lowbit(i); } }
    int ask(int i) { int ans = 0; while (i) { ans += f[i]; i -= lowbit(i); } return ans; }
};

int main()
{
    int n, m;
    cin >> n >> m;

    VVI v(n+1, VI(2, 0));

    VVI e(n+1);

    FOR (i, m) 
    {
        int from, to;
        cin >> from >> to;
        e[from].push_back(to);
        // out
        v[from][0]++;
        // in
        v[to][1]++;
    }

    queue<PII> q;
    // auto comp = [](auto& v1, auto& v2) { return v1.second > v2.second; };
    // priority_queue<PII, vector<PII>, decltype(comp)> q(comp);
    VI v_len(n+1, 0);
    VI to_determine(n+1, 0);

    FOR (i, n) {
        int k = i + 1;
        if (v[k][0] > 1) {
            for (auto next : e[k]) {
                if (v[next][1] > 1) to_determine[next]++;
            }
        }
    }

    info("to deter", to_determine);
    FOR (i, n) {
        int k = i + 1;
        if (to_determine[k] == 0) q.push({ k, 1 });
    }

    int ans = 0;
    while (!q.empty()) {
        auto [cur, len] = q.front(); q.pop();
        ans = max(ans, len);
        info("dequeued", cur, len, to_determine, v_len);

        if (v[cur][0] < 2) continue;
        for (auto next : e[cur]) {
            if (v[next][1] > 1) {
                to_determine[next]--;
                v_len[next] = max(v_len[next], len);
                if (to_determine[next] == 0) {
                    q.push({ next, v_len[next] + 1 });
                }
            }
        }

        info("processed", cur, len, to_determine, v_len);
    }

    cout << ans << endl;

    return 0;
}