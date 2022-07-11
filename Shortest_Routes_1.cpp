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
#include <map>
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
#undef int
#define int long long int
#define endl '\n'
#define pi 3.1415926535
int **memorized_dp_array;
int no_of_vertix = 0;
int **adj_matrix;
int MOD = 1e9 + 7;
map<int, vector<int>> tree;
int *vis;
char **grid;

void solution() {
   int n;
   unsigned long long m;
   cin >> n >> m;
   int arr[n];
   for (int i = 0; i < n; i++) {
      cin >> arr[i];
   }
   int l= 0,r = 0;
   unsigned long long sum = 0;
   int ans = 0;
   while(l <= r){
      if(sum < m){
         if(r == n){
            break;
         }
         sum += arr[r];
         r++;
      }
      else{
         ans++;
         sum -= arr[l];
         l++;
      }
   }
   if(ans == INT_MAX){
      std::cout << -1 << endl;
   }
   else
      std::cout << ans << endl;
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
   cerr << "=====" << endl;
   cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
}
