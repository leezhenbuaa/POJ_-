/*
ID: leezhen
TASK: practice
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <bitset>
#include <list>

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<pair<int, int> > vii;
typedef long long ll;

// struct
#define inf 1e9
#define REP(i, a, b) for(int i = int(a); i < int(b); i++)

// data


int main() {
  int n;
  double costs[1024];
  while(scanf("%d", &n), n) {
    double sum = 0;
    REP(i, 0, n) scanf("%lf", &costs[i]), sum += costs[i];
    sum = round(sum*100.0/n)/100;
    double ans1 = 0, ans2 = 0;
    REP(i, 0, n) {
      if(costs[i] > sum) {
        ans1 += costs[i] - sum;
      } else {
        ans2 += sum - costs[i];
      }
    }
    printf("$%.2f\n", min(ans1, ans2));
  }
  return 0;
}
