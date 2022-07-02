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
#include <climits>
#include <codecvt>
#include <cstring>
#include <iostream>
#include <iterator>
#include <map>
#include <shared_mutex>
#include <system_error>
#include <type_traits>
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
int **memorized_dp_array;
int no_of_vertix = 0;
int **adj_matrix;
int MOD = 1e9 + 7;
std::map<int, vector<int>> tree;
int *vis;
char **grid;

void solution() {
   string s;
   cin >> s;
   map<char, int> ma;
   for (int i = 0; i < s.length(); i++) {
      ma[s[i]]++;
   }
   bool ch = false;
   for (auto i : ma) {
      if(i.second%2 == 1 ){
         if(ch == true){
            std::cout << "NO SOLUTION" << endl;
            return;
         }
         ch = true;
      }
   }
   string ans;
   for (auto i : ma) {
      if(i.second%2 == 0)
      {
         for (int j = 0; j < i.second/2; j++) {
            ans += i.first;
         }
      }
   }
   string g = ans;
   reverse(g.begin(), g.end());
   for (auto i : ma) {
      if(i.second%2 == 1){
         for (int j = 0; j < i.second; j++) {
            ans += i.first;
         }
      }
   }
   std::cout << ans+g << endl;
}

int32_t main() {
   fast;
   int test_cases = 1;
   /* cin >> test_cases; */
   /* int a = 1; */
   while (test_cases--) {
      /* std::cout << "Case #"<< a << ": "; */
      solution();
      /* a++; */
   }
}

