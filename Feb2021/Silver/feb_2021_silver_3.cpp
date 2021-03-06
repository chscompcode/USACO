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
int a[501][501];

ll solve() {
  ll ans = 0;
  for (int x1=0;x1<n;x1++) {
    vector<int> mn(n);
    for (int i=0;i<n;i++) {
      mn[i] = a[i][x1];
    }
    for (int x2=x1;x2<n;x2++) {
      for (int j=0;j<n;j++) {
        mn[j] = min(mn[j], a[j][x2]);
      }
      int y1 = 0;
      int h = -1;
      for (int y2=0;y2<n;y2++) {
        if (mn[y2] == 100) {
          h = y2;
        } else if (mn[y2] < 100) {
          y1 = y2+1;
          h = -1;
        }
        if (mn[y2] >= 100) {
          if (h != -1)
            ans += h - y1 + 1;
        }
      }
    }
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n;
  for (int i=0;i<n;i++) {
    for (int j=0;j<n;j++) {
      cin >> a[i][j];
    }
  }
  cout << solve() << endl;
  return 0;
}
