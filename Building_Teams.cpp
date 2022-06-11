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
#include <regex>
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
vector<int>team;


string ans;
bool ch = false;
void dfs(int start,int a){
   for (auto i : tree[start]) {
      if(vis[i] == 0){
         vis[i] = 1;
         team[i] = a;
         if(a == 1)a = 2;
         else a = 1;
         dfs(i,a);
         if(a == 1)a = 2;
         else a = 1;
      }
      if(team[start] == team[i]){
         ch = true;
         ans = "IMPOSSIBLE";
         return;
      }
   }
}


void solution() {
   int n,m;
   cin >> n>> m;
   vis = new int[n];
   team.resize(n);
   for (int i = 0; i < n; i++) {
      vis[i] = 0;
      team[i] = 0;
   }
   for (int i = 0; i < m; i++) {
      int q,w;
      cin >> q >> w;
      tree[q-1].push_back(w-1);
      tree[w-1].push_back(q-1);
   }
   for (int i = 0; i < n; i++) {
      if(vis[i] == 0)
      {
         vis[i] = 1;
         team[i] = 1;
         dfs(i,2);
      }
   }
   if(ch){
      cout << ans << endl;
      return;
   }
   for (int i = 0; i < n; i++) {
      cout<<team[i] << " ";
   }
   std::cout << endl;
   parr(team);
}

int32_t main() {
   fast;
   int test_cases = 1;
   /* cin >> test_cases; */
   while (test_cases--) {
      solution();
   }
}

