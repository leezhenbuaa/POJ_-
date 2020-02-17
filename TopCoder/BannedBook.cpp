// BEGIN CUT HERE

// END CUT HERE
#line 5 "BannedBook.cpp"
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<pair<int, int> > vii;
typedef long long ll;
#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
const int inf = 1e9;
const int mod = 1e9 + 7;

class BannedBook {
 public:
  int n;
  vector<vi> adj;
  vector<int> passAround(vector<string> friends) {
    vi ans;
    n = friends.size();
    adj.assign(n, vi(0));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (i == j) continue;
        if (friends[i][j] == 'Y') adj[i].push_back(j);
      }
    }
    vi vist(n, 0);
    REP(i, 0, n) {
      if (!vist[i]) {
        dfs_first(i, vist, ans);
      }
    }
    return ans;
  }
  void dfs_first(int u, vi &vist, vi &ans) {
    vist[u] = 1;
    ans.push_back(u);
    REP(i, 0, adj[u].size()) {
      int v = adj[u][i];
      if (!vist[v]) dfs_last(v, vist, ans);
    }
  }
  void dfs_last(int u, vi &vist, vi &ans) {
    vist[u] = 1;
    REP(i, 0, adj[u].size()) {
      int v = adj[u][i];
      if (!vist[v]) dfs_first(v, vist, ans);
    }
    ans.push_back(u);
  }

  // BEGIN CUT HERE
 public:
  void run_test(int Case) {
    if ((Case == -1) || (Case == 0)) test_case_0();
    if ((Case == -1) || (Case == 1)) test_case_1();
    if ((Case == -1) || (Case == 2)) test_case_2();
    if ((Case == -1) || (Case == 3)) test_case_3();
  }

 private:
  template <typename T>
  string print_array(const vector<T> &V) {
    ostringstream os;
    os << "{ ";
    for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end();
         ++iter)
      os << '\"' << *iter << "\",";
    os << " }";
    return os.str();
  }
  void verify_case(int Case, const vector<int> &Expected,
                   const vector<int> &Received) {
    cerr << "Test Case #" << Case << "...";
    if (Expected == Received)
      cerr << "PASSED" << endl;
    else {
      cerr << "FAILED" << endl;
      cerr << "\tExpected: " << print_array(Expected) << endl;
      cerr << "\tReceived: " << print_array(Received) << endl;
    }
  }
  void test_case_0() {
    string Arr0[] = {"YNN", "NYN", "NNY"};
    vector<string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    int Arr1[] = {0, 1, 2};
    vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    verify_case(0, Arg1, passAround(Arg0));
  }
  void test_case_1() {
    string Arr0[] = {"YYYYY", "YYNNN", "YNYNN", "YNNYN", "YNNNY"};
    vector<string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    int Arr1[] = {0, 1, 2, 3, 4};
    vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    verify_case(1, Arg1, passAround(Arg0));
  }
  void test_case_2() {
    string Arr0[] = {"YYNNN", "YYYNN", "NYYYN", "NNYYY", "NNNYY"};
    vector<string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    int Arr1[] = {0, 2, 4, 3, 1};
    vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    verify_case(2, Arg1, passAround(Arg0));
  }
  void test_case_3() {
    string Arr0[] = {"YYNNYNYNN", "YYNNNYNNN", "NNYNNNNNN",
                     "NNNYNNNNN", "YNNNYNNNY", "NYNNNYNYN",
                     "YNNNNNYNY", "NNNNNYNYN", "NNNNYNYNY"};
    vector<string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    int Arr1[] = {0, 5, 7, 1, 8, 6, 4, 2, 3};
    vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    verify_case(3, Arg1, passAround(Arg0));
  }

  // END CUT HERE
};

// BEGIN CUT HERE
int main() {
  BannedBook ___test;
  ___test.run_test(-1);
  system("pause");
}
// END CUT HERE
