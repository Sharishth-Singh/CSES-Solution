/* ================================================= Copyright © 2022 Sharishth Singh. All Rights Reserved ================================= */

#include "bits/stdc++.h"
#include <algorithm>
#include <codecvt>
#include <iostream>
#include <map>
#include <queue>
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
   }cerr << "=====" << endl;cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";return 0;
}

/* ================================================================= Global Varible =========================================================== */

int **memorized_dp_array;
int no_of_vertix = 0;
int **adj_matrix;
unordered_map<int,vector<pair<int,int>>> graph;
int **vis;
char **grid;

/* ================================================================== Solution Start ============================================================== */

bool comp (const pair<int,pair<int,int>> &a,const pair<int,pair<int,int>> &b){
   if(a.first == b.first){
      return a.second.first > b.second.first;
   }
   else{
      return a.first < b.first;
   }
}

bool comp2(const pair<int,int> &a, const pair<int,int> &b){
   return a.second < b.second;
}

void solution(){
   int n;
   cin >> n;
   vector<pair<int, pair<int,int>>> arr;
   for (int i = 0; i < n; i++) {
      int q,w;
      cin >> q >> w;
      arr.push_back({q,{w,i}});
   }
   sort(arr.begin(),arr.end(),comp);
   vector<pair<int,int>> ans;
   vector<pair<int,int>> ans1;
   ordered_set se,sr;
   for (auto i : arr) {
      se.insert({i.second.first,i.second.second});
      sr.insert({i.second.first,i.second.second});
   }
   for (auto i : arr) {
      se.erase(se.find({i.second.first,i.second.second}));
      ans.push_back({se.order_of_key({i.second.first+1,-1}),i.second.second});
   }
   reverse(arr.begin(), arr.end());
   for (auto i : arr) {
      sr.erase(sr.find({i.second.first,i.second.second}));
      ans1.push_back({sr.size() - sr.order_of_key({i.second.first,-1}),i.second.second});
   }
   sort(ans.begin(),ans.end(),comp2);
   sort(ans1.begin(),ans1.end(),comp2);
   for (auto i : ans) {
      if(i.first != 0){
         i.first = 1;
      }
      std::cout << i.first << " ";
   }
   std::cout << endl;
   for (auto i : ans1) {
      if(i.first != 0){
         i.first = 1;
      }
      std::cout << i.first << " ";
   }
}

