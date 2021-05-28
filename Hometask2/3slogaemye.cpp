#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int maxn = 16;
vector<int> precompute()
{
    vector<int> dp(maxn, -1);
    dp[0] = 0;
    for (int i = 1; i < maxn; ++i) {
        for (auto j : vector<int>{ 4, 6, 9 }) {
            if (i >= j && dp[i - j] != -1) {
                dp[i] = max(dp[i], dp[i - j] + 1);
            }
        }
    }
    return dp;
}
int Maximum_Summands(vector<int> dp, int n){
    if (n < maxn)
        return dp[n];
    else {
        int t = (n - maxn) / 4 + 1;
        return t + dp[n - 4 * t];
    }
}
int main(){
    int n = 12;
    vector<int> dp = precompute();
    cout << Maximum_Summands(dp, n) << endl;
    return 0;
}