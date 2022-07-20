/*
 ______________________________________
/           Title: cp template         \
|        Author: Sharishth Singh       |
\           Date: 22 May 2022          /
 --------------------------------------
        \   ^__^
         \  (xx)\_______
            (__)\       )\/\
             U  ||----w |
                ||     ||
*/

#include "bits/stdc++.h"
#include <algorithm>
#include <climits>
#include <map>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;
using namespace chrono;
#define parr(x)                                                                 \
   cerr << #x << ' ' << '[' << ' ';                                             \
   for (auto z : x)                                                             \
      cerr << z << ' ';                                                         \
   cerr << ']' << endl;
#define pmap(x)                                                                 \
   cerr << #x << ' ' << '{' << ' ';                                             \
   for (auto z : x)                                                             \
      cerr << '(' << ' ' << z.first << ' ' << z.second << ' ' << ')' << ' ';    \
   cerr << '}' << endl;
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
   int n,x;
   cin >> n >>x;
   int arr[n];
   for (int i = 0; i < n; i++) {
      cin >> arr[i];
   }
   int sum = 0;
   int l = 0,r = 0;
   int ans = 0;
   while(l <= r){
      if(sum <= x && r < n){
         sum += arr[r];
         r++;
      }
      else{
         sum -= arr[l];
         l++;
      }
      if(sum == x){
         ans++;
      }
   }
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
   cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
   return 0;
}
