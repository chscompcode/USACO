#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> cows;
unordered_map<string, int> zodiacMapping = {{"Ox", 0}, {"Tiger", 1}, {"Rabbit", 2}, 
                                            {"Dragon", 3}, {"Snake", 4}, {"Horse", 5}, 
                                            {"Goat", 6}, {"Monkey", 7}, {"Rooster", 8}, 
                                            {"Dog", 9}, {"Pig", 10}, {"Rat", 11}};
int calcDif (int zodiac1, int zodiac2) {
    if (zodiac1 == zodiac2) return 12;
    else if (zodiac2 > zodiac1) return abs(zodiac2 - zodiac1);
    else return 12 - abs(zodiac2 - zodiac1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cows.insert({"Bessie", 1200});
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        string cow1, born, in, relation, zodiac, y, from, cow2;
        cin >> cow1 >> born >> in >> relation >> zodiac >> y >> from >> cow2;
        int year = cows[cow2];
        int zodiacYear = abs(year % 12);
        if (relation.compare("previous") == 0) 
            cows.insert({cow1, year - calcDif(zodiacMapping[zodiac], zodiacYear)});
        else
            cows.insert({cow1, year + calcDif(zodiacYear, zodiacMapping[zodiac])});
    }
    cout << abs(cows["Bessie"] - cows["Elsie"]) << "\n";
}