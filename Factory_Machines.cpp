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
#include <pthread.h>
#include <valarray>
#include <vector>
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

void solution() {
   int n,m;
   cin >> n >> m;
   int arr[n];
   for (int i = 0; i < n; i++) {
      cin >> arr[i];
   }
   int l = 0,r=1e18,sum = 0;
   int ans = 0;
   while(l <= r){
      int mid = (l+r)/2;
      for (int i = 0; i < n; i++) {
         sum += mid/arr[i];
         if(sum >= m){ // dont now why this is needed
            break;
         }
      }
      if(sum < m){
         l = mid+1;
      }
      else{
         r = mid-1;
         ans = mid;
      }
      sum = 0;
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
   cerr << "=====" << endl;
   cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
   return 0;
}
