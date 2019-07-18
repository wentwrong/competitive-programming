// https://www.hackerrank.com/challenges/abbr/
#include <bits/stdc++.h>
using namespace std;

string abbreviation(string a, string b) {
    bool dp[a.size()+1][b.size()+1];
    for(size_t i = 0; i <= a.size(); i++)
        for(size_t j = 0; j <= b.size(); j++)
            dp[i][j] = false;
    dp[0][0] = true;
    for(size_t i = 0; i <= a.size(); i++) {
        for(size_t j = 0; j <= b.size(); j++) {
            if(dp[i][j]) {
                if(j < b.size() && toupper(a[i]) == b[j]) dp[i+1][j+1] = true;
                if(islower(a[i])) dp[i+1][j] = true;
            }
        }
    }
    return (dp[a.size()][b.size()] ? "YES" : "NO");
}

int main()
{
    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string a,b;
        getline(cin, a);
        getline(cin, b);

        string result = abbreviation(a,b);

        cout << result << "\n";
    }
    
    return 0;
}
