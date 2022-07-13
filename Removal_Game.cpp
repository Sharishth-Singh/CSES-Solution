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
#include <cctype>
#include <climits>
#include <map>
#include <memory>
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

int m;
int fun(int arr[],int l,int r){
   if(memorized_dp_array[l][r] != -INT_MAX){
      return memorized_dp_array[l][r];
   }
   if(l == r){
      return memorized_dp_array[l][r] = arr[l];
   }
   if(l+1 == r){
      return memorized_dp_array[l][r] = max(arr[l],arr[r]);
   }
   return memorized_dp_array[l][r] = max(arr[l]+ min(fun(arr,l+2,r), fun(arr, l+1, r-1)),arr[r]+min(fun(arr, l, r-2),fun(arr, l+1, r-1)));
   /* return memorized_dp_array[l][r] = max(arr[l]+ min(memorized_dp_array[l][r] = fun(arr,l+2,r),memorized_dp_array[l][r] = fun(arr, l+1, r-1)),arr[r]+min(memorized_dp_array[l][r] = fun(arr, l, r-2),memorized_dp_array[l][r] = fun(arr, l+1, r-1))); */
}

void solution() {
   cin >> m;
   int arr[m];
   memorized_dp_array = new int*[m];
   for (int i = 0; i < m; i++) {
      memorized_dp_array[i] = new int[m];
   }
   for (int i = 0; i < m; i++) {
      for (int j = 0; j < m; j++) {
         memorized_dp_array[i][j] = -INT_MAX;
      }
   }
   for (int i = 0; i < m; i++) {
      cin >> arr[i];
   }
   std::cout << fun(arr,0,m-1) << endl;;
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
