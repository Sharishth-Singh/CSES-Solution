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
#include <bitset>
#include <cerrno>
#include <codecvt>
#include <cstddef>
#include <iostream>
#include <map>
#include <set>
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
int **memorized_dp_array;
int no_of_vertix = 0;
int **adj_matrix;
int MOD = 1e9 + 7;
map<int, vector<int>> tree;
int *vis;
char **grid;


int Binary_Search_left(vector<int> a, int ele,int n) // left most closest element
{
   /* a.resize(n); */
   int l = -1, r = n;
   while (r > l + 1) {
      int mid = (l + r) / 2;
      if (a[mid] <= ele) {
         l = mid;
      } else {
         r = mid;
      }
   }
   return l ;
}

void solution() {
   int n,m;
   cin >> n >> m;
   multiset<int> va;
   for (int i = 0; i < n; i++) {
      int q;
      cin >> q;
      va.insert(q);
   }
   for (int i = 0; i < m; i++) {
      int q;
      cin >> q;
      auto it = va.upper_bound(q);
      if(it == va.begin()){
         std::cout << -1 << endl;
      }
      else{
         std::cout << *(--it) << endl;
         va.erase(it);
      }
   }
}

int32_t main() {
   fast;
   int test_cases = 1;
   /* cin >> test_cases; */
   while (test_cases--) {
      solution();
   }
}
