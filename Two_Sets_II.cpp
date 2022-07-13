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
/* #undef int */
/* #define int unsigned long long int */
#define endl '\n'
#define pi 3.1415926535
int **memorized_dp_array;
int no_of_vertix = 0;
int **adj_matrix;
int MOD = 1e9 + 7;
map<int, vector<int>> tree;
int *vis;
char **grid;

int fun(vector<int> arr,int sum, int n){
   int dp[n+1][sum+1];
   for (int i = 0; i < n+1; i++) {
      for (int j = 0; j < sum+1; j++) {
         if(j == 0) dp[i][j] = 1;
         if(i == 0) dp[i][j] = 0;
      }
   }
   dp[0][0] = 1;
   for (int i = 1; i < n+1; i++) {
      for (int j = 1; j < sum+1; j++) {
         if(arr[i] > j){
            dp[i][j] = dp[i-1][j]%MOD;
         }
         else{
            dp[i][j] = dp[i-1][j-arr[i]]%MOD + dp[i-1][j]%MOD;
         }
      }
   }
   return dp[n][sum];
}

int isSum(vector<int> p,int sum,int n){
   if(memorized_dp_array[n][sum] != -1){
      return memorized_dp_array[n][sum];
   }
   if(sum == 0){
      return memorized_dp_array[n][sum] = 1;
   }
   if(n == 0){
      return memorized_dp_array[n][sum] = 0;
   }
   if(p[n-1] > sum){
      memorized_dp_array[n][sum] = isSum(p, sum, n-1)%MOD;
      return memorized_dp_array[n][sum]%MOD;
   }
   else{
      memorized_dp_array[n][sum] = isSum(p, sum-p[n-1], n-1)%MOD;
      memorized_dp_array[n][sum] = memorized_dp_array[n][sum] + isSum(p, sum, n-1)%MOD;
      return memorized_dp_array[n][sum];
   }
}

void solution() {
   int n;
   cin >> n;
   vector<int> arr;
   int sum = 0;
   for (int i = 0; i < n; i++) {
      arr.push_back(i+1);
      sum += i+1;
   }
   memorized_dp_array = new int*[n+1];
   for (int i = 0; i < n+1; i++) {
      memorized_dp_array[i] = new int[sum+1];
   }
   for (int i = 0; i < n+1; i++) {
      for (int j = 0; j < sum+1; j++) {
         memorized_dp_array[i][j] = -1;
      }
   }
   if(sum%2 == 1){
      std::cout << 0 << endl;
   }
   else
   {
      std::cout << fun(arr, sum/2, n)/2 << endl;
      /* std::cout << ( isSum(arr, sum/2, n) )/2 << endl; */
   }
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
