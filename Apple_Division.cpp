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

int isSum(vector<int> arr,int total,int n){
   int ans = INT_MAX;
   for(int i = 0; i < 1<<n; i++) {
      int s = 0;
      for(int j = 0; j < n; j++) {
         if(i & 1<<j) {
            /* std::cerr << ( i & 1<<j ) << endl; */
            /* std::cerr << s << endl; */
            s += arr[j];
         }
      }
      int curr = abs((total-s)-s);
      ans = min(ans, curr);
   }
   return ans;
}

void solution() {
   int n;
   cin >> n;
   vector<int> arr;
   int range = 0;
   for (int i = 0; i < n; i++) {
      int q;
      cin >> q;
      range += q;
      arr.push_back(q);
   }
   std::cout << isSum(arr, range, n) << endl;
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
