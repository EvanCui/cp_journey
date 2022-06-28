#include "./template.h"

using namespace std;

int main()
{
    fast_io();
    logger::info(pair<int, string>(1, "ddd"));
    STR s = "abc";
    info(s);
    LL l = 25L;
    info(l);

    VI vi{1, 2, 3, 4, 5};
    info(vi);
    VVI vvi{{1, 2, 3}, {4, 5, 6}};
    info(vvi);
    VLL vll{1, 2, 3, 4, 5};
    info(vll);
    VVLL vvll{{1, 2, 3}, {4, 5, 6}};
    info(vvll);
    VS vs{"abc", "def"};
    info(vs);
    PII pii{1, 2};
    info(pii);
    MII mii{{1, 2}, {3, 4}};
    info(mii);
    SI si{1, 2, 3, 4};
    info(si);
    UII uii{{1, 2}, {3, 4}};
    info(uii);
    UI ui{1, 2, 3, 4};
    info(ui);
    info(vi, vvi, vll, vvll, vs, pii, mii, si, uii, ui);

    M<int, STR> mis = {{1, "abc"}, {2, "def"}};
    info(mis);

    VV<UII> vvuii(1, V<UII>(1));
    vvuii[0][0][2] = 5;
    info(vvuii);

    UM<int, STR> umis{{1, "abc"}, {2, "def"}};
    info(umis);

    UM<STR, VVB> umstrvvb;
    umstrvvb["abc"] = VVB(2, VB(2, true));
    umstrvvb["def"] = VVB(2);
    info(umstrvvb);
    for (auto it : umstrvvb) {
        info(it);
    }

    PII pii_ori{1, 1};
    for (auto d : dir4) { info(pii_ori + d); }
    for (auto d : dir8) { info(pii_ori + d); }
    for (auto d : dir4) { info(to_vi(pii_ori) + d); }
    for (auto d : dir8) { info(to_vi(pii_ori) + d); }
    VI vi_ori{1, 1};
    for (auto d : dir4) { info(to_vi(to_pii(vi_ori) + d)); }
    for (auto d : dir8) { info(to_vi(to_pii(vi_ori) + d)); }
    for (auto d : dir4) { info(vi_ori + d); }
    for (auto d : dir8) { info(vi_ori + d); }
    VVB vvb;
    vvb.assign(2, VB(2, false));
    info(vvb);

    tuple t { 2, "abc", 3.5 };
    tuple t1 {};
    info(t);
    info(t1);
}