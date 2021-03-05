#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        string fence;
        cin >> fence;
        int y = 0;
        int max_y = INT_MIN;
        char max_dir = 'a';
        for (char c : fence) {
            if (c == 'N') y++;
            else if (c == 'S') y--;
            else if (c == 'E' && y > max_y) {
                max_y = y;
                max_dir = 'E';
            } else if (c == 'W' && y > max_y) {
                max_y = y;
                max_dir = 'W';
            }
        }
        if (max_dir == 'W') cout << "CCW\n";
        else cout << "CW\n";
    }
}