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
#include <climits>
#include <iostream>
#include <regex>
#include <vector>
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
#define bug(x)                                                                  \
   cerr << #x << " : ";                                                         \
   cerr << x << endl
#define ff first
#define ss second
#undef int
#define int unsigned long long
#define endl '\n'
#define pi 3.1415926535
#define ve vector
int static **memorized_dp_array;
int no_of_vertix = 0;
int **adj_matrix;
int MOD = 1e9 + 7;
std::map<int, vector<int>> tree;
vector<int> vis;
char **grid;
vector<int> path;

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


/* MOD
   a == b (mod n)  => a = n*k + b
   => a^k == b^k (mod n)

   x^y (mod n)     => (x%n)^y

   (R/N)%P => (R%P) * (X%P)   [ (N*X)%P = 1 ] iff GCD(N,P) = 1

   if P is prime Number (x^(p-1)%13 = 1) => X = a^(-1) = a^(P-2) (mod P)
   */

/* NUMBER OF INTEGER CO-PRIME WITH P

   P^(x-1)(P-1)
   */

/* KNAPSACK

   Subset with sum equal to k (y/n)
   Subset sum equal to k (count)
   Equil sum subset(min diff) (y/n)
   Subset diff min (count)
   Diff b/w subset equal k (count)
   target sum (count)
   */



void solution() {
   int a,b,c;
   cin >> a >> b >> c;
   int temp = power(b, c,MOD-1);
   std::cout << power(a, temp, MOD) << endl;
}

int32_t main() {
   fast;
   int test_cases = 1;
   cin >> test_cases;
   while (test_cases--) {
      solution();
   }
}

