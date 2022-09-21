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
#include <climits>
#include <cmath>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <utility>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;
typedef tree <pair<int, int>,null_type,less<pair<int, int>>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
#undef int
#define int long long int
#define endl '\n'
#define INF 1000000000000
#define pi 3.1415926535
#define MOD 1000000007
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
unordered_map<int,vector<pair<int,int>>> graph;
int *vis;
char **grid;

vector<vector<int>> floyd (int n,int m){
   vector<vector<int>> distance(n+1,vector<int>(n+1,INF));
   for (auto x:graph) {
      int k,e,w;
      k = x.first;
      for (auto i : x.second) {
         e = i.first;
         w = i.second;
         distance[k][k] = 0,distance[e][e] = 0;
         distance[e][k] = min(distance[k][e],w),distance[k][e] = min(distance[k][e],w);
      }
   }
   for (int k = 1; k <= n; k++) {
      for (int i = 1; i <= n; i++) {
         for (int j = 1; j <= n; j++) {
            distance[i][j] = min(distance[i][j],distance[i][k]+distance[k][j]);
         }
      }
   }
   return distance;
}

void solution(){
   int n,m,q;
   cin >> n >> m >> q;
   for (int i = 0; i < m; i++) {
      int k,e,w;
      cin >> k >> e >> w;
      graph[k].push_back({e,w});
      graph[e].push_back({k,w});
   }
   vector<vector<int>>distance = floyd(n, m);
   for (int i = 0; i < q; i++) {
      int w,e;
      cin >> w >> e;
      std::cout << ( distance[w][e] == INF ? -1 : distance[w][e] ) << endl;
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
   return 0;
}

