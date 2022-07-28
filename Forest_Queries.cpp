/*
 ______________________________________
/           Title: cp template         \
|        Author: Sharishth Singh       |
\           Date: 22 May 2022          /
 --------------------------------------
        \   ^__^
         \  (xx)\_______
            (__)\       )\/\
             U  ||----w |
                ||     ||
*/

#include "bits/stdc++.h"
#include <algorithm>
#include <cerrno>
#include <cstdlib>
#include <map>
#include <set>
#include <unordered_map>
#include <utility>
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

void solution() {
   int n,q;
   cin >> n >> q;
   int ar[n][n];
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
         char q;
         cin >> q;
         if(q == '*'){
            ar[i][j] = 1;
         }
         else{
            ar[i][j] = 0;
         }
      }
   }
   int **ans;
   ans = new int*[n+1];
   for (int i = 0; i <= n; i++) {
      ans[i] = new int[n+1];
   }
   for (int i = 1; i <= n; i++) {
      for (int j = 2; j <= n; j++) {
         ans[j][i] = ans[j][i] + ans[j-1][i];
      }
   }
   for (int i = 1; i <= n; i++) {
      ans[i][1] = ar[i-1][0];
   }
   for (int i = 1; i <= n; i++) {
      for (int j = 2; j <= n; j++) {
         ans[i][j] = ar[i-1][j-1] + ans[i][j-1];
      }
   }
   for (int i = 1; i <= n; i++) {
      for (int j = 2; j <= n; j++) {
         ans[j][i] = ans[j][i] + ans[j-1][i];
      }
   }
   /* int a,b; */
   /* cin >> a >> b; */
   /* std::cout << ans[a][b] << endl; */
   for (int i = 0; i < q; i++) {
      int st[2],fi[2];
      cin >> st[0] >> st[1] >> fi[0] >> fi[1];
      /* st[0]--; */
      /* st[1]--; */
      /* fi[0]--; */
      /* fi[1]--; */
      /* std::cerr << ans[fi[0]][fi[1]] << endl; */
      /* std::cerr << ans[st[0]-1][fi[1]] << endl; */
      /* std::cerr << ans[fi[0]-1][st[1]] << endl; */
      /* std::cerr << ans[st[0]][st[1]] << endl; */
      /* if(st[0] == fi[0] && st[1] == fi[1]){ */
      /*    std::cout << ans[fi[0]][fi[1]] << endl; */
      /* } */
      /* else */
      /* { */
         std::cout << ans[fi[0]][fi[1]] - ans[st[0]-1][fi[1]] - ans[fi[0]][st[1]-1] + ans[st[0]-1][st[1]-1]<< endl;
      /* } */
   }
   /* for (int i = 0; i <= n; i++) { */
   /*    for (int j = 0; j <= n; j++) { */
   /*       std::cerr << ans[i][j] << " "; */
   /*    } */
   /*    std::cerr << endl; */
   /* } */
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
