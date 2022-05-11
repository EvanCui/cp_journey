#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>

using namespace std;

using STR=string; using LL=long long;
template<class T> using V=vector<T>;template<class T> using VV=V<V<T>>; template<class T1, class T2> using P=pair<T1, T2>;
template<class T1, class T2> using M=map<T1, T2>; template<class T1, class T2> using UM=unordered_map<T1, T2>;
template<class T> using S=set<T>; template<class T> using US=unordered_set<T>;
using VI=V<int>; using VVI=V<VI>; using VLL=V<LL>; using VVLL=V<VLL>; using VS=V<STR>; using VB=V<bool>; using VVB=VV<bool>;
using PII=P<int, int>; using MII=M<int, int>; using SI=S<int>; using UII=UM<int, int>; using UI=US<int>;
V<PII> dir4{{-1,0},{1,0},{0,-1},{0,1}};
V<PII> dir8{{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
PII operator+(PII a, PII b){return{a.first+b.first,a.second+b.second};}VI operator+(VI& a,VI& b){return{a[0]+b[0],a[1]+b[1]};}
PII operator+(PII a, VI b){return{a.first+b[0],a.second+b[1]};}VI operator+(VI a,PII b){return{a[0]+b.first,a[1]+b.second};}
PII to_pii(VI a){return{a[0],a[1]};}VI to_vi(PII a){return{a.first,a.second};}
#define FOR(i, n) for (int i = 0; i < (n); i++)
void fast_io() { cin.tie(nullptr); ios::sync_with_stdio(false); }

class logger {
    template<class T> inline static void _info(const T &v) { cout << v; }
    inline static void _info(const string &v) { cout << v; }
    template<class K, class V> inline static void _info(const pair<K, V> &v) { info<'\0', false>('(', v.first, ',', v.second, ')'); }
    template<template<class...>class M,class...T>
    inline static void _info(const M<T...> &v){_info("[");int o=0;for(const auto &p:v){o++>0&&cout<<",";_info(p);}_info("]");}
public:
    template <char sep = ',', bool el = true, class... T> inline static void info(const T &...a) {
        size_t o=0; [_={(_info(a),++o<sizeof...(a)?(sep&&cout<<sep):(el&&cout<<endl))...}]{};
    }
};
#define LOG
template <class... T> inline static void info(const T &...args) {
#ifdef LOG
    logger::info(args...);
#endif
}

int main() {
    fast_io();
    int T;
    cin >> T;
    while (T--) {
        int n, m; cin >> n >> m;

        VVI a(n, VI(m, 0));
        VI left(m + n - 1);
        VI right(m + n - 1);
        FOR (i, n) FOR (j, m) {
            cin >> a[i][j];
            left[i + j] += a[i][j];
            right[j - i + n - 1] += a[i][j];
        }

        int ans = 0;
        FOR (i, n) FOR (j, m) {
            ans = max(ans, left[i+j] + right[j-i+n-1] - a[i][j]);
        }

        cout << ans << endl;
    }

    return 0;
}
