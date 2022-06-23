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
#include <cerrno>
#include <iomanip>
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
/* #undef int */
/* #define int long long int */
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
int min_(int a,int b,int c){
   return min(min(a,b),c);
}

int lcs(string a,string b,int a_, int b_){
   int dp[a_+1][b_+1];
   for (int i = 0; i < a_+1; i++) {
      for (int j = 0; j < b_+1; j++) {
         if(i == 0){
            dp[i][j] = j;
         }
         if(j == 0){
            dp[i][j] = i;
         }
      }
   }
   for (int i = 1; i <= a_; i++) {
      for (int j = 1; j <= b_; j++) {
         if(a[i-1] == b[j-1]){
            dp[i][j] = dp[i-1][j-1];
         }
         else{
            dp[i][j] = 1 + min_(dp[i][j-1],dp[i-1][j],dp[i-1][j-1]);
         }
      }
   }
   return dp[a_][b_];
}


void solution() {
   string a,s;
   cin >> a >> s;
   memorized_dp_array = new int*[max(a.length(),s.length())+1];
   for (int i = 0; i <= max( s.length(),a.length() ); i++) {
      memorized_dp_array[i] = new int[max(a.length(),s.length())+1];
   }
   for (int i = 0; i <= max(a.length(),s.length()); i++) {
      for (int j = 0; j <= max(a.length(),s.length()); j++) {
         memorized_dp_array[i][j] = -1;
      }
   }
   std::cout << lcs(a, s, a.length(), s.length()) << endl;
}

int32_t main() {
   fast;
   int test_cases = 1;
   /* cin >> test_cases; */
   while (test_cases--) {
      solution();
   }
}
