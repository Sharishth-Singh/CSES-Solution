/*
 _________________________________________
/                                         \
| ; Title:  cp template                   |
| ; Author: Sharishth Singh               |
| ; Date:   22 May 2022                   |
\                                         /
 -----------------------------------------
        \   ^__^
         \  (oo)\_______
            (__)\       )\/\
                ||----w |
                ||     ||
*/
#include "bits/stdc++.h"
#include <cstring>
#include <iostream>
#include <memory>
#include <vector>
using namespace std;
#define parr(x)                                                                 \
    cout << #x << ' ' << '[' << ' ';                                            \
    for (auto z : x)                                                            \
        cout << z << ' ';                                                       \
    cout << ']' << endl
#define pmap(x)                                                                 \
    cout << #x << ' ' << '{' << ' ';                                            \
    for (auto z : x)                                                            \
        cout << '(' << ' ' << z.first << ' ' << z.second << ' ' << ')' << ' ';  \
    cout << '}' << endl
#define fast                                                                    \
    ios_base::sync_with_stdio(false);                                           \
    cin.tie(NULL);                                                              \
    cout.tie(NULL);
#define ff first
#define ss second
#undef int
#define int long long int
#define endl '\n'
#define MOD 1000000007
#define pi 3.1415926535
#define ve vector
/* int static memorized_dp_array[1001][1001]; */
int no_of_vertix = 0;
int **adj_matrix;


/* int ans = 0; */
/* int an = 0; */
int fun(int n,vector<int>dp){
    dp[0] = 1;
    /* if(dp[n] != -1){ ans += dp[n];return; } */
    /* if(n == 0) {ans += 1;return; } */
    /* if(n < 0) {ans += 0;return; } */
    for(int j = 1;j<=n;j++)
    {
        for (int i = 1; i <=6; i++) {
            if(j-i >= 0)
            {
                /* std::cout << n-i << " "<<n << " " << i << " "<< ans << endl; */
                /* fun(n-i,dp); */
                dp[j] += dp[j-i];
                dp[j] = dp[j]%MOD;
            }
        }
    }
    /* parr(dp); */
    return dp[n];
}


void solution() {
    int n;
    cin >> n;
    vector<int> dp(n+1);
    int ans = fun(n,dp);
        cout << ans << endl;
    /* cout << an << endl; */
}


int32_t main() {
    fast;
    int test_cases = 1;
    /* cin >> test_cases; */
    while (test_cases--) {
        solution();
    }
}
