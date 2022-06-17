/*
    _________________________________________
   /                                         \
   | ; Title: cp template                    |
   | ; Author:  Sharishth Singh              |
   | ; Date: 22 May 2022                     |
   \                                         /
    -----------------------------------------
         \  ^__^
          \ (oo)\_______
            (__)\       )\/\
                ||----w |
                ||     ||
*/

#include "bits/stdc++.h"
#include <cerrno>
#include <codecvt>
#include <iostream>
using namespace std;
#define parr(x)                                                                 \
   cerr << #x << ' ' << '[' << ' ';                                             \
   for (auto z : x)                                                             \
      cerr << z << ' ';                                                         \
   cerr << ']' << endl
#define pmap(x)                                                                 \
   cerr << #x << ' ' << '{' << ' ';                                             \
   for (auto z : x)                                                             \
      cerr << '(' << ' ' << z.first << ' ' << z.second << ' ' << ')' << ' ';    \
   cerr << '}' << endl
#define fast                                                                    \
   ios_base::sync_with_stdio(false);                                            \
   cin.tie(NULL);                                                               \
   cout.tie(NULL);                                                              \
   cerr.tie(NULL);
#define ff first
#define ss second
#undef int
#define int unsigned long long int
#define endl '\n'
#define pi 3.1415926535
#define ve vector
int **memorized_dp_array;
int no_of_vertix = 0;
int **adj_matrix;
int MOD = 1e9 + 7;
map<int, vector<int>> tree;
int *vis;
char **grid;


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

int F[1000001];
int C(int n, int k, int P) {
    if (k > n)
        return 0;

    int res = F[n];
    res = (res * power(F[k], P - 2, P)) % P;
    res = (res * power(F[n - k], P - 2, P)) % P;
    return res;
}


void solution() {
   int q,w;
   cin >> q >> w;
   std::cout << C(q,w,MOD) << endl;
}

int32_t main() {
   fast;

   F[0] = F[1] = 1;
   for(int i = 2;i <= 1000000;i++){
       F[i] = (F[i-1]*i)%MOD;
   }
   int test_cases = 1;
   cin >> test_cases;
   while (test_cases--) {
      solution();
   }
}
