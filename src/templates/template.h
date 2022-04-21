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
using VI=V<int>; using VVI=V<VI>; using VLL=V<LL>; using VVLL=V<VLL>; using VS=V<STR>;
using PII=P<int, int>; using MII=M<int, int>; using SI=S<int>; using UII=UM<int, int>; using UI=US<int>;

class logger {
    static constexpr bool LOG = 1;

    template<class T> inline static void _info(const T &v) { cout << v; }
    inline static void _info(const string &v) { cout << v; }
    template<class K, class V> inline static void _info(const pair<K, V> &v) { info<'\0', false>('(', v.first, ',', v.second, ')'); }
    template<template<class...>class M,class...T>
    inline static void _info(const M<T...> &v){_info("[");int o=0;for(auto &p:v){o++>0&&cout<<",";_info(p);}_info("]");}
public:
    template <char sep = ',', bool el = true, class... T> inline static void info(const T &...a) {
        if constexpr(LOG){int o=0; const auto &d={(_info(a),++o<sizeof...(a)?(sep&&cout<<sep):(el&&cout<<endl))...};}
    }
};

template <class... T> inline static void info(const T &...args) { logger::info(args...); }
