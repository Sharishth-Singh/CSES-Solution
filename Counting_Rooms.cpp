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
#include <climits>
#include <iostream>
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
int static memorized_dp_array[1001][1001];
int no_of_vertix = 0;
int **adj_matrix;
map<int,vector<int>> tree;

char arr[1001][1001];


int dir_x[] = {1,0,-1,0};
int dir_y[] = {0,1,0,-1};
void dfs (int x, int y){
    if(arr[x][y] == '#'){
        return;
    }
    arr[x][y] = '#';
    for (int i = 0; i < 4; i++) {
        if(arr[x+dir_x[i]][y+dir_y[i]] == '.'){
            dfs(x+dir_x[i],y+dir_y[i]);
        }
    }
}
void solution() {
    int n,m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(arr[i][j] == '.'){
                dfs(i,j);
                ans++;
            }
        }
    }
    std::cout << ans << endl;

}

int32_t main() {

    fast;
    /* memset(memorized_dp_array, -1, sizeof(memorized_dp_array)); */

    /* uncomment below lines to nCk... */

    /* F[0] = F[1] = 1; */
    /* for(int i = 2;i <= 1000000;i++){ */
    /*     F[i] = (F[i-1]*i)%MOD; */
    /* } */
    int test_cases = 1;

    /* phi_for_n_queryies(100000); */
    /* cout << phi_array[5] << endl; */

    /* cin >> test_cases; */

    /* seive(); // no. of prime till k */
    /* seive_factor(); // prime factor of a number */

    //  destination    <- adj_matrix
    // s
    // t
    // a
    // r
    // t
    /* int a = 1; */
    while (test_cases--) {
        /* cout << "Case #"<< a << ": "; */
        /* a++; */
        solution();

    }
}
