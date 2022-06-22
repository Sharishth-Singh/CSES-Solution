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

int fun(int x, int y,int n){
   if(grid[x][y] == '*'){
      return memorized_dp_array[x][y] = 0;
   }
   if(memorized_dp_array[x][y] != -1){
      return memorized_dp_array[x][y];
   }
   else
   {
      if(x == n-1 && y == n-1){
         return memorized_dp_array[x][y] = 1;
      }
      if(x < n-1 && y < n-1){
         return memorized_dp_array[x][y] = ( fun(x+1,y,n) + fun(x,y+1,n) )%MOD;
      }
      else{
         if(y == n-1){
            return memorized_dp_array[x][y] = fun(x+1,y,n)%MOD;
         }
         if(x == n-1){
            return memorized_dp_array[x][y] = fun(x,y+1,n)%MOD;
         }
      }
   }
}


void solution() {
   int n;
   cin >> n;
   memorized_dp_array = new int*[n];
   grid = new char*[n];
   for (int i = 0; i < n; i++) {
      memorized_dp_array[i] = new int[n];
      grid[i] = new char[n];
      for (int j = 0; j < n; j++) {
         memorized_dp_array[i][j] = -1;
      }
   }
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
         cin >> grid[i][j];
      }
   }
   std::cout << fun(0,0,n) << endl;
}

int32_t main() {
   fast;
   int test_cases = 1;
   /* cin >> test_cases; */
   while (test_cases--) {
      solution();
   }
}
