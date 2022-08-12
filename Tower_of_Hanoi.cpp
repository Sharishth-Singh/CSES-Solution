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
vector<pair<int, int>>ma;
void towerOfHanoi(int n, int from_rod, int to_rod, int aux_rod) {
   if (n == 0)
   {
      return;
   }
   towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
   ma.push_back(make_pair(from_rod, to_rod));
   towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}
void solution() {
   int n;
   cin >> n;
   towerOfHanoi(n, 1, 3, 2);
   std::cout << ma.size() << endl;
   for (auto i : ma) {
      std::cout << i.first << " " << i.second<< endl;
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
