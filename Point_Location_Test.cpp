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
#include <algorithm>
#include <cmath>
#include <iostream>
#include <iterator>
#include <utility>
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
int *vis;
char **grid;


int gcd(int a, int b) {
   if (b == 0) {
      return a;
   } else {
      return gcd(b, a % b);
   }
}


vector<int> printDivisors(int n) {
   vector<int> a;
   for (int i = 1; i * i <= n; i++) {
      if (n % i == 0) {
         if (n / i == i)
            a.push_back(i);

         else
            a.push_back(i), a.push_back(n / i);
      }
   }
   return a;
}

void solution() {
   int n;
   cin >> n;
   int ans = printDivisors(n).size();
   ans--;
   if(n%2 == 0){
      std::cout << ans*2 -1 << endl;
   }
   else{
      std::cout << ans*2 << endl;
   }
}

int32_t main() {
   fast;
   int test_cases = 1;
   cin >> test_cases;
   while (test_cases--) {
      solution();
   }
}
