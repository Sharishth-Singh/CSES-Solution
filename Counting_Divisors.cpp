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
#include <codecvt>
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
#define int long long int
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

// prime factor using seive
int ar[1000001];
void seive_factor() {
   int maxN = 1000000;
   for (int i = 1; i <= maxN; i++)
      ar[i] = 0;

   for (int i = 2; i <= maxN; i++) {
      /* if (ar[i] == -1) { */
         for (int j = i; j <= maxN; j += i) {
            /* if (ar[j] == -1) { */
               ar[j] += 1;
            /* } */
         }
      /* } */
   }
}

void solution() {
   int n;
   cin >> n;
   std::cout << ar[n]+1 << endl;
}

int32_t main() {
   fast;
   seive_factor();
   int test_cases = 1;
   cin >> test_cases;
   while (test_cases--) {
      solution();
   }
}
