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
   cout.tie(NULL);                                                              
   /* cerr.tie(NULL); */
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

void solution() {
   int n;
   cin >> n;
   int arr[n];
   for (int i = 0; i < n; i++) {
      cin >> arr[i];
   }
   multiset<int> ma;
   for (int i = 0; i < n; i++) {
      if(ma.upper_bound(arr[i]) == ma.end()){
         ma.insert(arr[i]);
      }
      else{
         ma.erase(ma.upper_bound(arr[i]));
         ma.insert(arr[i]);
      }
   }
   std::cout << ma.size() << endl;
}

int32_t main() {
   fast;
   int test_cases = 1;
   /* cin >> test_cases; */
   while (test_cases--) {
         solution();
   }
   cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
}
