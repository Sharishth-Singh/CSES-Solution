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
#define int unsigned long long int
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

vector<pair<int,int>>block;
int32_t main(){fast;int test_cases = 1;
   /* cin >> test_cases; */
   /* int a = 1; */
   block.push_back({1,9});
   int t = 9;
   int y = 2;
   while(t<= 1e18){
      block.push_back({ block.back().second+1,y*t*10+block.back().second });
      y++;
      t *= 10;
   }
   while (test_cases--) {
      /* std::cout << "Case #"<< a << ": "; */
      solution();
      /* a++; */
   }cerr << "=====" << endl;cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";return 0;}

/* ================================================================= Global Varible =========================================================== */

int **memorized_dp_array;
int no_of_vertix = 0;
int **adj_matrix;
unordered_map<int,vector<pair<int,int>>> graph;
int **vis;
char **grid;

/* ================================================================== Solution Start ============================================================== */


int power(int a, int n, int m) {
   int res = 1;

   while (n) {
      if (n % 2) {
         res = (res * a) % m, n--;
      } else {
         a = (a * a) % m, n /= 2;
      }
   }
   return res;
} // O(log(n))

int Binary_Search_left(int ele,int n,int l,int r,int sta,int ind) // left most closest element
{
   while (r > l + 1) {
      int mid = (l + r) / 2;
      if (( (mid-power(10,ind-1,1e18))*ind + sta )  <= ele) {
         l = mid;
      } else {
         r = mid;
      }
   }
   return l;
}




void solution(){
   int n;
   cin >> n;
   while(n--){
      int q;
      cin >> q;
      int sta = 0;
      int ind = 1;
      int fis = 0;
      for (auto i : block) {
         if(i.second >= q){
            sta = i.first;
            fis = i.second;
            break;
         }
         ind++;
      }
      std::cerr << ind << " " << sta << " " << fis << endl;
      int i = Binary_Search_left(q, 0, sta, fis, sta, ind);
      int t = (i-power(10,ind-1,1e18))*ind + sta;
      std::cerr << i << " " << t << endl;
      std::cout << to_string(i)[q-t] << endl;
   }
}

