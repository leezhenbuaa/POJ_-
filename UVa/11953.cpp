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

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<pair<int, int> > vii;
char g[105][105];
int n;
void dfs(int i, int j) {
    if(i >= n || j >= n || i < 0 || j < 0)
        return;
    if(g[i][j] == '.')  return;
    g[i][j] = '.';
    dfs(i+1, j);
    dfs(i-1, j);
    dfs(i, j+1);
    dfs(i, j-1);
}
int main() {
    int cases = 0, i, j;
    scanf("%*d");
    while(scanf("%d", &n) == 1) {
        for(i = 0; i < n; i++)
            scanf("%s", g[i]);
        int res = 0;
        for(i = 0; i < n; i++)
            for(j = 0; j < n; j++)
                if(g[i][j] == 'x')
                    res++, dfs(i, j);
        printf("Case %d: %d\n", ++cases, res);
    }
    return 0;
}
