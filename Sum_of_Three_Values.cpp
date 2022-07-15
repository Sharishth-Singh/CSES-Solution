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
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;
using namespace chrono;
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
   cin.tie(0);                                                                  \
   cout.tie(0);                                                                 \
   cerr.tie(0);
#undef int
#define int long long int
#define endl '\n'
#define pi 3.1415926535
#define mod 1000000007
#define INF 1100000000000000000
int **memorized_dp_array;
int no_of_vertix = 0;
int **adj_matrix;
unordered_map<int, vector<int>> tree;
int *vis;
char **grid;

struct custom_hash {
   static uint64_t splitmix64(uint64_t x) {
      // http://xorshift.di.unimi.it/splitmix64.c
      x += 0x9e3779b97f4a7c15;
      x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
      x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
      return x ^ (x >> 31);
   }

   size_t operator()(uint64_t x) const {
      static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
      return splitmix64(x + FIXED_RANDOM);
   }
};

void solution() {
   int n,k;
   cin >> n >> k;
   int arr[n];
   unordered_map<int, int,custom_hash> ma;
   unordered_map<int, vector<int>,custom_hash> ans;
   vector<int> h;
   for (int i = 0; i < n; i++) {
      cin >> arr[i];
      ma[arr[i]]++;
      if(ans[arr[i]].size() < 3){
         ans[arr[i]].push_back(i+1);
      }
   }
   if(k == 1e9){
      std::cout << "IMPOSSIBLE" << endl;
      return;
   }
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
         if(i != j){
            if(( ma[k-arr[i]-arr[j]] > 0 ) & (k-arr[i]-arr[j] == arr[i] ? ma[arr[i]] > 1 ? 1:0:1) & (k-arr[i]-arr[j] == arr[j] ? ma[arr[i]] > 1 ? 1:0:1) & (k-arr[i]-arr[j] == arr[i] && k-arr[i]-arr[j] == arr[i] ? ma[arr[i]] > 2 ? 1:0:1)){
               std::cout << i+1 << " " << j+1 << " ";
               for (auto x : ans[k-arr[i]-arr[j]]) {// ans[k-arr[i]-arr[j]] is of size 3
                  if(x != i+1 && x != j+1){
                     std::cout << x << endl;
                     return;
                  }
               }
            }
         }
      }
   }
   std::cout << "IMPOSSIBLE" << endl;
}

int32_t main() {
   auto starttime = high_resolution_clock::now();
   fast;
   int test_cases = 1;
   /* cin >> test_cases; */
   /* int a = 1; */
   while (test_cases--) {
      /* std::cout << "Case #"<< a << ": "; */
      solution();
      /* a++; */
   }
   auto endtime = high_resolution_clock::now();
   double duration = duration_cast<microseconds>(endtime - starttime).count();
   duration /= 1000000;
   cerr << "Time Taken : " << fixed << setprecision(6) << duration << " secs" << '\n';
   return 0;
}
