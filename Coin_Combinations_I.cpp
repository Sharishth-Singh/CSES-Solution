/*
 _________________________________________
/                                         \
| ; Title: cp template                    |
| ; Author:  Sharishth Singh              |
| ; Date: 22 May 2022                     |
\                                         /
 -----------------------------------------
        \   ^__^
         \  (oo)\_______
            (__)\       )\/\
                ||----w |
                ||     ||
*/
#include "bits/stdc++.h"
using namespace std;

int32_t main() {
    int MOD = (int)1e9+7;
    int n,sum;
    cin >> n >> sum;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int dp[sum+1];
    for (int i = 0; i <= sum; i++) {
        dp[i] = 0;
    }
    dp[0] = 1;
    for (int i = 0; i <= sum; i++) {
        for (int j = 1; j <= n; j++) {
            if(arr[j-1] <= i)
            {
                dp[i] += dp[i-arr[j-1]];
                dp[i] %= MOD;
            }
        }
    }
    cout << dp[sum] << endl;
    return 0;
}
