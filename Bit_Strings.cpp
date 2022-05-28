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


int power(int a, int n, int m) {
    int res = 1;

    while (n) {
        if (n % 2) {
            res = (res * a) % m, n--;
        } else {
            a = (a * a) % m, n /= 2;
        }
    }
    return res;
} // O(log(n))



void solution() {
    int n;
    cin >> n;
    cout << power(2, n, MOD) << endl;
}


int32_t main() {
    fast;
    int test_cases = 1;
    /* cin >> test_cases; */
    while (test_cases--) {
        solution();
    }
}
