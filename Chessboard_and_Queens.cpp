/* ================================================= Copyright © 2022 Sharishth Singh. All Rights Reserved ================================= */

#include "bits/stdc++.h"
#include <algorithm>
#include <codecvt>
#include <map>
#include <system_error>
#include <utility>
#include <vector>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
#define parr(x)cerr << #x << ' ' << '[' << ' ';for (auto z : x)cerr << z << ' ';cerr << ']' << endl
#define pmap(x)cerr << "\033[40m" << typeid(x).name() << "\033[0m"<< "\033[36m " << #x << ' ' << '{' << ' ';for (auto z : x)cerr << '(' << ' ' << z.first << ' ' << z.second << ' ' << ')' << ' ';cerr << '}' << endl
#define debug(x)cerr << "\033[40m" << typeid(x).name() << " :" << "\033[0m"<< "\033[36m "<< #x << " " <<  x << endl;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);cerr.tie(0);
void solution();

/* =================================================================== Driving Code ========================================================== */

int32_t main(){fast;int test_cases = 1;
   /* cin >> test_cases; */
   /* int a = 1; */
   while (test_cases--) {
      /* std::cout << "Case #"<< a << ": "; */
      solution();
      /* a++; */
   }cerr << "=====" << endl;cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";return 0;}

/* ================================================================= Code Start =========================================================== */

int **memorized_dp_array;
int no_of_vertix = 0;
int **adj_matrix;
unordered_map<int,vector<pair<int,int>>> graph;
int **vis;
char **grid;

/* ================================================================== Solution Start ============================================================== */

char chess[8][8];
int ld[15],rd[15],row[8];
int ans = 0;

void fun(int j){
   if(j == 8){
      ans++;
      return;
   }
   for (int i = 0; i <= 7; i++) {
      if(chess[i][j] == '.' && ld[i-j+7] == 0 && rd[i+j] == 0 && row[i] == 0){
         ld[i-j+7] = 1 , rd[i+j] = 1 , row[i] = 1;
         fun(j+1);
         ld[i-j+7] = 0 , rd[i+j] = 0 , row[i] = 0;
      }
   }
}


void solution(){
   for (int i = 0; i <= 7; i++) {
      for (int j = 0; j <= 7; j++) {
         cin >> chess[i][j];
      }
   }
   fun(0);
   std::cout << ans << endl;
}

