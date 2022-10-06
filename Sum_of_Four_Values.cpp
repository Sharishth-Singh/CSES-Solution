/* ================================================= Copyright © 2022 Sharishth Singh. All Rights Reserved ================================= */

#include "bits/stdc++.h"
#include <algorithm>
#include <iostream>
#include <iterator>
#include <map>
#include <unordered_map>
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
#define parr(x)cerr << "\033[40m" << typeid(x).name() << " :" << "\033[0m"<< "\033[36m "<< #x << ' ' << '[' << ' ';for (auto z : x)cerr << z << ' ';cerr << ']' << endl
#define pmap(x)cerr << "\033[40m" << typeid(x).name() << "\033[0m"<< "\033[36m " << #x << ' ' << '{' << ' ';for (auto z : x)cerr << '(' << ' ' << z.first << ' ' << z.second << ' ' << ')' << ' ';cerr << '}' << endl
#define debug(x)cerr << "\033[40m" << typeid(x).name() << " :" << "\033[0m"<< "\033[36m "<< #x << " " <<  x << endl;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);cerr.tie(0);
template <typename T> std::string type_name();
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

/* ================================================================= Global Varible =========================================================== */

int **memorized_dp_array;
int no_of_vertix = 0;
int **adj_matrix;
unordered_map<int,vector<pair<int,int>>> graph;
int *vis;
char **grid;

/* ================================================================== Solution Start ============================================================== */

void solution(){
   int n,tar;
   cin >> n >> tar;
   vector<int>arr(n);
   unordered_map<int, vector<int>>ma;
   for (int i = 0; i < n; i++) {
      cin >> arr[i];
      ma[arr[i]].push_back(i+1);
   }
   sort(arr.begin(),arr.end());
   for (int i = 0; i < n; i++) {
      for (int j = i+1; j < n; j++) {
         int l = 0,r =n-1;
         while(l < r){
            if(arr[l] + arr[r] == ( tar -arr[i]-arr[j]) && l != i && l != j && r != i && r != j){
               std::cout << ma[arr[i]].back() << " ";
               ma[arr[i]].pop_back();
               std::cout << ma[arr[j]].back() << " ";
               ma[arr[j]].pop_back();
               std::cout << ma[arr[l]].back() << " ";
               ma[arr[l]].pop_back();
               std::cout << ma[arr[r]].back() << " ";
               ma[arr[r]].pop_back();
               std::cout << endl;
               return;
            }
            else{
               if(arr[l] + arr[r] <= ( tar -arr[i]-arr[j])){
                  l++;
               }
               else{
                  r--;
               }
            }
         }
      }
   }
   std::cout << "IMPOSSIBLE" << endl;
}




