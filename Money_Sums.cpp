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
#include <cstring>
#include <iomanip>
#include <iostream>
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
#undef int
#define int long long int
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


int *arr;
map<int,int> ma;
void fun(int n,int v){
   if(memorized_dp_array[n][v] != -1){
      ma[v] = v;
      return;
   }
   if(n == 0){
      if(v != 0)
         memorized_dp_array[n][v] = ma[v] = v;
      return;
   }
   fun(n-1,v+arr[n-1]);
   memorized_dp_array[n][v] = ma[v] = v;
   fun(n-1,v);
   memorized_dp_array[n][v] = ma[v] = v;
   return;
}


void solution() {
   int n;
   cin >> n;
   arr = new int[n];
   int sum = 0;
   memorized_dp_array = new int*[n+1];
   for (int i = 0; i < n; i++) {
      cin >> arr[i];
      sum += arr[i];
   }
   for (int i = 0; i <= n; i++) {
      memorized_dp_array[i] = new int[sum+1];
      for (int j = 0; j <= sum; j++) {
         memorized_dp_array[i][j] = -1;
      }
   }
   fun(n,0);
   std::cout << ma.size()-1 << endl;
   for (auto i : ma) {
      if(i.second != 0)
         std::cout << i.second << " ";
   }
}

int32_t main() {
   fast;
   int test_cases = 1;
   /* cin >> test_cases; */
   while (test_cases--) {
      solution();
   }
}
