/*
ID: leezhen
TASK: practice
LANG: C++11
*/
#include <assert.h>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <iterator>
#include <map>
#include <new>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<pair<int, int> > vii;
typedef long long ll;
#define bit(x, i) (x & (1 << i))
#define IN(i, l, r) (l < i && i < r)
#define LINR(i, l, r) (l <= i && i <= r)
#define LIN(i, l, r) (l <= i && i < r)
#define INR(i, l, r) (l < i && i <= r)
#define getI(a) scanf("%d", &a)
#define getII(a, b) scanf("%d%d", &a, &b)
#define getIII(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define getS(x) scanf("%s", x)
#define clr(a, x) memset(a, x, sizeof(a))
#define char2Int(c) (c - '0')
#define sz(x) ((int)((x).size()))
#define all(c) (c).begin(), (c).end()
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
// for debug
#define what_is(x) \
  cerr << "Line " << __LINE__ << ": " << #x << " is " << (x) << endl;
#define error(args...)                       \
  {                                          \
    string _s = #args;                       \
    replace(_s.begin(), _s.end(), ',', ' '); \
    stringstream _ss(_s);                    \
    istream_iterator<string> _it(_ss);       \
    err(_it, args);                          \
  }

template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << a << endl;
  err(++it, args...);
}

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int fx[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
const int fxx[8][2] = {{0, 1}, {0, -1}, {1, 0},  {-1, 0},
                       {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

// struct

// data
const int N = 1000010;
int n;
char s[N];
vi p[2][N];
int cxt[2][N];

int main() {
  getI(n);
  getS(s);
  for (int i = n - 1; i >= 0; i--) {
    if (s[i] != '0') cxt[0][i] = cxt[0][i + 1] + 1;
    if (s[i] != '1') cxt[1][i] = cxt[1][i + 1] + 1;
  }
  REP(i, 0, 2) {
    int l = 0;
    while (l < n) {
      if (s[l] == char(i + '0')) {
        ++l;
        continue;
      }
      int r = l + 1;
      while (r < n && s[r] != char('0' + i)) ++r;
      for (int len = 1; len <= r - l; len++) {
        p[i][len].push_back(l);
      }
      l = r;
    }
  }
  printf("%d ", n);
  REP(i, 2, n + 1) {
    int pos = 0, ans = 0;
    int p0 = 0, p1 = 0;
    while (pos < n) {
      int npos = inf;
      if (cxt[0][pos] >= i) npos = pos + i;
      if (cxt[1][pos] >= i) npos = pos + i;
      while (p0 < sz(p[0][i]) && pos > p[0][i][p0]) ++p0;
      if (p0 < sz(p[0][i])) npos = min(npos, p[0][i][p0] + i);
      while (p1 < sz(p[1][i]) && pos > p[1][i][p1]) ++p1;
      if (p1 < sz(p[1][i])) npos = min(npos, p[1][i][p1] + i);
      if (npos != inf) ++ans;
      pos = npos;
    }
    printf("%d ", ans);
  }
  printf("\n");
  return 0;
}
