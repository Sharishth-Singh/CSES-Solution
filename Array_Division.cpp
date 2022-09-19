/*
 ______________________________________
/           Title: cp template         \
|        Author: Sharishth Singh       |
\           Date: 22 May 2022          /
 --------------------------------------
        \   ^__^
         \  (xx)\_______
            (__)\       )\/\
             U  ||----w||
                ||     ||
*/

#include "bits/stdc++.h"
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;
using namespace chrono;
#undef int
#define int long long int
#define endl '\n'
#define pi 3.1415926535
#define MOD 1000000007
#define INF 1100000000000000000
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
int **memorized_dp_array;
int no_of_vertix = 0;
int **adj_matrix;
unordered_map<int, vector<int>> tree;
int *vis;
char **grid;

bool fun(vector<int>arr,int mid,int k){
   int sum = 0;
   int groups = 0;
   for (auto i : arr) {
      if(i > mid){
         return false;
      }
      if(sum + i > mid){
         groups++;
         sum = 0;
      }
      sum += i;
   }
   groups++;
   return groups <= k;
}


void solution(){
   int n,k;
   cin >> n >> k;
   vector<int>arr(n);
   int l = 0,h = 0;
   for (int i = 0; i < n; i++) {
      cin >> arr[i];
      h += arr[i];
   }
   int ans = 0;
   while(l <= h){
      int mid = (l+h)/2;
      if(fun(arr,mid,k)){
         h = mid-1;
         ans = mid;
      }
      else{
         l = mid+1;
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
   cerr << "=====" << endl;
   cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
   return 0;
}

