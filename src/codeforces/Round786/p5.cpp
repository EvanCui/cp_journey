#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

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

int minhit(int k)
{
    return (k + 1) / 2;
}

int main()
{
    int n;
    cin >> n;
    VI nums(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    int ans = INT_MAX;

    // adjacent
    for (int i = 0; i < n - 1; i++)
    {
        int ma = max(nums[i], nums[i + 1]);
        int mi = min(nums[i], nums[i + 1]);
        if (ma >= mi * 2)
        {
            ans = min(ans, minhit(ma));
        }
        else
        {
            ans = min(ans, (ma + mi + 2) / 3);
        }
    }

    // separate by 1
    for (int i = 0; i < n - 2; i++)
    {
        int sum = nums[i] + nums[i + 2];
        ans = min(ans, minhit(sum));
    }

    // totally separated
    auto low = min_element(nums.begin(), nums.end());
    int mi1 = *low;
    *low = INT_MAX;
    int mi2 = *min_element(nums.begin(), nums.end());
    info(mi1, mi2, ans);

    ans = min(ans, minhit(mi1) + minhit(mi2));

    cout << ans << endl;
    return 0;
}