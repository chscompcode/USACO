#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <set>

#define INF 1000000001
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define MOD 1000000007

typedef long long ll;

using namespace std;

int n;
bool grid[3001][3001];
int adj[3001][3001];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int ans = 0;

void dfs(int r, int c) {
  if (grid[r][c] == 0) {
    grid[r][c] = 1;
    ans++;
    if (grid[r][c] == 1 && adj[r][c] == 3) {
      for (int i=0;i<4;i++) {
        dfs(r+dx[i], c+dy[i]);
      }
    }
    for (int i=0;i<4;i++) {
      int u = r + dx[i];
      int v = c + dy[i];
      adj[u][v]++;
      if (grid[u][v] == 1 && adj[u][v] == 3) {
        for (int j=0;j<4;j++) {
          dfs(u+dx[j], v+dy[j]);
        }
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n;
  for (int i=0;i<n;i++) {
   int u, v;
   cin >> u >> v;
   ans--;
   dfs(u+1000, v+1000);
   cout << ans << "\n";
  }
  return 0;
}
