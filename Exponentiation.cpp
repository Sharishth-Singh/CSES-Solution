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
#define int long long int
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
int n,m;

void dfs(int start){
   for (auto i : tree[start]) {
      if(vis[i] == 0){

      }
   }
}


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
   int a,b;
   cin >> a >> b;
   std::cout << power(a, b, MOD) << endl;
}

int32_t main() {
   fast;
   int test_cases = 1;
   cin >> test_cases;
   while (test_cases--) {
      solution();
   }
}

