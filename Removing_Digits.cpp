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
#include <climits>
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

int fun (int N){
    if(N == 0){
        return 0;
    }
    int ma = -INT_MAX;
    int n = N;
    while(n != 0){
        int q = n%10;
        if(q > ma){
            ma = q;
        }
        n /= 10;
    }
    N -= ma;
    return 1+fun(N);
}


void solution() {
    int n;
    cin >> n;
    cout << fun(n) << endl;
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
