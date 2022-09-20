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

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;
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
/* unordered_map<int, vector<int>> tree; */
int *vis;
char **grid;

typedef tree <
	pair<int, int>,
	null_type,
	less<pair<int, int>>,
	rb_tree_tag,
	tree_order_statistics_node_update> ordered_set;

void solution(){
   int n,k;
   cin >> n >> k;
   ordered_set ma;
   int t = 0;
   int arr[n];
   for (int i = 0; i < n; i++) {
      cin >> arr[i];
   }
   for (int i = 0; i < k; i++) {
      ma.insert({arr[i],i});
   }
   std::cout << ma.find_by_order(( k-1 )/2)->first << " ";
   for (int i = k; i < n; i++) {
      ma.insert({arr[i],i});
      ma.erase(ma.lower_bound({arr[i-k],0}));
      std::cout << ma.find_by_order(( k-1 )/2)->first << " ";
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

