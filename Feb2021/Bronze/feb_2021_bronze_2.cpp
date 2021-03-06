#include <bits/stdc++.h>
#include <cstdio>
#define FAST_IO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);cerr.tie(0)
#define pb push_back
#define all(x) begin(x), end(x)
#define umap unordered_map
#define TEST_CASES int a; cin >> a; for (int i = 0; i < a; i++) {solve(); cout << endl;}
using namespace std;
typedef long long ll;
typedef long double ld;
vector<vector<int>> vec(1001, vector<int> (1001));
int comfort (int x, int y){
    int curr = 0;
    if (x != 0){
        if (vec[x-1][y] == 1){
            curr++;
        }
    }
    if (y != 0){
        if (vec[x][y-1] == 1){
            curr++;
        }
    }
    if (x != 1000){
        if (vec[x+1][y] == 1){
            curr++;
        }
    }
    if (y != 1000){
        if (vec[x][y+1] == 1){
            curr++;
        }
    }
    if (curr == 3){
        return 1;
    }
    if (curr == 4){
        return -1;
    }
    return 0;
}
void solve() {
    int b; cin >> b;
    int res = 0;
    for (int i = 0; i < b; i++){
        int x, y; cin >> x >> y;
        vec[x][y] = 1;
        int curr = 0;
        if (x != 0){
            if (vec[x-1][y] == 1){
                curr++;
                res += comfort(x-1, y);
            }
        }
        if (y != 0){
            if (vec[x][y-1] == 1){
                curr++;
                res += comfort(x, y-1);
            }
        }
        if (x != 1000){
            if (vec[x+1][y] == 1){
                curr++;
                res += comfort(x+1, y);
            }
        }
        if (y != 1000){
            if (vec[x][y+1] == 1){
                curr++;
                res += comfort(x, y+1);
            }
        }
        if (curr == 3){
            res++;
        }
        cout << res << endl;
    }
}
int main() {
    FAST_IO;
    //freopen("moocast.in", "r", stdin);
    //freopen("moocast.out", "w", stdout);
    //TEST_CASES;
    solve(); //cout << endl;
}