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
#define bug(x)                                                                  \
   cerr << #x << " : ";                                                         \
   cerr << x << endl
#define ff first
#define ss second
#undef int
#define int long long int
#define endl '\n'
#define pi 3.1415926535
#define ve vector
int static **memorized_dp_array;
int no_of_vertix = 0;
int **adj_matrix;
int MOD = 1e9 + 7;
std::map<int, vector<int>> tree;
int *vis;
char **grid;

int fun(int n,int k)
{
   if(n==1) return 1;
   if(k<=(n+1)/2)
   {
      if(2*k>n) return (2*k)%n;
      else return 2*k;
   }
   int temp=fun(n/2,k-(n+1)/2);
   if(n%2==1) return 2*temp+1;
   return 2*temp-1;
}


void solution() {
   int n,m;
   cin >> n >> m;
   std::cout << fun(n, m) << endl;
}

int32_t main() {
   fast;
   int test_cases = 1;
   cin >> test_cases;
   while (test_cases--) {
      solution();
   }
}

