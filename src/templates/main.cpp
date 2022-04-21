#include "./template.h"

using namespace std;

int main()
{
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
}