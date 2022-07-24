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
#include <cerrno>
#include <map>
#include <set>
#include <utility>
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
   int n,m;
   cin >> n >> m;
   unordered_map<int , int> count;
   set<int> ma;
   count[n]++;
   ma.insert(n);
   int ans = n;
   set<int> li;
   set<int>::iterator it;
   li.insert(0);
   li.insert(n);
   unordered_map<int, int> as;
   as[0] = n;
   for (int i = 0; i < m; i++) {
      int q;
      cin >> q;
      ma.erase(as[*--li.lower_bound(q)]);
      count[as[*--li.lower_bound(q)]]--;
      ma.insert(q - *--li.lower_bound(q));
      count[q-*--li.lower_bound(q)]++;
      as[*--li.lower_bound(q)] = q - *--li.lower_bound(q);
      ma.insert(*li.lower_bound(q) - q);
      count[*li.lower_bound(q) - q]++;
      as[q] = *li.lower_bound(q) - q;
      li.insert(q);
      if(count[ans] == 0){
         ans = *--ma.end();
      }
      else{
         ma.insert(ans);
         ans = max(ans,*--ma.end());
      }
      std::cout << ans << " ";
   }
   std::cout << endl;
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
